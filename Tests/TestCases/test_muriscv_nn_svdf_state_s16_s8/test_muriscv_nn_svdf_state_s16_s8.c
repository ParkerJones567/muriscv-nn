/*
 * Copyright (C) 2010-2021 Arm Limited or its affiliates.
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
 * Modifications copyright (C) 2021-2022 Chair of Electronic Design Automation, TUM
 */

#include <muriscv_nn_functions.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unity.h>

#include "../../TestData/test_muriscv_nn_svdf_state_s16_s8/test_data.h"
#include "../../Utils/validate.h"

#define UNITY_OUTPUT_COLOR

#define TOLERANCE 0
#define REPEAT_NUM 1

static bool check_null_bias(const int32_t *bias, int32_t size)
{
    bool null_bias = true;
    for (int i = 0; i < size; i++)
    {
        if (bias[i] != 0)
        {
            null_bias = false;
            break;
        }
    }
    return null_bias;
}

void setUp(void)
{ /* set stuff up here */
}

void tearDown(void)
{ /* clean stuff up here */
}

void test_muriscv_nn_svdf_0_s8(void)
{
    muriscv_nn_context input_ctx;
    muriscv_nn_context output_ctx;
    muriscv_nn_svdf_params svdf_params;
    muriscv_nn_dims input_dims;
    muriscv_nn_dims weights_feature_dims;
    muriscv_nn_dims weights_time_dims;
    muriscv_nn_dims state_dims;
    muriscv_nn_dims output_dims;
    muriscv_nn_dims bias_dims;
    muriscv_nn_per_tensor_quant_params input_quant_params;
    muriscv_nn_per_tensor_quant_params output_quant_params;
    int8_t output_data[SVDF_0_DST_SIZE];
    const q7_t *weights_feature_data = svdf_0_weights_feature;
    const q15_t *weights_time_data = svdf_0_weights_time;

    input_dims.n = SVDF_0_INPUT_BATCHES;
    input_dims.h = SVDF_0_INPUT_SIZE;
    weights_feature_dims.n = SVDF_0_FEATURE_BATCHES;
    weights_time_dims.h = SVDF_0_TIME_BATCHES;

    input_quant_params.multiplier = SVDF_0_MULTIPLIER_IN;
    input_quant_params.shift = SVDF_0_SHIFT_1;
    output_quant_params.multiplier = SVDF_0_MULTIPLIER_OUT;
    output_quant_params.shift = SVDF_0_SHIFT_2;

    svdf_params.input_activation.min = SVDF_0_IN_ACTIVATION_MIN;
    svdf_params.input_activation.max = SVDF_0_IN_ACTIVATION_MAX;
    svdf_params.output_activation.min = SVDF_0_OUT_ACTIVATION_MIN;
    svdf_params.output_activation.max = SVDF_0_OUT_ACTIVATION_MAX;
    svdf_params.input_offset = SVDF_0_INPUT_OFFSET;
    svdf_params.output_offset = SVDF_0_OUTPUT_OFFSET;
    svdf_params.rank = SVDF_0_RANK;

    const int32_t output_ref_size = SVDF_0_DST_SIZE;
    const int8_t *output_ref = svdf_0_output_ref;
    const int input_round_size = SVDF_0_INPUT_BATCHES * SVDF_0_INPUT_SIZE;
    const int number_inputs = sizeof(svdf_0_input_sequence) / input_round_size;
    const int32_t number_units = SVDF_0_FEATURE_BATCHES / SVDF_0_RANK;
    const int scratch_size = SVDF_0_INPUT_BATCHES * SVDF_0_FEATURE_BATCHES * sizeof(int32_t);
    const int scratch_size_out = SVDF_0_INPUT_BATCHES * number_units * sizeof(int32_t);

    input_ctx.buf = malloc(scratch_size);
    output_ctx.buf = malloc(scratch_size_out);

    int8_t *input_data = malloc(input_round_size);
    q15_t *state_data = malloc(sizeof(svdf_0_state));

    const bool null_bias = check_null_bias(svdf_0_biases, SVDF_0_DST_SIZE / SVDF_0_INPUT_BATCHES);

    for (int i = 0; i < REPEAT_NUM; i++)
    {
        memcpy(state_data, svdf_0_state, sizeof(svdf_0_state));
        for (int j = 0; j < number_inputs; j++)
        {
            memcpy(input_data, svdf_0_input_sequence + j * input_round_size, input_round_size);
            muriscv_nn_status result = muriscv_nn_svdf_state_s16_s8(&input_ctx,
                                                                    &output_ctx,
                                                                    &svdf_params,
                                                                    &input_quant_params,
                                                                    &output_quant_params,
                                                                    &input_dims,
                                                                    input_data,
                                                                    &state_dims,
                                                                    state_data,
                                                                    &weights_feature_dims,
                                                                    weights_feature_data,
                                                                    &weights_time_dims,
                                                                    weights_time_data,
                                                                    &bias_dims,
                                                                    null_bias == true ? NULL : svdf_0_biases,
                                                                    &output_dims,
                                                                    output_data);
            TEST_ASSERT_EQUAL(MURISCV_NN_SUCCESS, result);
        }

        TEST_ASSERT_TRUE(validate(output_data, output_ref, output_ref_size, TOLERANCE));
    }
    free(state_data);
    free(input_data);
    free(input_ctx.buf);
    free(output_ctx.buf);
}

void test_muriscv_nn_svdf_1_s8(void)
{
    muriscv_nn_context input_ctx;
    muriscv_nn_context output_ctx;
    muriscv_nn_svdf_params svdf_params;
    muriscv_nn_dims input_dims;
    muriscv_nn_dims weights_feature_dims;
    muriscv_nn_dims weights_time_dims;
    muriscv_nn_dims state_dims;
    muriscv_nn_dims output_dims;
    muriscv_nn_dims bias_dims;
    muriscv_nn_per_tensor_quant_params input_quant_params;
    muriscv_nn_per_tensor_quant_params output_quant_params;
    int8_t output_data[SVDF_1_DST_SIZE];
    const q7_t *weights_feature_data = svdf_1_weights_feature;
    const q15_t *weights_time_data = svdf_1_weights_time;

    input_dims.n = SVDF_1_INPUT_BATCHES;
    input_dims.h = SVDF_1_INPUT_SIZE;
    weights_feature_dims.n = SVDF_1_FEATURE_BATCHES;
    weights_time_dims.h = SVDF_1_TIME_BATCHES;

    input_quant_params.multiplier = SVDF_1_MULTIPLIER_IN;
    input_quant_params.shift = SVDF_1_SHIFT_1;
    output_quant_params.multiplier = SVDF_1_MULTIPLIER_OUT;
    output_quant_params.shift = SVDF_1_SHIFT_2;

    svdf_params.input_activation.min = SVDF_1_IN_ACTIVATION_MIN;
    svdf_params.input_activation.max = SVDF_1_IN_ACTIVATION_MAX;
    svdf_params.output_activation.min = SVDF_1_OUT_ACTIVATION_MIN;
    svdf_params.output_activation.max = SVDF_1_OUT_ACTIVATION_MAX;
    svdf_params.input_offset = SVDF_1_INPUT_OFFSET;
    svdf_params.output_offset = SVDF_1_OUTPUT_OFFSET;
    svdf_params.rank = SVDF_1_RANK;

    const int32_t output_ref_size = SVDF_1_DST_SIZE;
    const int8_t *output_ref = svdf_1_output_ref;
    const int input_round_size = SVDF_1_INPUT_BATCHES * SVDF_1_INPUT_SIZE;
    const int number_inputs = sizeof(svdf_1_input_sequence) / input_round_size;
    const int32_t number_units = SVDF_1_FEATURE_BATCHES / SVDF_1_RANK;
    const int scratch_size = SVDF_1_INPUT_BATCHES * SVDF_1_FEATURE_BATCHES * sizeof(int32_t);
    const int scratch_size_out = SVDF_1_INPUT_BATCHES * number_units * sizeof(int32_t);

    input_ctx.buf = malloc(scratch_size);
    output_ctx.buf = malloc(scratch_size_out);

    int8_t *input_data = malloc(input_round_size);
    q15_t *state_data = malloc(sizeof(svdf_1_state));

    const bool null_bias = check_null_bias(svdf_1_biases, SVDF_1_DST_SIZE / SVDF_1_INPUT_BATCHES);

    for (int i = 0; i < REPEAT_NUM; i++)
    {
        memcpy(state_data, svdf_1_state, sizeof(svdf_1_state));
        for (int j = 0; j < number_inputs; j++)
        {
            memcpy(input_data, svdf_1_input_sequence + j * input_round_size, input_round_size);
            muriscv_nn_status result = muriscv_nn_svdf_state_s16_s8(&input_ctx,
                                                                    &output_ctx,
                                                                    &svdf_params,
                                                                    &input_quant_params,
                                                                    &output_quant_params,
                                                                    &input_dims,
                                                                    input_data,
                                                                    &state_dims,
                                                                    state_data,
                                                                    &weights_feature_dims,
                                                                    weights_feature_data,
                                                                    &weights_time_dims,
                                                                    weights_time_data,
                                                                    &bias_dims,
                                                                    null_bias == true ? NULL : svdf_1_biases,
                                                                    &output_dims,
                                                                    output_data);
            TEST_ASSERT_EQUAL(MURISCV_NN_SUCCESS, result);
        }

        TEST_ASSERT_TRUE(validate(output_data, output_ref, output_ref_size, TOLERANCE));
    }
    free(state_data);
    free(input_data);
    free(input_ctx.buf);
    free(output_ctx.buf);
}

void test_muriscv_nn_svdf_2_s8(void)
{
    muriscv_nn_context input_ctx;
    muriscv_nn_context output_ctx;
    muriscv_nn_svdf_params svdf_params;
    muriscv_nn_dims input_dims;
    muriscv_nn_dims weights_feature_dims;
    muriscv_nn_dims weights_time_dims;
    muriscv_nn_dims state_dims;
    muriscv_nn_dims output_dims;
    muriscv_nn_dims bias_dims;
    muriscv_nn_per_tensor_quant_params input_quant_params;
    muriscv_nn_per_tensor_quant_params output_quant_params;
    int8_t output_data[SVDF_2_DST_SIZE];
    const q7_t *weights_feature_data = svdf_2_weights_feature;
    const q15_t *weights_time_data = svdf_2_weights_time;

    input_dims.n = SVDF_2_INPUT_BATCHES;
    input_dims.h = SVDF_2_INPUT_SIZE;
    weights_feature_dims.n = SVDF_2_FEATURE_BATCHES;
    weights_time_dims.h = SVDF_2_TIME_BATCHES;

    input_quant_params.multiplier = SVDF_2_MULTIPLIER_IN;
    input_quant_params.shift = SVDF_2_SHIFT_1;
    output_quant_params.multiplier = SVDF_2_MULTIPLIER_OUT;
    output_quant_params.shift = SVDF_2_SHIFT_2;

    svdf_params.input_activation.min = SVDF_2_IN_ACTIVATION_MIN;
    svdf_params.input_activation.max = SVDF_2_IN_ACTIVATION_MAX;
    svdf_params.output_activation.min = SVDF_2_OUT_ACTIVATION_MIN;
    svdf_params.output_activation.max = SVDF_2_OUT_ACTIVATION_MAX;
    svdf_params.input_offset = SVDF_2_INPUT_OFFSET;
    svdf_params.output_offset = SVDF_2_OUTPUT_OFFSET;
    svdf_params.rank = SVDF_2_RANK;

    const int32_t output_ref_size = SVDF_2_DST_SIZE;
    const int8_t *output_ref = svdf_2_output_ref;
    const int input_round_size = SVDF_2_INPUT_BATCHES * SVDF_2_INPUT_SIZE;
    const int number_inputs = sizeof(svdf_2_input_sequence) / input_round_size;
    const int32_t number_units = SVDF_2_FEATURE_BATCHES / SVDF_2_RANK;
    const int scratch_size = SVDF_2_INPUT_BATCHES * SVDF_2_FEATURE_BATCHES * sizeof(int32_t);
    const int scratch_size_out = SVDF_2_INPUT_BATCHES * number_units * sizeof(int32_t);

    input_ctx.buf = malloc(scratch_size);
    output_ctx.buf = malloc(scratch_size_out);

    int8_t *input_data = malloc(input_round_size);
    q15_t *state_data = malloc(sizeof(svdf_2_state));

    const bool null_bias = check_null_bias(svdf_2_biases, SVDF_2_DST_SIZE / SVDF_2_INPUT_BATCHES);

    for (int i = 0; i < REPEAT_NUM; i++)
    {
        memcpy(state_data, svdf_2_state, sizeof(svdf_2_state));
        for (int j = 0; j < number_inputs; j++)
        {
            memcpy(input_data, svdf_2_input_sequence + j * input_round_size, input_round_size);
            muriscv_nn_status result = muriscv_nn_svdf_state_s16_s8(&input_ctx,
                                                                    &output_ctx,
                                                                    &svdf_params,
                                                                    &input_quant_params,
                                                                    &output_quant_params,
                                                                    &input_dims,
                                                                    input_data,
                                                                    &state_dims,
                                                                    state_data,
                                                                    &weights_feature_dims,
                                                                    weights_feature_data,
                                                                    &weights_time_dims,
                                                                    weights_time_data,
                                                                    &bias_dims,
                                                                    null_bias == true ? NULL : svdf_2_biases,
                                                                    &output_dims,
                                                                    output_data);
            TEST_ASSERT_EQUAL(MURISCV_NN_SUCCESS, result);
        }

        TEST_ASSERT_TRUE(validate(output_data, output_ref, output_ref_size, TOLERANCE));
    }
    free(state_data);
    free(input_data);
    free(input_ctx.buf);
    free(output_ctx.buf);
}

void test_muriscv_nn_svdf_3_s8(void)
{
    muriscv_nn_context input_ctx;
    muriscv_nn_context output_ctx;
    muriscv_nn_svdf_params svdf_params;
    muriscv_nn_dims input_dims;
    muriscv_nn_dims weights_feature_dims;
    muriscv_nn_dims weights_time_dims;
    muriscv_nn_dims state_dims;
    muriscv_nn_dims output_dims;
    muriscv_nn_dims bias_dims;
    muriscv_nn_per_tensor_quant_params input_quant_params;
    muriscv_nn_per_tensor_quant_params output_quant_params;
    int8_t output_data[SVDF_3_DST_SIZE];
    const q7_t *weights_feature_data = svdf_3_weights_feature;
    const q15_t *weights_time_data = svdf_3_weights_time;

    input_dims.n = SVDF_3_INPUT_BATCHES;
    input_dims.h = SVDF_3_INPUT_SIZE;
    weights_feature_dims.n = SVDF_3_FEATURE_BATCHES;
    weights_time_dims.h = SVDF_3_TIME_BATCHES;

    input_quant_params.multiplier = SVDF_3_MULTIPLIER_IN;
    input_quant_params.shift = SVDF_3_SHIFT_1;
    output_quant_params.multiplier = SVDF_3_MULTIPLIER_OUT;
    output_quant_params.shift = SVDF_3_SHIFT_2;

    svdf_params.input_activation.min = SVDF_3_IN_ACTIVATION_MIN;
    svdf_params.input_activation.max = SVDF_3_IN_ACTIVATION_MAX;
    svdf_params.output_activation.min = SVDF_3_OUT_ACTIVATION_MIN;
    svdf_params.output_activation.max = SVDF_3_OUT_ACTIVATION_MAX;
    svdf_params.input_offset = SVDF_3_INPUT_OFFSET;
    svdf_params.output_offset = SVDF_3_OUTPUT_OFFSET;
    svdf_params.rank = SVDF_3_RANK;

    const int32_t output_ref_size = SVDF_3_DST_SIZE;
    const int8_t *output_ref = svdf_3_output_ref;
    const int input_round_size = SVDF_3_INPUT_BATCHES * SVDF_3_INPUT_SIZE;
    const int number_inputs = sizeof(svdf_3_input_sequence) / input_round_size;
    const int32_t number_units = SVDF_3_FEATURE_BATCHES / SVDF_3_RANK;
    const int scratch_size = SVDF_3_INPUT_BATCHES * SVDF_3_FEATURE_BATCHES * sizeof(int32_t);
    const int scratch_size_out = SVDF_3_INPUT_BATCHES * number_units * sizeof(int32_t);

    input_ctx.buf = malloc(scratch_size);
    output_ctx.buf = malloc(scratch_size_out);

    int8_t *input_data = malloc(input_round_size);
    q15_t *state_data = malloc(sizeof(svdf_3_state));

    const bool null_bias = check_null_bias(svdf_3_biases, SVDF_3_DST_SIZE / SVDF_3_INPUT_BATCHES);

    for (int i = 0; i < REPEAT_NUM; i++)
    {
        memcpy(state_data, svdf_3_state, sizeof(svdf_3_state));
        for (int j = 0; j < number_inputs; j++)
        {
            memcpy(input_data, svdf_3_input_sequence + j * input_round_size, input_round_size);
            muriscv_nn_status result = muriscv_nn_svdf_state_s16_s8(&input_ctx,
                                                                    &output_ctx,
                                                                    &svdf_params,
                                                                    &input_quant_params,
                                                                    &output_quant_params,
                                                                    &input_dims,
                                                                    input_data,
                                                                    &state_dims,
                                                                    state_data,
                                                                    &weights_feature_dims,
                                                                    weights_feature_data,
                                                                    &weights_time_dims,
                                                                    weights_time_data,
                                                                    &bias_dims,
                                                                    null_bias == true ? NULL : svdf_3_biases,
                                                                    &output_dims,
                                                                    output_data);
            TEST_ASSERT_EQUAL(MURISCV_NN_SUCCESS, result);
        }

        TEST_ASSERT_TRUE(validate(output_data, output_ref, output_ref_size, TOLERANCE));
    }
    free(state_data);
    free(input_data);
    free(input_ctx.buf);
    free(output_ctx.buf);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_muriscv_nn_svdf_0_s8);
    RUN_TEST(test_muriscv_nn_svdf_1_s8);
    RUN_TEST(test_muriscv_nn_svdf_2_s8);
    RUN_TEST(test_muriscv_nn_svdf_3_s8);

#if defined(__riscv) || defined(__riscv__)
    /* If an error occurred make sure the simulator fails so CTest can detect that. */
    int failures = UNITY_END();
    if (failures != 0)
    {
        __asm__ volatile("unimp");
    }
    return failures;
#else
    return UNITY_END();
#endif
}
