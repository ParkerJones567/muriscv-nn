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
#include <stdlib.h>
#include <unity.h>

#include "../../TestData/int16xint8/test_data.h"
#include "../../TestData/int16xint8_dilation_1/test_data.h"
#include "../../TestData/int16xint8_dilation_2/test_data.h"
#include "../../TestData/int16xint8_dilation_3/test_data.h"
#include "../../TestData/requantize_s64/test_data.h"
#include "../../Utils/validate.h"

void setUp(void)
{ /* set stuff up here */
}

void tearDown(void)
{ /* clean stuff up here */
}

void int16xint8_muriscv_nn_convolve_s16(void)
{
    q15_t output[INT16XINT8_DST_SIZE] = {0};

    muriscv_nn_context ctx;
    muriscv_nn_conv_params conv_params;
    muriscv_nn_per_channel_quant_params quant_params;
    muriscv_nn_dims input_dims;
    muriscv_nn_dims filter_dims;
    muriscv_nn_dims bias_dims;
    muriscv_nn_dims output_dims;

    const q63_t *bias_pointer = int16xint8_biases;
    const q7_t *kernel_data = int16xint8_weights;
    const q15_t *input_data = int16xint8_input;
    const q15_t *output_ref = int16xint8_output_ref;
    const int32_t output_ref_size = INT16XINT8_DST_SIZE;

    input_dims.n = INT16XINT8_INPUT_BATCHES;
    input_dims.w = INT16XINT8_INPUT_W;
    input_dims.h = INT16XINT8_INPUT_H;
    input_dims.c = INT16XINT8_IN_CH;
    filter_dims.w = INT16XINT8_FILTER_X;
    filter_dims.h = INT16XINT8_FILTER_Y;
    output_dims.w = INT16XINT8_OUTPUT_W;
    output_dims.h = INT16XINT8_OUTPUT_H;
    output_dims.c = INT16XINT8_OUT_CH;

    conv_params.padding.w = INT16XINT8_PAD_X;
    conv_params.padding.h = INT16XINT8_PAD_Y;
    conv_params.stride.w = INT16XINT8_STRIDE_X;
    conv_params.stride.h = INT16XINT8_STRIDE_Y;
    conv_params.dilation.w = INT16XINT8_DILATION_X;
    conv_params.dilation.h = INT16XINT8_DILATION_Y;

    conv_params.input_offset = 0;
    conv_params.output_offset = 0;
    conv_params.activation.min = INT16XINT8_OUT_ACTIVATION_MIN;
    conv_params.activation.max = INT16XINT8_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)int16xint8_output_mult;
    quant_params.shift = (int32_t *)int16xint8_output_shift;
    
    muriscv_nn_bias_data bias_data = { .data = (void*)bias_pointer, .is_int32_bias = false };

    int buf_size = muriscv_nn_convolve_s16_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);

    muriscv_nn_status result = muriscv_nn_convolve_s16(&ctx,
                                                       &conv_params,
                                                       &quant_params,
                                                       &input_dims,
                                                       input_data,
                                                       &filter_dims,
                                                       kernel_data,
                                                       &bias_dims,
                                                       &bias_data,
                                                       &output_dims,
                                                       output);
    free(ctx.buf);
    TEST_ASSERT_EQUAL(MURISCV_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));

    buf_size = muriscv_nn_convolve_wrapper_s16_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);

    result = muriscv_nn_convolve_wrapper_s16(&ctx,
                                             &conv_params,
                                             &quant_params,
                                             &input_dims,
                                             input_data,
                                             &filter_dims,
                                             kernel_data,
                                             &bias_dims,
                                             &bias_data,
                                             &output_dims,
                                             output);

    free(ctx.buf);
    TEST_ASSERT_EQUAL(MURISCV_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));
}

void requantize_s64_muriscv_nn_convolve_s16(void)
{
    q15_t output[REQUANTIZE_S64_DST_SIZE] = {0};

    muriscv_nn_context ctx;
    muriscv_nn_conv_params conv_params;
    muriscv_nn_per_channel_quant_params quant_params;
    muriscv_nn_dims input_dims;
    muriscv_nn_dims filter_dims;
    muriscv_nn_dims bias_dims;
    muriscv_nn_dims output_dims;

    const q63_t *bias_pointer = requantize_s64_biases;
    const q7_t *kernel_data = requantize_s64_weights;
    const q15_t *input_data = requantize_s64_input;
    const q15_t *output_ref = requantize_s64_output_ref;
    const int32_t output_ref_size = REQUANTIZE_S64_DST_SIZE;

    input_dims.n = REQUANTIZE_S64_INPUT_BATCHES;
    input_dims.w = REQUANTIZE_S64_INPUT_W;
    input_dims.h = REQUANTIZE_S64_INPUT_H;
    input_dims.c = REQUANTIZE_S64_IN_CH;
    filter_dims.w = REQUANTIZE_S64_FILTER_X;
    filter_dims.h = REQUANTIZE_S64_FILTER_Y;
    output_dims.w = REQUANTIZE_S64_OUTPUT_W;
    output_dims.h = REQUANTIZE_S64_OUTPUT_H;
    output_dims.c = REQUANTIZE_S64_OUT_CH;

    conv_params.padding.w = REQUANTIZE_S64_PAD_X;
    conv_params.padding.h = REQUANTIZE_S64_PAD_Y;
    conv_params.stride.w = REQUANTIZE_S64_STRIDE_X;
    conv_params.stride.h = REQUANTIZE_S64_STRIDE_Y;
    conv_params.dilation.w = REQUANTIZE_S64_STRIDE_X;
    conv_params.dilation.h = REQUANTIZE_S64_STRIDE_Y;

    conv_params.input_offset = REQUANTIZE_S64_INPUT_OFFSET;
    conv_params.output_offset = REQUANTIZE_S64_OUTPUT_OFFSET;
    conv_params.activation.min = REQUANTIZE_S64_OUT_ACTIVATION_MIN;
    conv_params.activation.max = REQUANTIZE_S64_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)requantize_s64_output_mult;
    quant_params.shift = (int32_t *)requantize_s64_output_shift;
    
    muriscv_nn_bias_data bias_data = { .data = (void*)bias_pointer, .is_int32_bias = false };

    int buf_size = muriscv_nn_convolve_s16_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);

    muriscv_nn_status result = muriscv_nn_convolve_s16(&ctx,
                                                       &conv_params,
                                                       &quant_params,
                                                       &input_dims,
                                                       input_data,
                                                       &filter_dims,
                                                       kernel_data,
                                                       &bias_dims,
                                                       &bias_data,
                                                       &output_dims,
                                                       output);
    free(ctx.buf);
    TEST_ASSERT_EQUAL(MURISCV_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));

    buf_size = muriscv_nn_convolve_wrapper_s16_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);

    result = muriscv_nn_convolve_wrapper_s16(&ctx,
                                             &conv_params,
                                             &quant_params,
                                             &input_dims,
                                             input_data,
                                             &filter_dims,
                                             kernel_data,
                                             &bias_dims,
                                             &bias_data,
                                             &output_dims,
                                             output);

    free(ctx.buf);
    TEST_ASSERT_EQUAL(MURISCV_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));
}

void int16xint8_dilation_1_muriscv_nn_convolve_s16(void)
{
    q15_t output[INT16XINT8_DILATION_1_DST_SIZE] = {0};

    muriscv_nn_context ctx;
    muriscv_nn_conv_params conv_params;
    muriscv_nn_per_channel_quant_params quant_params;
    muriscv_nn_dims input_dims;
    muriscv_nn_dims filter_dims;
    muriscv_nn_dims bias_dims;
    muriscv_nn_dims output_dims;

    const q63_t *bias_pointer = int16xint8_dilation_1_biases;
    const q7_t *kernel_data = int16xint8_dilation_1_weights;
    const q15_t *input_data = int16xint8_dilation_1_input;
    const q15_t *output_ref = int16xint8_dilation_1_output_ref;
    const int32_t output_ref_size = INT16XINT8_DILATION_1_DST_SIZE;

    input_dims.n = INT16XINT8_DILATION_1_INPUT_BATCHES;
    input_dims.w = INT16XINT8_DILATION_1_INPUT_W;
    input_dims.h = INT16XINT8_DILATION_1_INPUT_H;
    input_dims.c = INT16XINT8_DILATION_1_IN_CH;
    filter_dims.w = INT16XINT8_DILATION_1_FILTER_X;
    filter_dims.h = INT16XINT8_DILATION_1_FILTER_Y;
    output_dims.w = INT16XINT8_DILATION_1_OUTPUT_W;
    output_dims.h = INT16XINT8_DILATION_1_OUTPUT_H;
    output_dims.c = INT16XINT8_DILATION_1_OUT_CH;

    conv_params.padding.w = INT16XINT8_DILATION_1_PAD_X;
    conv_params.padding.h = INT16XINT8_DILATION_1_PAD_Y;
    conv_params.stride.w = INT16XINT8_DILATION_1_STRIDE_X;
    conv_params.stride.h = INT16XINT8_DILATION_1_STRIDE_Y;
    conv_params.dilation.w = INT16XINT8_DILATION_1_DILATION_X;
    conv_params.dilation.h = INT16XINT8_DILATION_1_DILATION_Y;

    conv_params.input_offset = INT16XINT8_DILATION_1_INPUT_OFFSET;
    conv_params.output_offset = INT16XINT8_DILATION_1_OUTPUT_OFFSET;
    conv_params.activation.min = INT16XINT8_DILATION_1_OUT_ACTIVATION_MIN;
    conv_params.activation.max = INT16XINT8_DILATION_1_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)int16xint8_dilation_1_output_mult;
    quant_params.shift = (int32_t *)int16xint8_dilation_1_output_shift;
    
    muriscv_nn_bias_data bias_data = { .data = (void*)bias_pointer, .is_int32_bias = false };

    int buf_size = muriscv_nn_convolve_s16_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);

    muriscv_nn_status result = muriscv_nn_convolve_s16(&ctx,
                                                       &conv_params,
                                                       &quant_params,
                                                       &input_dims,
                                                       input_data,
                                                       &filter_dims,
                                                       kernel_data,
                                                       &bias_dims,
                                                       &bias_data,
                                                       &output_dims,
                                                       output);
    free(ctx.buf);
    TEST_ASSERT_EQUAL(MURISCV_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));

    buf_size = muriscv_nn_convolve_wrapper_s16_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);

    result = muriscv_nn_convolve_wrapper_s16(&ctx,
                                             &conv_params,
                                             &quant_params,
                                             &input_dims,
                                             input_data,
                                             &filter_dims,
                                             kernel_data,
                                             &bias_dims,
                                             &bias_data,
                                             &output_dims,
                                             output);

    free(ctx.buf);
    TEST_ASSERT_EQUAL(MURISCV_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));
}

void int16xint8_dilation_2_muriscv_nn_convolve_s16(void)
{
    q15_t output[INT16XINT8_DILATION_2_DST_SIZE] = {0};

    muriscv_nn_context ctx;
    muriscv_nn_conv_params conv_params;
    muriscv_nn_per_channel_quant_params quant_params;
    muriscv_nn_dims input_dims;
    muriscv_nn_dims filter_dims;
    muriscv_nn_dims bias_dims;
    muriscv_nn_dims output_dims;

    const q63_t *bias_pointer = int16xint8_dilation_2_biases;
    const q7_t *kernel_data = int16xint8_dilation_2_weights;
    const q15_t *input_data = int16xint8_dilation_2_input;
    const q15_t *output_ref = int16xint8_dilation_2_output_ref;
    const int32_t output_ref_size = INT16XINT8_DILATION_2_DST_SIZE;

    input_dims.n = INT16XINT8_DILATION_2_INPUT_BATCHES;
    input_dims.w = INT16XINT8_DILATION_2_INPUT_W;
    input_dims.h = INT16XINT8_DILATION_2_INPUT_H;
    input_dims.c = INT16XINT8_DILATION_2_IN_CH;
    filter_dims.w = INT16XINT8_DILATION_2_FILTER_X;
    filter_dims.h = INT16XINT8_DILATION_2_FILTER_Y;
    output_dims.w = INT16XINT8_DILATION_2_OUTPUT_W;
    output_dims.h = INT16XINT8_DILATION_2_OUTPUT_H;
    output_dims.c = INT16XINT8_DILATION_2_OUT_CH;

    conv_params.padding.w = INT16XINT8_DILATION_2_PAD_X;
    conv_params.padding.h = INT16XINT8_DILATION_2_PAD_Y;
    conv_params.stride.w = INT16XINT8_DILATION_2_STRIDE_X;
    conv_params.stride.h = INT16XINT8_DILATION_2_STRIDE_Y;
    conv_params.dilation.w = INT16XINT8_DILATION_2_DILATION_X;
    conv_params.dilation.h = INT16XINT8_DILATION_2_DILATION_Y;

    conv_params.input_offset = INT16XINT8_DILATION_2_INPUT_OFFSET;
    conv_params.output_offset = INT16XINT8_DILATION_2_OUTPUT_OFFSET;
    conv_params.activation.min = INT16XINT8_DILATION_2_OUT_ACTIVATION_MIN;
    conv_params.activation.max = INT16XINT8_DILATION_2_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)int16xint8_dilation_2_output_mult;
    quant_params.shift = (int32_t *)int16xint8_dilation_2_output_shift;
    
    muriscv_nn_bias_data bias_data = { .data = (void*)bias_pointer, .is_int32_bias = false };

    int buf_size = muriscv_nn_convolve_s16_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);

    muriscv_nn_status result = muriscv_nn_convolve_s16(&ctx,
                                                       &conv_params,
                                                       &quant_params,
                                                       &input_dims,
                                                       input_data,
                                                       &filter_dims,
                                                       kernel_data,
                                                       &bias_dims,
                                                       &bias_data,
                                                       &output_dims,
                                                       output);
    free(ctx.buf);
    TEST_ASSERT_EQUAL(MURISCV_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));

    buf_size = muriscv_nn_convolve_wrapper_s16_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);

    result = muriscv_nn_convolve_wrapper_s16(&ctx,
                                             &conv_params,
                                             &quant_params,
                                             &input_dims,
                                             input_data,
                                             &filter_dims,
                                             kernel_data,
                                             &bias_dims,
                                             &bias_data,
                                             &output_dims,
                                             output);

    free(ctx.buf);
    TEST_ASSERT_EQUAL(MURISCV_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));
}

void int16xint8_dilation_3_muriscv_nn_convolve_s16(void)
{
    q15_t output[INT16XINT8_DILATION_3_DST_SIZE] = {0};

    muriscv_nn_context ctx;
    muriscv_nn_conv_params conv_params;
    muriscv_nn_per_channel_quant_params quant_params;
    muriscv_nn_dims input_dims;
    muriscv_nn_dims filter_dims;
    muriscv_nn_dims bias_dims;
    muriscv_nn_dims output_dims;
    

    const q63_t *bias_pointer = int16xint8_dilation_3_biases;
    const q7_t *kernel_data = int16xint8_dilation_3_weights;
    const q15_t *input_data = int16xint8_dilation_3_input;
    const q15_t *output_ref = int16xint8_dilation_3_output_ref;
    const int32_t output_ref_size = INT16XINT8_DILATION_3_DST_SIZE;

    input_dims.n = INT16XINT8_DILATION_3_INPUT_BATCHES;
    input_dims.w = INT16XINT8_DILATION_3_INPUT_W;
    input_dims.h = INT16XINT8_DILATION_3_INPUT_H;
    input_dims.c = INT16XINT8_DILATION_3_IN_CH;
    filter_dims.w = INT16XINT8_DILATION_3_FILTER_X;
    filter_dims.h = INT16XINT8_DILATION_3_FILTER_Y;
    output_dims.w = INT16XINT8_DILATION_3_OUTPUT_W;
    output_dims.h = INT16XINT8_DILATION_3_OUTPUT_H;
    output_dims.c = INT16XINT8_DILATION_3_OUT_CH;

    conv_params.padding.w = INT16XINT8_DILATION_3_PAD_X;
    conv_params.padding.h = INT16XINT8_DILATION_3_PAD_Y;
    conv_params.stride.w = INT16XINT8_DILATION_3_STRIDE_X;
    conv_params.stride.h = INT16XINT8_DILATION_3_STRIDE_Y;
    conv_params.dilation.w = INT16XINT8_DILATION_3_DILATION_X;
    conv_params.dilation.h = INT16XINT8_DILATION_3_DILATION_Y;

    conv_params.input_offset = INT16XINT8_DILATION_3_INPUT_OFFSET;
    conv_params.output_offset = INT16XINT8_DILATION_3_OUTPUT_OFFSET;
    conv_params.activation.min = INT16XINT8_DILATION_3_OUT_ACTIVATION_MIN;
    conv_params.activation.max = INT16XINT8_DILATION_3_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)int16xint8_dilation_3_output_mult;
    quant_params.shift = (int32_t *)int16xint8_dilation_3_output_shift;
    
    muriscv_nn_bias_data bias_data = { .data = (void*)bias_pointer, .is_int32_bias = false };

    int buf_size = muriscv_nn_convolve_s16_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);

    muriscv_nn_status result = muriscv_nn_convolve_s16(&ctx,
                                                       &conv_params,
                                                       &quant_params,
                                                       &input_dims,
                                                       input_data,
                                                       &filter_dims,
                                                       kernel_data,
                                                       &bias_dims,
                                                       &bias_data,
                                                       &output_dims,
                                                       output);
    free(ctx.buf);
    TEST_ASSERT_EQUAL(MURISCV_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));

    buf_size = muriscv_nn_convolve_wrapper_s16_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);

    result = muriscv_nn_convolve_wrapper_s16(&ctx,
                                             &conv_params,
                                             &quant_params,
                                             &input_dims,
                                             input_data,
                                             &filter_dims,
                                             kernel_data,
                                             &bias_dims,
                                             &bias_data,
                                             &output_dims,
                                             output);

    free(ctx.buf);
    TEST_ASSERT_EQUAL(MURISCV_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(int16xint8_muriscv_nn_convolve_s16);
    RUN_TEST(requantize_s64_muriscv_nn_convolve_s16);
    RUN_TEST(int16xint8_dilation_1_muriscv_nn_convolve_s16);
    RUN_TEST(int16xint8_dilation_2_muriscv_nn_convolve_s16);
    RUN_TEST(int16xint8_dilation_3_muriscv_nn_convolve_s16);

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
