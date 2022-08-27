#
# Copyright (C) 2021-2022 Chair of Electronic Design Automation, TUM.
#
# SPDX-License-Identifier: Apache-2.0
#
# Licensed under the Apache License, Version 2.0 (the License); you may
# not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an AS IS BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# Simple macro that will register an integration test with CTest
macro(add_muriscv_nn_intg_test TEST_NAME)

  # Register test with CTest and provide command to execute
  if(DEFINED RISCV_ARCH)
    if(${SIMULATOR} STREQUAL "OVPsim")
      add_test(NAME ${TEST_NAME}
        COMMAND ${CMAKE_SOURCE_DIR}/Sim/OVPsim/run.sh ./${TEST_NAME}.elf ${RISCV_ARCH} ${VLEN} 1
        WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    elseif(${SIMULATOR} STREQUAL "Spike")
      add_test(NAME ${TEST_NAME}
        COMMAND ${CMAKE_SOURCE_DIR}/Sim/Spike/run.sh ./${TEST_NAME}.elf ${RISCV_ARCH} ${VLEN}
        WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    elseif(${SIMULATOR} STREQUAL "ETISS")
      add_test(NAME ${TEST_NAME}
        COMMAND ${CMAKE_SOURCE_DIR}/Sim/ETISS/run.sh ./${TEST_NAME}
        WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    else()
      message(SEND_ERROR "Could not add test for specified simulator ${SIMULATOR}!")
    endif()
  else()
    add_test(NAME ${TEST_NAME}
      COMMAND ./${TEST_NAME}.elf
      WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
  endif()

  # TODO(fabianpedd): Reintroduce test timeout
  # if(${SIMULATOR} STREQUAL "ETISS")
  #   # TODO(fabianpedd): make ETISS tests fail after 2 second for now
  #   set_tests_properties(${TEST_NAME} PROPERTIES TIMEOUT 2)
  # else()
  #   # Tests should not take longer than 15 seconds
  #   set_tests_properties(${TEST_NAME} PROPERTIES TIMEOUT 15)
  # endif()

  # Create assembly dump from binary file
  add_custom_command(TARGET ${TEST_NAME} POST_BUILD
    COMMAND ${CMAKE_OBJDUMP} -S "$<TARGET_FILE:${TEST_NAME}>" # or just -d
                              > "$<TARGET_FILE:${TEST_NAME}>.lst" VERBATIM)

  message(STATUS "Successfully added ${TEST_NAME}")

endmacro()
