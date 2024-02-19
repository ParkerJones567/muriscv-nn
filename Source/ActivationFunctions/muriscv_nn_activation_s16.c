/*
 * SPDX-FileCopyrightText: Copyright 2010-2020, 2022 Arm Limited and/or its affiliates <open-source-office@arm.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Modifications copyright (C) 2023 Chair of Electronic Design Automation, TUM
 */

/* ----------------------------------------------------------------------
 * Project:      MURISCV NN Library
 * Title:        muriscv_nn_activations_q15.c
 * Description:  Q15 neural network activation function using direct table look-up
 *
 * $Date:        19 February 2024
 * $Revision:    V.1.0.0
 *
 * Target Processor:  RISCV cores
 *
 * -------------------------------------------------------------------- */

#include "muriscv_nn_tables.h"
#include "muriscv_nn_functions.h"

/**
 *  @ingroup groupNN
 */

/**
 * @addtogroup Acti
 * @{
 */

/*
 * @brief Neural network activation function using direct table look-up
 *
 * @note  Refer header file for details.
 *
 */

muriscv_nn_status muriscv_nn_activation_s16(const int16_t *input,
                           int16_t *output,
                           const int32_t size,
                           const int32_t left_shift,
                           const muriscv_nn_activation_type type)
{
    uint32_t abs_input_shift, max_saturation;
    switch (type)
    {
    case MURISCV_SIGMOID:
        abs_input_shift = 9;
        max_saturation = 0x7FFF << 10;
        break;
    case MURISCV_TANH:
    default:
        abs_input_shift = 8;
        max_saturation = 0xFFFF << 8;
        break;
    }

    // Use the LUT for sigmoid and take into account, that
    // tanh(x) = 2*sigmoid(2*x) - 1
    int32_t input_multiplier = ((int32_t)3) << left_shift;

    for (int i = 0; i < size; ++i, input++, output++)
    {
        int32_t input_data = ((*input) * input_multiplier);

        uint32_t abs_input_data = input_data > 0 ? input_data : -input_data;

        uint32_t uh = abs_input_data >> abs_input_shift;

        uint32_t result;

        if (uh >= 255)
        {
            result = max_saturation;
        }
        else
        {
            uint32_t ua = sigmoid_table_uint16[uh];
            uint32_t ub = sigmoid_table_uint16[uh + 1];
            uint32_t ut;
            if (type == MURISCV_SIGMOID)
            {
                ut = abs_input_data & 0x1ff;
            }
            else
            {
                ut = abs_input_data & 0x0ff;
            }
            result = (ua << abs_input_shift) + ut * (ub - ua);
        }
        if (type == MURISCV_SIGMOID)
        {
            result = (input_data >= 0) ? (result + (1 << 9)) : ((1 << 25) - result + (1 << 9) - 1);
            result >>= 10;
        }
        else
        {
            result = (input_data >= 0) ? (result - (1 << 23)) + (1 << 7) : ((-result + (1 << 23)) + (1 << 7) - 1);
            result >>= 8;
        }
        *output = (int16_t)result;
    }
    
    return MURISCV_NN_SUCCESS;
}

/**
 * @} end of Acti group
 */
