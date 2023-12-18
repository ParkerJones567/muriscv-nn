#!/bin/bash
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

set -e

VERSION=${1:-"17"}

if [[ "$VERSION" == "15" ]]
then
    ./download_helper.sh llvm/ LLVM default 15.0.7 llvm15
elif [[ "$VERSION" == "16" ]]
then
    ./download_helper.sh llvm/ LLVM default 16.0.6 llvm16
elif [[ "$VERSION" == "17" ]]
then
    ./download_helper.sh llvm/ LLVM default 17.0.6 llvm17
elif [[ "$VERSION" == "dev" ]]
then
    ./download_helper.sh llvm/ LLVM default 2024.01.15 llvmdev
fi
