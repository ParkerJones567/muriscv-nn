// Modifications copyright (C) 2024 Chair of Electronic Design Automation, TUM
/*
 * SPDX-FileCopyrightText: Copyright 2010-2024 Arm Limited and/or its affiliates <open-source-office@arm.com>
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
 */

/* ----------------------------------------------------------------------
 * Project:      MURISCV NN Library
 * Title:        muriscv_nn_support_functions.h
 * Description:  Public header file of support functions for MURISCV NN Library
 *
 * $Date:        16 April 2024
 * $Revision:    V.20.3.0
 *
 * Target :  Arm(R) M-Profile Architecture
 * -------------------------------------------------------------------- */

#ifndef MURISCV_NNSUPPORT_FUNCTIONS_H
#define MURISCV_NNSUPPORT_FUNCTIONS_H

#include "Internal/muriscv_nn_compiler.h"
#include "muriscv_nn_math_types.h"
#include "muriscv_nn_types.h"

//MURISCV_NN NEW CODE  //Include this around any code unique to muRISCV-nn for auto-sync with CMSIS
#if defined(USE_VEXT)
#include <riscv_vector.h>
#if (__clang_major__ >= 16) || (__GNUC__ >= 13)
#if __clang_major__ >= 17
#define vsmul_vx_i32m8(a, b, c) __riscv_vsmul_vx_i32m8(a, b, __RISCV_VXRM_RNU, c)
#define vsmul_vx_i32m4(a, b, c) __riscv_vsmul_vx_i32m4(a, b, __RISCV_VXRM_RNU, c)
#define vsmul_vv_i32m2(a, b, c) __riscv_vsmul_vv_i32m2(a, b, __RISCV_VXRM_RNU, c)
#define vnclip_wx_i16m4(a, b, c) __riscv_vnclip_wx_i16m4(a, b, __RISCV_VXRM_RNU, c)
#define vnclip_wx_i16m2(a, b, c) __riscv_vnclip_wx_i16m2(a, b, __RISCV_VXRM_RNU, c)
#define vnclip_wx_i16m1(a, b, c) __riscv_vnclip_wx_i16m1(a, b, __RISCV_VXRM_RNU, c)
#define vnclip_wx_i8m2(a, b, c) __riscv_vnclip_wx_i8m2(a, b, __RISCV_VXRM_RNU, c)
#define vnclip_wx_i8m1(a, b, c) __riscv_vnclip_wx_i8m1(a, b, __RISCV_VXRM_RNU, c)
#define vnclip_wx_i8mf2(a, b, c) __riscv_vnclip_wx_i8mf2(a, b, __RISCV_VXRM_RNU, c)
#else
#define vsmul_vx_i32m8 __riscv_vsmul_vx_i32m8
#define vsmul_vx_i32m4 __riscv_vsmul_vx_i32m4
#define vsmul_vv_i32m2 __riscv_vsmul_vv_i32m2
#define vnclip_wx_i16m4 __riscv_vnclip_wx_i16m4
#define vnclip_wx_i16m2 __riscv_vnclip_wx_i16m2
#define vnclip_wx_i16m1 __riscv_vnclip_wx_i16m1
#define vnclip_wx_i8m2 __riscv_vnclip_wx_i8m2
#define vnclip_wx_i8m1 __riscv_vnclip_wx_i8m1
#define vnclip_wx_i8mf2 __riscv_vnclip_wx_i8mf2
#endif

#define vand_vx_i32m8 __riscv_vand_vx_i32m8
#define vmv_v_x_i32m8 __riscv_vmv_v_x_i32m8
#define vsra_vx_i32m8 __riscv_vsra_vx_i32m8
#define vmslt_vx_i32m8_b4 __riscv_vmslt_vx_i32m8_b4
#define vadd_vx_i32m8_m __riscv_vadd_vx_i32m8_tum
#define vmsgt_vv_i32m8_b4 __riscv_vmsgt_vv_i32m8_b4
#define vand_vx_i32m4 __riscv_vand_vx_i32m4
#define vmv_v_x_i32m4 __riscv_vmv_v_x_i32m4
#define vsra_vx_i32m4 __riscv_vsra_vx_i32m4
#define vmslt_vx_i32m4_b8 __riscv_vmslt_vx_i32m4_b8
#define vadd_vx_i32m4_m __riscv_vadd_vx_i32m4_tum
#define vadd_vx_i32m4 __riscv_vadd_vx_i32m4
#define vmsgt_vv_i32m4_b8 __riscv_vmsgt_vv_i32m4_b8
#define vreinterpret_v_i32m2_u32m2 __riscv_vreinterpret_v_i32m2_u32m2
#define vneg_v_i32m2 __riscv_vneg_v_i32m2
#define vsra_vv_i32m2 __riscv_vsra_vv_i32m2
#define vsub_vx_i32m2 __riscv_vsub_vx_i32m2
#define vsll_vv_i32m2 __riscv_vsll_vv_i32m2
#define vmv_v_x_i32m2 __riscv_vmv_v_x_i32m2
#define vsra_vx_i32m2 __riscv_vsra_vx_i32m2
#define vmslt_vx_i32m2_b16 __riscv_vmslt_vx_i32m2_b16
#define vadd_vx_i32m2_m __riscv_vadd_vx_i32m2_tum
#define vand_vv_i32m2 __riscv_vand_vv_i32m2
#define vmsgt_vv_i32m2_b16 __riscv_vmsgt_vv_i32m2_b16
#define vsetvl_e8m8 __riscv_vsetvl_e8m8
#define vsetvl_e32m4 __riscv_vsetvl_e32m4
#define vle8_v_i8m8 __riscv_vle8_v_i8m8
#define vse8_v_i8m8 __riscv_vse8_v_i8m8
#define vadd_vv_i32m8 __riscv_vadd_vv_i32m8
#define vadd_vx_i32m2 __riscv_vadd_vx_i32m2
#define vadd_vx_i32m8 __riscv_vadd_vx_i32m8
#define vle16_v_i16m4 __riscv_vle16_v_i16m4
#define vle16_v_i16m8 __riscv_vle16_v_i16m8
#define vle32_v_i32m2 __riscv_vle32_v_i32m2
#define vle8_v_i8m2 __riscv_vle8_v_i8m2
#define vle8_v_i8mf2 __riscv_vle8_v_i8mf2
#define vmacc_vv_i32m2 __riscv_vmacc_vv_i32m2
#define vmacc_vv_i32m8 __riscv_vmacc_vv_i32m8
#define vmax_vv_i16m8 __riscv_vmax_vv_i16m8
#define vmax_vv_i8m8 __riscv_vmax_vv_i8m8
#define vmax_vx_i16m8 __riscv_vmax_vx_i16m8
#define vmax_vx_i8m8 __riscv_vmax_vx_i8m8
#define vmin_vx_i8m8 __riscv_vmin_vx_i8m8
#define vmnot_m_b4 __riscv_vmnot_m_b4
#define vmsgt_vx_i32m8_b4 __riscv_vmsgt_vx_i32m8_b4
#define vmul_vv_i32m8 __riscv_vmul_vv_i32m8
#define vmv_v_x_i32m1 __riscv_vmv_v_x_i32m1
#define vmv_v_x_i8m8 __riscv_vmv_v_x_i8m8
#define vredsum_vs_i32m8_i32m1(a, b, c, d) __riscv_vredsum_vs_i32m8_i32m1(b, c, d)
#define vse16_v_i16m8 __riscv_vse16_v_i16m8
#define vsetvl_e16m4 __riscv_vsetvl_e16m4
#define vsetvl_e16m8 __riscv_vsetvl_e16m8
#define vsetvl_e32m1 __riscv_vsetvl_e32m1
#define vsetvl_e32m2 __riscv_vsetvl_e32m2
#define vsetvl_e32m8 __riscv_vsetvl_e32m8
#define vsetvl_e8m2 __riscv_vsetvl_e8m2
#define vsext_vf2_i32m8 __riscv_vsext_vf2_i32m8
#define vsext_vf4_i32m2 __riscv_vsext_vf4_i32m2
#define vsext_vf4_i32m8 __riscv_vsext_vf4_i32m8
#define vsll_vx_i32m8 __riscv_vsll_vx_i32m8
#define vundefined_i32m1 __riscv_vundefined_i32m1
#define vadd_vv_i32m2 __riscv_vadd_vv_i32m2
#define vdiv_vx_i32m8 __riscv_vdiv_vx_i32m8
#define vle32_v_i32m1 __riscv_vle32_v_i32m1
#define vmax_vx_i32m2 __riscv_vmax_vx_i32m2
#define vmax_vx_i32m8 __riscv_vmax_vx_i32m8
#define vmin_vx_i16m8 __riscv_vmin_vx_i16m8
#define vmin_vx_i32m2 __riscv_vmin_vx_i32m2
#define vmin_vx_i32m8 __riscv_vmin_vx_i32m8
#define vmul_vx_i32m2 __riscv_vmul_vx_i32m2
#define vmv_x_s_i32m1_i32 __riscv_vmv_x_s_i32m1_i32
#define vredsum_vs_i32m2_i32m1(a, b, c, d) __riscv_vredsum_vs_i32m2_i32m1(b, c, d)
#define vse8_v_i8mf2 __riscv_vse8_v_i8mf2
#define vsub_vx_i32m8_m __riscv_vsub_vx_i32m8_tum
#define vse16_v_i16m4 __riscv_vse16_v_i16m4
#define vse8_v_i8m2 __riscv_vse8_v_i8m2
#define vslide1up_vx_i32m4 __riscv_vslide1up_vx_i32m4
#define vmin_vx_i32m4 __riscv_vmin_vx_i32m4
#define vse32_v_i32m4 __riscv_vse32_v_i32m4
#define vmax_vx_i32m4 __riscv_vmax_vx_i32m4
#define vsse8_v_i8m1 __riscv_vsse8_v_i8m1
#endif

#elif defined(USE_PEXT)
#include <rvp_intrinsic.h>
#endif
#include "muriscv_nn_util.h"
#include <stdbool.h>
#include <string.h>
//MURISCV_NN END OF NEW CODE
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define USE_FAST_DW_CONV_S16_FUNCTION(dw_conv_params, filter_dims, input_dims)                                         \
    (dw_conv_params->ch_mult == 1 && dw_conv_params->dilation.w == 1 && dw_conv_params->dilation.h == 1 &&             \
     filter_dims->w * filter_dims->h < 512)

#define LEFT_SHIFT(_shift) (_shift > 0 ? _shift : 0)
#define RIGHT_SHIFT(_shift) (_shift > 0 ? 0 : -_shift)
#define MASK_IF_ZERO(x) (x) == 0 ? ~0 : 0
#define MASK_IF_NON_ZERO(x) (x) != 0 ? ~0 : 0
#define SELECT_USING_MASK(mask, a, b) ((mask) & (a)) ^ (~(mask) & (b))

//MURISCV_NN NEW CODE
#if defined(USE_PEXT)
#define MAX_RV(A, B) __rv_max(A, B)
#define MIN_RV(A, B) __rv_min(A, B)
#else
#define MAX_RV(A, B) ((A) > (B) ? (A) : (B))
#define MIN_RV(A, B) ((A) < (B) ? (A) : (B))
#endif
//MURISCV_NN END OF NEW CODE
//MURISCV_NN CUSTOM CODE
#define MAX(A, B) MAX_RV(A, B)
//MURISCV_NN CUSTOM CODE
#define MIN(A, B) MIN_RV(A, B)
#define CLAMP(x, h, l) MAX(MIN((x), (h)), (l))
#define REDUCE_MULTIPLIER(_mult) ((_mult < 0x7FFF0000) ? ((_mult + (1 << 15)) >> 16) : 0x7FFF)

// Number of channels processed in a block for DW Conv(MVE)
// Requirement: Greater than 0 & less than 128
// This can be fine tuned to match number of input channels for best performance.
// A layer with lower number of channels than CH_IN_BLOCK_MVE will result in higher
// scratch buffer usage and a layer with higher number of channels than CH_IN_BLOCK_MVE
// will result in lower scratch buffer usage.
#define CH_IN_BLOCK_MVE (124)

// For input of int16 when number of columns are above this limit int64 accumulation is needed
// to not loose precision.
#define MAX_COL_COUNT (512)

//MURISCV_NN CUSTOM CODE
/**
 * @brief definition to pack four 8 bit values.
 */
#define PACK_S8x4_32x1(v0, v1, v2, v3) PACK_Q7x4_32x1(v0, v1, v2, v3)
//MURISCV_NN NEW CODE
#if defined(USE_PEXT)
#define PACK_Q7x4_32x1(v0, v1, v2, v3) ((__rv_packu((uint8_t)(v0), (uint8_t)(v2))) | ((__rv_packu((uint8_t)(v1), (uint8_t)(v3))) << 8))
#else
#define PACK_Q7x4_32x1(v0, v1, v2, v3)                                                                                 \
    ((((int32_t)(v0) << 0) & (int32_t)0x000000FF) | (((int32_t)(v1) << 8) & (int32_t)0x0000FF00) |                     \
     (((int32_t)(v2) << 16) & (int32_t)0x00FF0000) | (((int32_t)(v3) << 24) & (int32_t)0xFF000000))
#endif
//MURISCV_NN END OF NEW CODE

/**
 * @brief definition to pack two 16 bit values.
 */
#define PACK_Q15x2_32x1(v0, v1) (((int32_t)v0 & (int32_t)0xFFFF) | ((int32_t)v1 << 16))

//MURISCV_NN NEW CODE
/**
* @brief These instructions are part of the rv32imv spec, but not currently supported by Vicuna (as of 06/2023). Attempting to use them results in an illegal instruction exception.
*/
#if defined(SIM_VICUNA)

#define vsext_vf4_i32m2 vicuna_sext_i32m2
static inline vint32m2_t vicuna_sext_i32m2(vint8mf2_t input, size_t vl)
{
    return vsext_vf2_i32m2(vsext_vf2_i16m1(input, vl), vl);
}

#define vsext_vf4_i32m8 vicuna_sext_i32m8
static inline vint32m8_t vicuna_sext_i32m8(vint8m2_t input, size_t vl)
{
    return vwadd_vx_i32m8(vsext_vf2_i16m4(input, vl), 0, vl);
}

#endif
//MURISCV_NN END OF NEW CODE
/**
 * @defgroup groupSupport Private
 *
 * Internal Support functions. Not intended to be called direclty by a CMSIS-NN user.
 *
 */

/**
 * @defgroup genPrivTypes Structure Types
 * @ingroup groupSupport
 * @brief Data structure types used by private functions.
 * @{
 */

/**
 * @brief Union for SIMD access of q31/s16/s8 types
 */
union muriscv_nn_word
{
    int32_t word;
    /**< q31 type */
    int16_t half_words[2];
    /**< s16 type */
    int8_t bytes[4];
    /**< s8 type */
};

/**
 * @brief Union for data type long long
 */
struct muriscv_nn_double
{
    uint32_t low;
    int32_t high;
};

union muriscv_nn_long_long
{
    int64_t long_long;
    struct muriscv_nn_double word;
};

/**
 * @} // end group groupPrivTypes
 */

/**
 * @defgroup supportConversion Data Conversion
 *
 * Perform data type conversion in-between neural network operations
 *
 */

/**
 * @brief Converts the elements from a s8 vector to a s16 vector with an added offset
 * @param[in]    src        pointer to the s8 input vector
 * @param[out]   dst        pointer to the s16 output vector
 * @param[in]    block_size length of the input vector
 * @param[in]    offset     s16 offset to be added to each input vector element.
 *
 * \par Description:
 *
 * Output elements are ordered.
 * The equation used for the conversion process is:
 *
 * <pre>
 *  dst[n] = (int16_t) src[n] + offset;   0 <= n < block_size.
 * </pre>
 *
 */
void muriscv_nn_q7_to_q15_with_offset(const int8_t *src, int16_t *dst, int32_t block_size, int16_t offset);

#if defined(USE_PEXT)
/**
 * @brief Converts the elements from a s8 vector to a s16 vector with an added offset
 * @param[in]    src        pointer to the s8 input vector
 * @param[out]   dst        pointer to the s16 output vector
 * @param[in]    block_size length of the input vector
 * @param[in]    offset     s16 offset to be added to each input vector element.
 *
 * \par Description:
 *
 * No additonal ordering is done with the result that output elements are not in order.
 * Instead of ABCD order will be ACBD.
 * Note this is for processors with DSP extension only.
 * The equation used for the conversion process is:
 *
 * <pre>
 *  dst[n - 0] = (int16_t) src[n - 0] + offset;   0 <= n < block_size.
 *  dst[n - 1] = (int16_t) src[n - 2] + offset;   0 <= n < block_size.
 *  dst[n - 2] = (int16_t) src[n - 1] + offset;   0 <= n < block_size.
 *  dst[n - 3] = (int16_t) src[n - 3] + offset;   0 <= n < block_size.
 * </pre>
 *
 */
void muriscv_nn_s8_to_s16_unordered_with_offset(const int8_t *src, int16_t *dst, int32_t block_size, int16_t offset);

#endif

/**
 * @brief Get the required buffer size for optimized s8 depthwise convolution
 *        function with constraint that in_channel equals out_channel.
 *        This is for processors with DSP extension.
 *        Refer to muriscv_nn_depthwise_conv_s8_opt_get_buffer_size() for function argument details.
 *
 * @note  Intended for compilation on Host. If compiling for an Arm target, use
 *        muriscv_nn_depthwise_conv_s8_opt_get_buffer_size(). Note also this is a support function,
 *        so not recommended to call directly even on Host.
 *
 */
int32_t muriscv_nn_depthwise_conv_s8_opt_get_buffer_size_dsp(const muriscv_nn_dims *input_dims,
                                                      const muriscv_nn_dims *filter_dims);

/**
 * @brief Depthwise conv on an im2col buffer where the input channel equals output channel.
 * @param[in]    row     pointer to row
 * @param[in]    col     pointer to im2col buffer, always consists of 2 columns.
 * @param[in]    num_ch   number of channels
 * @param[in]    out_shift  pointer to per output channel requantization shift parameter.
 * @param[in]    out_mult   pointer to per output channel requantization multiplier parameter.
 * @param[in]    out_offset      output tensor offset.
 * @param[in]    activation_min   minimum value to clamp the output to. Range : int8
 * @param[in]    activation_max   maximum value to clamp the output to. Range : int8
 * @param[in]    kernel_size   number of elements in one column.
 * @param[in]    output_bias per output channel bias. Range : int32
 * @param[out]   out         pointer to output
 * @return     The function returns one of the two
 *              1. The incremented output pointer for a successful operation or
 *              2. NULL if implementation is not available.
 *
 * @details     Supported framework: TensorFlow Lite micro.
 */
int8_t *muriscv_nn_depthwise_conv_s8_core(const int8_t *row,
                                      const int16_t *col,
                                      const uint16_t num_ch,
                                      const int32_t *out_shift,
                                      const int32_t *out_mult,
                                      const int32_t out_offset,
                                      const int32_t activation_min,
                                      const int32_t activation_max,
                                      const uint16_t kernel_size,
                                      const int32_t *const output_bias,
                                      int8_t *out);

/**
 * @brief General Matrix-multiplication function with per-channel requantization.
 * @param[in]       input_row    pointer to row operand
 * @param[in]       input_col    pointer to col operand
 * @param[in]       output_ch    number of rows of input_row
 * @param[in]       col_batches  number of column batches. Range: 1 to 4
 * @param[in]       output_shift  pointer to per output channel requantization shift parameter.
 * @param[in]       output_mult   pointer to per output channel requantization multiplier parameter.
 * @param[in]       out_offset    output tensor offset.
 * @param[in]       col_offset    input tensor(col) offset.
 * @param[in]       row_offset    kernel offset(row). Not used.
 * @param[in]       out_activation_min   minimum value to clamp the output to. Range : int8
 * @param[in]       out_activation_max   maximum value to clamp the output to. Range : int8
 * @param[in]       row_len       number of elements in each row
 * @param[in]       bias          per output channel bias. Range : int32
 * @param[in,out]   out           pointer to output
 * @return     The function returns one of the two
 *              1. The incremented output pointer for a successful operation or
 *              2. NULL if implementation is not available.
 *
 * @details   Supported framework: TensorFlow Lite
 */
int8_t *muriscv_nn_mat_mult_s8(const int8_t *input_row,
                           const int8_t *input_col,
                           const uint16_t output_ch,
                           const uint16_t col_batches,
                           const int32_t *output_shift,
                           const int32_t *output_mult,
                           const int32_t out_offset,
                           const int32_t col_offset,
                           const int32_t row_offset,
                           const int16_t out_activation_min,
                           const int16_t out_activation_max,
                           const uint16_t row_len,
                           const int32_t *const bias,
                           int8_t *out);
/**
 * @brief Matrix-multiplication function for convolution with per-channel requantization for 16 bits convolution.
 * @param[in]       input_a     pointer to operand A
 * @param[in]       input_b     pointer to operand B, always consists of 2 vectors.
 * @param[in]       output_ch   number of rows of A
 * @param[in]       out_shift  pointer to per output channel requantization shift parameter.
 * @param[in]       out_mult   pointer to per output channel requantization multiplier parameter.
 * @param[in]       activation_min   minimum value to clamp the output to. Range : int16
 * @param[in]       activation_max   maximum value to clamp the output to. Range : int16
 * @param[in]       num_col_a   number of columns of A
 * @param[in]       output_bias per output channel bias. Range : int64
 * @param[in,out]   out_0       pointer to output
 * @return     The function returns one of the two
 *              1. The incremented output pointer for a successful operation or
 *              2. NULL if implementation is not available.
 *
 * @details   This function does the matrix multiplication of weight matrix for all output channels
 *            with 2 columns from im2col and produces two elements/output_channel. The outputs are
 *            clamped in the range provided by activation min and max.
 *            Supported framework: TensorFlow Lite micro.
 */
int16_t *muriscv_nn_mat_mult_kernel_s16(const int8_t *input_a,
                                    const int16_t *input_b,
                                    const int32_t output_ch,
                                    const int32_t *out_shift,
                                    const int32_t *out_mult,
                                    const int32_t activation_min,
                                    const int32_t activation_max,
                                    const int32_t num_col_a,
                                    const int64_t *const output_bias,
                                    int16_t *out_0);

//MURISCV_NN CUSTOM CODE
/**
 * @brief General Matrix-multiplication without requantization for one row & one column
 * @param[in]       row_elements  number of row elements
 * @param[in]       row_base      pointer to row operand
 * @param[in]       col_base      pointer to col operand
 * @param[out]      sum_col       pointer to store sum of column elements
 * @param[out]      output        pointer to store result of multiply-accumulate
 * @return     The function returns the multiply-accumulated result of the row by column.
 *
 * @details Pseudo-code
 *      *output = 0
 *      sum_col = 0
 *      for (i = 0; i < row_elements; i++)
 *          *output += row_base[i] * col_base[i]
 *          sum_col += col_base[i]
 *
 */
muriscv_nn_status muriscv_nn_mat_mul_core_1x_s8(int32_t row_elements,
                                                const int8_t *row_base,
                                                const int8_t *col_base,
                                                int32_t *const sum_col,
                                                int32_t *const output);

/**
 * @brief General Vector by Matrix multiplication with requantization, storage of result and int4 weights packed into an
 * int8 buffer.
 * @param[in]       row_elements          number of row elements
 * @param[in]       skipped_row_elements  number of row elements skipped due to padding.
 *                                        row_elements + skipped_row_elements = (kernel_x * kernel_y) * input_ch
 * @param[in]       row_base_ref          pointer to row operand
 * @param[in]       col_base_ref          pointer to col operand as packed int4
 * @param[out]      out_ch                Number of output channels
 * @param[in]       conv_params           Pointer to convolution parameters like offsets and activation values
 * @param[in]       quant_params          Pointer to per-channel quantization parameters
 * @param[in]       bias                  Pointer to optional per-channel bias
 * @param[out]      output                Pointer to output where int8 results are stored.
 * @return     The function performs matrix(row_base_ref) multiplication with vector(col_base_ref) and
 *             scaled result is stored in memory.
 *
 * @details Pseudo-code as int8 example. Int4 filter data will be unpacked.
 *      *output = 0
 *      sum_col = 0
 *      for (j = 0; j < out_ch; j++)
 *      for (i = 0; i < row_elements; i++)
 *          *output += row_base_ref[i] * col_base_ref[i]
 *          sum_col += col_base_ref[i]
 *      scale sum_col using quant_params and bias
 *      store result in 'output'
 *
 *
 */
muriscv_nn_status muriscv_nn_mat_mul_core_1x_s4(int32_t row_elements,
                                              const int32_t skipped_row_elements,
                                              const int8_t *row_base_ref,
                                              const int8_t *col_base_ref,
                                              const int32_t out_ch,
                                              const muriscv_nn_conv_params *conv_params,
                                              const muriscv_nn_per_channel_quant_params *quant_params,
                                              const int32_t *bias,
                                              int8_t *output);

/**
 * @brief Matrix-multiplication with requantization & activation function for four rows and one column
 * @param[in]       row_elements  number of row elements
 * @param[in]       offset        offset between rows. Can be the same as row_elements.
 *                                For e.g, in a 1x1 conv scenario with stride as 1.
 * @param[in]       row_base      pointer to row operand
 * @param[in]       col_base      pointer to col operand
 * @param[in]       out_ch        Number of output channels
 * @param[in]       conv_params   Pointer to convolution parameters like offsets and activation values
 * @param[in]       quant_params  Pointer to per-channel quantization parameters
 * @param[in]       bias          Pointer to per-channel bias
 * @param[out]      output        Pointer to output where int8 results are stored.
 *
 * @return     The function returns the updated output pointer or NULL if implementation is not available.
 *
 * @details Compliant to TFLM int8 specification. MVE implementation only
 */
int8_t *muriscv_nn_mat_mul_core_4x_s8(const int32_t row_elements,
                                  const int32_t offset,
                                  const int8_t *row_base,
                                  const int8_t *col_base,
                                  const int32_t out_ch,
                                  const muriscv_nn_conv_params *conv_params,
                                  const muriscv_nn_per_channel_quant_params *quant_params,
                                  const int32_t *bias,
                                  int8_t *output);

/**
 * @brief General Matrix-multiplication function with per-channel requantization.
 *        This function assumes:
 *        - LHS input matrix NOT transposed (nt)
 *        - RHS input matrix transposed (t)
 *        - RHS is int8 packed with 2x int4
 *        - LHS is int8
 *
 *  @note This operation also performs the broadcast bias addition before the requantization
 *
 * @param[in]  lhs                Pointer to the LHS input matrix
 * @param[in]  rhs                Pointer to the RHS input matrix
 * @param[in]  bias               Pointer to the bias vector. The length of this vector is equal to the number of
 *                                output columns (or RHS input rows)
 * @param[out] dst                Pointer to the output matrix with "m" rows and "n" columns
 * @param[in]  dst_multipliers    Pointer to the multipliers vector needed for the per-channel requantization.
 *                                The length of this vector is equal to the number of output columns (or RHS input
 *                                rows)
 * @param[in]  dst_shifts         Pointer to the shifts vector needed for the per-channel requantization. The length
 *                                of this vector is equal to the number of output columns (or RHS input rows)
 * @param[in]  lhs_rows           Number of LHS input rows
 * @param[in]  rhs_rows           Number of RHS input rows
 * @param[in]  rhs_cols           Number of LHS/RHS input columns
 * @param[in]  lhs_offset         Offset to be applied to the LHS input value
 * @param[in]  dst_offset         Offset to be applied the output result
 * @param[in]  activation_min     Minimum value to clamp down the output. Range : int8
 * @param[in]  activation_max     Maximum value to clamp up the output. Range : int8
 * @param[in]  lhs_cols_offset    Column offset between subsequent lhs_rows
 *
 * @return     The function returns <code>MURISCV_NN_SUCCESS</code>
 *
 */
muriscv_nn_status muriscv_nn_mat_mult_nt_t_s4(const int8_t *lhs,
                                            const int8_t *rhs,
                                            const int32_t *bias,
                                            int8_t *dst,
                                            const int32_t *dst_multipliers,
                                            const int32_t *dst_shifts,
                                            const int32_t lhs_rows,
                                            const int32_t rhs_rows,
                                            const int32_t rhs_cols,
                                            const int32_t lhs_offset,
                                            const int32_t dst_offset,
                                            const int32_t activation_min,
                                            const int32_t activation_max,
                                            const int32_t lhs_cols_offset);

/**
 * @brief General Matrix-multiplication function with per-channel requantization.
 *        This function assumes:
 *        - LHS input matrix NOT transposed (nt)
 *        - RHS input matrix transposed (t)
 *
 *  @note This operation also performs the broadcast bias addition before the requantization
 *
 * @param[in]  lhs                Pointer to the LHS input matrix
 * @param[in]  rhs                Pointer to the RHS input matrix
 * @param[in]  bias               Pointer to the bias vector. The length of this vector is equal to the number of
 *                                output columns (or RHS input rows)
 * @param[out] dst                Pointer to the output matrix with "m" rows and "n" columns
 * @param[in]  dst_multipliers    Pointer to the multipliers vector needed for the per-channel requantization.
 *                                The length of this vector is equal to the number of output columns (or RHS input
 *                                rows)
 * @param[in]  dst_shifts         Pointer to the shifts vector needed for the per-channel requantization. The length
 *                                of this vector is equal to the number of output columns (or RHS input rows)
 * @param[in]  lhs_rows           Number of LHS input rows
 * @param[in]  rhs_rows           Number of RHS input rows
 * @param[in]  rhs_cols           Number of LHS/RHS input columns
 * @param[in]  lhs_offset         Offset to be applied to the LHS input value
 * @param[in]  dst_offset         Offset to be applied the output result
 * @param[in]  activation_min     Minimum value to clamp down the output. Range : int8
 * @param[in]  activation_max     Maximum value to clamp up the output. Range : int8
 * @param[in]  row_address_offset Address offset between rows in output. NOTE: Only used for MVEI extension.
 * @param[in]  lhs_cols_offset    Column offset between subsequent lhs_rows
 *
 * @return     The function returns <code>MURISCV_NN_SUCCESS</code>
 *
 */
muriscv_nn_status muriscv_nn_mat_mult_nt_t_s8(const int8_t *lhs,
                                            const int8_t *rhs,
                                            const int32_t *bias,
                                            int8_t *dst,
                                            const int32_t *dst_multipliers,
                                            const int32_t *dst_shifts,
                                            const int32_t lhs_rows,
                                            const int32_t rhs_rows,
                                            const int32_t rhs_cols,
                                            const int32_t lhs_offset,
                                            const int32_t dst_offset,
                                            const int32_t activation_min,
                                            const int32_t activation_max,
                                            const int32_t row_address_offset,
                                            const int32_t lhs_cols_offset);

/**
 * @brief General Matrix-multiplication function with per-channel requantization and int16 input (LHS) and output.
 *        This function assumes:
 *        - LHS input matrix NOT transposed (nt)
 *        - RHS input matrix transposed (t)
 *
 *  @note This operation also performs the broadcast bias addition before the requantization
 *
 * @param[in]  lhs                Pointer to the LHS input matrix
 * @param[in]  rhs                Pointer to the RHS input matrix
 * @param[in]  bias               Pointer to the bias vector. The length of this vector is equal to the number of
 *                                output columns (or RHS input rows)
 * @param[out] dst                Pointer to the output matrix with "m" rows and "n" columns
 * @param[in]  dst_multipliers    Pointer to the multipliers vector needed for the per-channel requantization.
 *                                The length of this vector is equal to the number of output columns (or RHS input
 *                                rows)
 * @param[in]  dst_shifts         Pointer to the shifts vector needed for the per-channel requantization. The length
 *                                of this vector is equal to the number of output columns (or RHS input rows)
 * @param[in]  lhs_rows           Number of LHS input rows
 * @param[in]  rhs_rows           Number of RHS input rows
 * @param[in]  rhs_cols           Number of LHS/RHS input columns
 * @param[in]  activation_min     Minimum value to clamp down the output. Range : int16
 * @param[in]  activation_max     Maximum value to clamp up the output. Range : int16
 *
 * @details MVE implementation only.
 *
 * @return     The function returns <code>MURISCV_NN_SUCCESS</code> or
 *                                  <code>MURISCV_NN_NO_IMPL_ERROR</code> if not for MVE
 *
 */
muriscv_nn_status muriscv_nn_mat_mult_nt_t_s16(const int16_t *lhs,
                                             const int8_t *rhs,
                                             const int64_t *bias,
                                             int16_t *dst,
                                             const int32_t *dst_multipliers,
                                             const int32_t *dst_shifts,
                                             const int32_t lhs_rows,
                                             const int32_t rhs_rows,
                                             const int32_t rhs_cols,
                                             const int32_t activation_min,
                                             const int32_t activation_max);

/**
 * @brief General Matrix-multiplication function with int8 input and int32 output.
 *        This function assumes:
 *        - LHS input matrix NOT transposed (nt)
 *        - RHS input matrix transposed (t)
 *
 * @note  Dst/output buffer must be zeroed out before calling this function.
 *
 * @param[in]  lhs                Pointer to the LHS input matrix
 * @param[in]  rhs                Pointer to the RHS input matrix
 * @param[out] dst                Pointer to the output matrix with "m" rows and "n" columns
 * @param[in]  lhs_rows           Number of LHS input rows
 * @param[in]  rhs_rows           Number of LHS input columns/RHS input rows
 * @param[in]  rhs_cols           Number of RHS input columns
 * @param[in]  lhs_offset         Offset to be applied to the LHS input value
 * @param[in]  dst_idx_offset     Offset between subsequent output results
 *
 * @return     The function returns <code>MURISCV_NN_SUCCESS</code>
 *
 */
muriscv_nn_status muriscv_nn_mat_mult_nt_t_s8_s32(const int8_t *lhs,
                                                const int8_t *rhs,
                                                int32_t *dst,
                                                const int32_t lhs_rows,
                                                const int32_t rhs_rows,
                                                const int32_t rhs_cols,
                                                const int32_t lhs_offset,
                                                const int32_t dst_idx_offset);

/**
 * @brief s4 Vector by Matrix (transposed) multiplication
 *
 * @param[in]      lhs             Input left-hand side vector
 * @param[in]      packed_rhs      Input right-hand side matrix (transposed)
 * @param[in]      bias            Input bias
 * @param[out]     dst             Output vector
 * @param[in]      lhs_offset      Offset to be added to the input values of the left-hand side vector.
 *                                 Range: -127 to 128
 * @param[in]      dst_offset      Offset to be added to the output values. Range: -127 to 128
 * @param[in]      dst_multiplier  Output multiplier
 * @param[in]      dst_shift       Output shift
 * @param[in]      rhs_cols        Number of columns in the right-hand side input matrix
 * @param[in]      rhs_rows        Number of rows in the right-hand side input matrix
 * @param[in]      activation_min  Minimum value to clamp the output to. Range: int8
 * @param[in]      activation_max  Maximum value to clamp the output to. Range: int8
 * @param[in]      address_offset  Memory position offset for dst. First output is stored at 'dst', the
 *                                 second at 'dst + address_offset' and so on. Default value is typically 1.
 *
 * @return         The function returns <code>MURISCV_NN_SUCCESS</code>
 *
 */
muriscv_nn_status muriscv_nn_vec_mat_mult_t_s4(const int8_t *lhs,
                                             const int8_t *packed_rhs,
                                             const int32_t *bias,
                                             int8_t *dst,
                                             const int32_t lhs_offset,
                                             const int32_t dst_offset,
                                             const int32_t dst_multiplier,
                                             const int32_t dst_shift,
                                             const int32_t rhs_cols,
                                             const int32_t rhs_rows,
                                             const int32_t activation_min,
                                             const int32_t activation_max,
                                             const int32_t address_offset);

/**
 * @brief s8 Vector by Matrix (transposed) multiplication
 *
 * @param[in]      lhs             Input left-hand side vector
 * @param[in]      rhs             Input right-hand side matrix (transposed)
 * @param[in]      kernel_sum      Kernel sums of the kernels (rhs). See muriscv_nn_vector_sum_s8 for more info.
 * @param[in]      bias            Input bias
 * @param[out]     dst             Output vector
 * @param[in]      lhs_offset      Offset to be added to the input values of the left-hand side vector.
 *                                 Range: -127 to 128
 * @param[in]      dst_offset      Offset to be added to the output values. Range: -127 to 128
 * @param[in]      dst_multiplier  Output multiplier
 * @param[in]      dst_shift       Output shift
 * @param[in]      rhs_cols        Number of columns in the right-hand side input matrix
 * @param[in]      rhs_rows        Number of rows in the right-hand side input matrix
 * @param[in]      activation_min  Minimum value to clamp the output to. Range: int8
 * @param[in]      activation_max  Maximum value to clamp the output to. Range: int8
 * @param[in]      address_offset  Memory position offset for dst. First output is stored at 'dst', the
 *                                 second at 'dst + address_offset' and so on. Default value is typically 1.
 * @param[in]      rhs_offset      Offset to be added to the input values of the right-hand side vector.
 *                                 Range: -127 to 128
 *
 * @return         The function returns <code>MURISCV_NN_SUCCESS</code>
 *
 */
muriscv_nn_status muriscv_nn_vec_mat_mult_t_s8(const int8_t *lhs,
                                             const int8_t *rhs,
                                             const int32_t *kernel_sum,
                                             const int32_t *bias,
                                             int8_t *dst,
                                             const int32_t lhs_offset,
                                             const int32_t dst_offset,
                                             const int32_t dst_multiplier,
                                             const int32_t dst_shift,
                                             const int32_t rhs_cols,
                                             const int32_t rhs_rows,
                                             const int32_t activation_min,
                                             const int32_t activation_max,
                                             const int32_t address_offset,
                                             const int32_t rhs_offset);

/**
 * @brief s16 Vector by Matrix (transposed) multiplication
 *
 * @param[in]      lhs             Input left-hand side vector
 * @param[in]      rhs             Input right-hand side matrix (transposed)
 * @param[in]      bias            Input bias
 * @param[out]     dst             Output vector
 * @param[in]      dst_multiplier  Output multiplier
 * @param[in]      dst_shift       Output shift
 * @param[in]      rhs_cols        Number of columns in the right-hand side input matrix
 * @param[in]      rhs_rows        Number of rows in the right-hand side input matrix
 * @param[in]      activation_min  Minimum value to clamp the output to. Range: int16
 * @param[in]      activation_max  Maximum value to clamp the output to. Range: int16
 *
 * @return         The function returns <code>MURISCV_NN_SUCCESS</code>
 *
 */
muriscv_nn_status muriscv_nn_vec_mat_mult_t_s16(const int16_t *lhs,
                                              const int8_t *rhs,
                                              const int64_t *bias,
                                              int16_t *dst,
                                              const int32_t dst_multiplier,
                                              const int32_t dst_shift,
                                              const int32_t rhs_cols,
                                              const int32_t rhs_rows,
                                              const int32_t activation_min,
                                              const int32_t activation_max);

/**
 * @brief s8 Vector by Matrix (transposed) multiplication with s16 output
 *
 * @param[in]      lhs             Input left-hand side vector
 * @param[in]      rhs             Input right-hand side matrix (transposed)
 * @param[out]     dst             Output vector
 * @param[in]      lhs_offset      Offset to be added to the input values of the left-hand side
 *                                 vector. Range: -127 to 128
 * @param[in]      scatter_offset  Address offset for dst. First output is stored at 'dst', the
 *                                 second at 'dst + scatter_offset' and so on.
 * @param[in]      dst_multiplier  Output multiplier
 * @param[in]      dst_shift       Output shift
 * @param[in]      rhs_cols        Number of columns in the right-hand side input matrix
 * @param[in]      rhs_rows        Number of rows in the right-hand side input matrix
 * @param[in]      activation_min  Minimum value to clamp the output to. Range: int16
 * @param[in]      activation_max  Maximum value to clamp the output to. Range: int16
 *
 * @return         The function returns <code>MURISCV_NN_SUCCESS</code>
 *
 */
muriscv_nn_status muriscv_nn_vec_mat_mult_t_svdf_s8(const int8_t *lhs,
                                                  const int8_t *rhs,
                                                  int16_t *dst,
                                                  const int32_t lhs_offset,
                                                  const int32_t scatter_offset,
                                                  const int32_t dst_multiplier,
                                                  const int32_t dst_shift,
                                                  const int32_t rhs_cols,
                                                  const int32_t rhs_rows,
                                                  const int32_t activation_min,
                                                  const int32_t activation_max);

/**
 * @brief Depthwise convolution of transposed rhs matrix with 4 lhs matrices. To be used in padded cases where
 *        the padding is -lhs_offset(Range: int8). Dimensions are the same for lhs and rhs.
 *
 * @param[in]      lhs             Input left-hand side matrix
 * @param[in]      rhs             Input right-hand side matrix (transposed)
 * @param[in]      lhs_offset      LHS matrix offset(input offset). Range: -127 to 128
 * @param[in]      active_ch       Subset of total_ch processed
 * @param[in]      total_ch        Number of channels in LHS/RHS
 * @param[in]      out_shift       Per channel output shift. Length of vector is equal to number of channels
 * @param[in]      out_mult        Per channel output multiplier. Length of vector is equal to number of channels
 * @param[in]      out_offset      Offset to be added to the output values. Range: -127 to 128
 * @param[in]      activation_min  Minimum value to clamp the output to. Range: int8
 * @param[in]      activation_max  Maximum value to clamp the output to. Range: int8
 * @param[in]       row_x_col       (row_dimension * col_dimension) of LHS/RHS matrix
 * @param[in]      output_bias     Per channel output bias. Length of vector is equal to number of channels
 * @param[in]      out             Output pointer
 *
 * @return         The function returns one of the two
 *                  - Updated output pointer if an implementation is available
 *                  - NULL if no implementation is available.
 *
 * @note           If number of channels is not a multiple of 4, upto 3 elements outside the boundary will be read
 * out for the following.
 *                  - Output shift
 *                  - Output multiplier
 *                  - Output bias
 *                  - rhs
 */
muriscv_nn_status muriscv_nn_depthwise_conv_nt_t_padded_s8(const int8_t *lhs,
                                                         const int8_t *rhs,
                                                         const int32_t lhs_offset,
                                                         const int32_t active_ch,
                                                         const int32_t total_ch,
                                                         const int32_t *out_shift,
                                                         const int32_t *out_mult,
                                                         const int32_t out_offset,
                                                         const int32_t activation_min,
                                                         const int32_t activation_max,
                                                         const uint16_t row_x_col,
                                                         const int32_t *const output_bias,
                                                         int8_t *out);

/**
 * @brief Depthwise convolution of transposed rhs matrix with 4 lhs matrices. To be used in non-padded cases.
 *        Dimensions are the same for lhs and rhs.
 *
 * @param[in]      lhs             Input left-hand side matrix
 * @param[in]      rhs             Input right-hand side matrix (transposed)
 * @param[in]      lhs_offset      LHS matrix offset(input offset). Range: -127 to 128
 * @param[in]      active_ch       Subset of total_ch processed
 * @param[in]      total_ch        Number of channels in LHS/RHS
 * @param[in]      out_shift       Per channel output shift. Length of vector is equal to number of channels.
 * @param[in]      out_mult        Per channel output multiplier. Length of vector is equal to number of channels.
 * @param[in]      out_offset      Offset to be added to the output values. Range: -127 to 128
 * @param[in]      activation_min  Minimum value to clamp the output to. Range: int8
 * @param[in]      activation_max  Maximum value to clamp the output to. Range: int8
 * @param[in]       row_x_col       (row_dimension * col_dimension) of LHS/RHS matrix
 * @param[in]      output_bias     Per channel output bias. Length of vector is equal to number of channels.
 * @param[in]      out             Output pointer
 *
 * @return         The function returns one of the two
 *                  - Updated output pointer if an implementation is available
 *                  - NULL if no implementation is available.
 *
 * @note           If number of channels is not a multiple of 4, upto 3 elements outside the boundary will be read
 * out for the following.
 *                  - Output shift
 *                  - Output multiplier
 *                  - Output bias
 *                  - rhs
 */
muriscv_nn_status muriscv_nn_depthwise_conv_nt_t_s8(const int8_t *lhs,
                                                  const int8_t *rhs,
                                                  const int32_t lhs_offset,
                                                  const int32_t active_ch,
                                                  const int32_t total_ch,
                                                  const int32_t *out_shift,
                                                  const int32_t *out_mult,
                                                  const int32_t out_offset,
                                                  const int32_t activation_min,
                                                  const int32_t activation_max,
                                                  const uint16_t row_x_col,
                                                  const int32_t *const output_bias,
                                                  int8_t *out);

/**
 * @brief Depthwise convolution of transposed rhs matrix with 4 lhs matrices. To be used in non-padded cases.
 *        Dimensions are the same for lhs and rhs.
 *
 * @param[in]      lhs             Input left-hand side matrix
 * @param[in]      rhs             Input right-hand side matrix (transposed)
 * @param[in]      num_ch          Number of channels in LHS/RHS
 * @param[in]      out_shift       Per channel output shift. Length of vector is equal to number of channels.
 * @param[in]      out_mult        Per channel output multiplier. Length of vector is equal to number of channels.
 * @param[in]      activation_min  Minimum value to clamp the output to. Range: int8
 * @param[in]      activation_max  Maximum value to clamp the output to. Range: int8
 * @param[in]       row_x_col       (row_dimension * col_dimension) of LHS/RHS matrix
 * @param[in]      output_bias     Per channel output bias. Length of vector is equal to number of channels.
 * @param[in]      out             Output pointer
 *
 * @return         The function returns one of the two
 *                  - Updated output pointer if an implementation is available
 *                  - NULL if no implementation is available.
 *
 * @note           If number of channels is not a multiple of 4, upto 3 elements outside the boundary will be read
 * out for the following.
 *                  - Output shift
 *                  - Output multiplier
 *                  - Output bias
 *                  - rhs
 */
int16_t *muriscv_nn_depthwise_conv_nt_t_s16(const int16_t *lhs,
                                        const int8_t *rhs,
                                        const uint16_t num_ch,
                                        const int32_t *out_shift,
                                        const int32_t *out_mult,
                                        const int32_t activation_min,
                                        const int32_t activation_max,
                                        const uint16_t row_x_col,
                                        const int64_t *const output_bias,
                                        int16_t *out);

/**
  @brief         Read 2 s16 elements and post increment pointer.
  @param[in]     in_q15   Pointer to pointer that holds address of input.
  @return        q31 value
 */
__STATIC_FORCEINLINE int32_t muriscv_nn_read_q15x2_ia(const int16_t **in_q15)
{
    int32_t val;

    memcpy(&val, *in_q15, 4);
    *in_q15 += 2;

    return (val);
}

/**
  @brief         Read 4 s8 from s8 pointer and post increment pointer.
  @param[in]     in_s8       Pointer to pointer that holds address of input.
  @return        q31 value
 */
__STATIC_FORCEINLINE int32_t muriscv_nn_read_s8x4_ia(const int8_t **in_s8)
{
    int32_t val;
    memcpy(&val, *in_s8, 4);
    *in_s8 += 4;

    return (val);
}

/**
  @brief         Read 2 s8 from s8 pointer and post increment pointer.
  @param[in]     in_s8    Pointer to pointer that holds address of input.
  @return        q31      value
 */
__STATIC_FORCEINLINE int32_t muriscv_nn_read_s8x2_ia(const int8_t **in_s8)
{
    int32_t val;
    memcpy(&val, *in_s8, 2);
    *in_s8 += 2;

    return (val);
}

/**
  @brief         Read 2 int16 values from int16 pointer.
  @param[in]     in     pointer to address of input.
  @return        s32    value
 */
__STATIC_FORCEINLINE int32_t muriscv_nn_read_s16x2(const int16_t *in)
{
    int32_t val;
    memcpy(&val, in, 4);

    return (val);
}

/**
  @brief         Read 4 s8 values.
  @param[in]     in_s8       pointer to address of input.
  @return        s32 value
 */
__STATIC_FORCEINLINE int32_t muriscv_nn_read_s8x4(const int8_t *in_s8)
{
    int32_t val;
    memcpy(&val, in_s8, 4);

    return (val);
}
/**
  @brief         Read 2 s8 values.
  @param[in]     in_s8    pointer to address of input.
  @return        s32      value
 */
__STATIC_FORCEINLINE int32_t muriscv_nn_read_s8x2(const int8_t *in_s8)
{
    int32_t val;
    memcpy(&val, in_s8, 2);

    return (val);
}

/**
  @brief         Write four s8 to s8 pointer and increment pointer afterwards.
  @param[in]     in       Double pointer to input value
  @param[in]     value    Four bytes to copy
 */
__STATIC_FORCEINLINE void muriscv_nn_write_s8x4_ia(int8_t **in, int32_t value)
{
    memcpy(*in, &value, 4);
    *in += 4;
}

//MURISCV_NN NEW CODE
/**
 @brief         Read 2 q15 elements and post increment pointer. Always uses memcpy for read, consistent speed, regardless of alignment
 @param[in]     in_q15   Pointer to pointer that holds address of input.
 @return        q31 value
*/
static inline q31_t muriscv_nn_read_q15x2_ia_slow(const q15_t **in_q15)
{
    q31_t val;
    memcpy(&val, *in_q15, 4);
    *in_q15 += 2;

    return val;
}

/**
 @brief         Read 2 q15 elements and post increment pointer.  Performs best for word aligned reads, otherwise performs extremely slowly
 @param[in]     in_q15   Pointer to pointer that holds address of input.
 @return        q31 value
*/
static inline q31_t muriscv_nn_read_q15x2_ia_fast(const q15_t **in_q15)
{
    q31_t val;
    val = (*((uint32_t*)(*in_q15)));
    *in_q15 += 2;

    return val;
}
/**
 @brief         Read 2 q15 elements and post increment pointer.  Always performs read on word boundaries
 @param[in]     in_q15           Pointer to pointer that holds address of input.
 @param[in]     alignment        Number of q15 values away from word aligned boundary
 @return        q31 value
*/
static inline q31_t muriscv_nn_read_q15x2_ia_aligned(const q15_t **in_q15, const uint8_t alignment)
{
    q31_t val;
    if(alignment == 0)
    {
         val = (*((uint32_t*)(*in_q15)));       
    }
    else
    {
         val = (uint32_t)((*((uint64_t*)(*in_q15 - 1))) >> 16); 
    }
    *in_q15 += 2;

    return val;
}
/**
  @brief         Read 4 q7 from q7 pointer and post increment pointer.  Performs best for word aligned reads, otherwise performs extremely slowly
  @param[in]     in_q7       Pointer to pointer that holds address of input.
  @return        q31 value
 */
static inline q31_t muriscv_nn_read_q7x4_ia_fast(const q7_t **in_q7)
{
    q31_t val;
    val = (*((q31_t*)(*in_q7)));
    *in_q7 += 4;
    return val;
}
/**
  @brief         Read 4 q7 from q7 pointer and post increment pointer.  Always uses memcpy for read, consistent speed, regardless of alignment
  @param[in]     in_q7       Pointer to pointer that holds address of input.
  @return        q31 value
 */
static inline q31_t muriscv_nn_read_q7x4_ia_slow(const q7_t **in_q7)
{
    q31_t val;
    memcpy(&val, *in_q7, 4);
    *in_q7 += 4;
    return val;
}
/**
  @brief         Read 4 q7 from q7 pointer and post increment pointer.  Always performs read on memory word boundaries
  @param[in]     in_q7            Pointer to pointer that holds address of input.
  @param[in]     alignment        Number of q7 values away from word aligned boundary
  @param[in]     alignment_bits   Number of bits to shift to receive desired value, precalculated for efficency
  @return        q31 value
 */
static inline q31_t muriscv_nn_read_q7x4_ia_aligned(const q7_t **in_q7, const uint8_t alignment, const uint8_t alignment_bits)
{
    q31_t val;
    if (alignment == 0)
    {
        val = (*((q31_t*)(*in_q7)));
    }
    else
    {
        val = (uint32_t)((*((uint64_t*)(*in_q7 - alignment))) >> (alignment_bits));
    }
    *in_q7 += 4;
    return val;
}
/**
  @brief         Read 2 q15 from q15 pointer.
  @param[in]     in_q15   pointer to address of input.
  @return        q31 value
 */
static inline q31_t muriscv_nn_read_q15x2(const q15_t *in_q15)
{
    q31_t val;
    val = (*((uint32_t*)(in_q15)));
    return val;
}

/**
  @brief         Read 4 q7 values.
  @param[in]     in_q7       pointer to address of input.
  @return        q31 value
 */
static inline q31_t muriscv_nn_read_q7x4(const q7_t *in_q7)
{
    q31_t val;
    val = (*((uint32_t*)(in_q7)));

    return val;
}

/**
  @brief         Write four q7 to q7 pointer and increment pointer afterwards.
  @param[in]     in       Double pointer to input value
  @param[in]     value    Four bytes to copy
 */
static inline void muriscv_nn_write_q7x4_ia(q7_t **in, q31_t value)
{
    memcpy(*in, &value, 4);
    *in += 4;
}

/**
  @brief         Write four q7 to q7 pointer and increment pointer afterwards.
  @param[in]     in       Double pointer to input value
  @param[in]     value    Four bytes to copy
 */
static inline void muriscv_nn_write_q7x4(q7_t *in, q31_t value) { memcpy(in, &value, 4); }

/**
  @brief         Write four q7 to q7 pointer and increment pointer afterwards.
  @param[in]     in       Double pointer to input value
  @param[in]     value    Four bytes to copy
 */
static inline void muriscv_nn_write_q7x4_fast(q7_t *in, q31_t value) 
{
    *((uint32_t*)(in)) = value;
}
//MURISCV_NN END OF NEW CODE
//MURISCV_NN NEW CODE
#if defined(USE_VEXT)

// TODO(fabianpedd): Clean these muriscv_nn_requantize functions up and find a consitent naming scheme that respects
// types and vector/scalar arguments

/**
 * @brief           Requantize a given vector of values.
 * @param[in]       val         Vector of value to be requantized
 * @param[in]       multiplier  multiplier. Range {Q31_MIN + 1, Q32_MAX}
 * @param[in]       shift       left or right shift for 'val * multiplier'
 *
 * @return          Returns (val * multiplier)/(2 ^ shift) for every vector entry
 *
 */
static inline vint32m8_t
muriscv_nn_requantize_vec(const vint32m8_t val, const q31_t multiplier, const q31_t shift, size_t vl)
{
    // TODO(fabianpedd): implement MURISCV_NN_USE_SINGLE_ROUNDING

    vint32m8_t val_internal = vsmul_vx_i32m8(val, multiplier * (1 << LEFT_SHIFT(shift)), vl);

    // TODO(fabianpedd): close, but sometimes off by 1 bit.
    // in1_off = vssra_vx_i32m8(in1_off, RIGHT_SHIFT(input_1_shift), vl);

    const q31_t remainder_mask = (1 << RIGHT_SHIFT(shift)) - 1;
    vint32m8_t remainder = vand_vx_i32m8(val_internal, remainder_mask, vl);
    vint32m8_t threshold = vmv_v_x_i32m8(remainder_mask >> 1, vl);

    val_internal = vsra_vx_i32m8(val_internal, RIGHT_SHIFT(shift), vl);

    vbool4_t mask = vmslt_vx_i32m8_b4(val_internal, 0, vl);
    threshold = vadd_vx_i32m8_m(mask, threshold, threshold, 1, vl);

    mask = vmsgt_vv_i32m8_b4(remainder, threshold, vl);
    val_internal = vadd_vx_i32m8_m(mask, val_internal, val_internal, 1, vl);

    return val_internal;
}

static inline vint32m4_t
muriscv_nn_requantize_vint32m4(const vint32m4_t val, const q31_t multiplier, const q31_t shift, size_t vl)
{
    // TODO(fabianpedd): implement MURISCV_NN_USE_SINGLE_ROUNDING

    vint32m4_t val_internal = vsmul_vx_i32m4(val, multiplier * (1 << LEFT_SHIFT(shift)), vl);

    // TODO(fabianpedd): close, but sometimes off by 1 bit.
    // in1_off = vssra_vx_i32m4(in1_off, RIGHT_SHIFT(input_1_shift), vl);

    const q31_t remainder_mask = (1 << RIGHT_SHIFT(shift)) - 1;
    vint32m4_t remainder = vand_vx_i32m4(val_internal, remainder_mask, vl);
    vint32m4_t threshold = vmv_v_x_i32m4(remainder_mask >> 1, vl);

    val_internal = vsra_vx_i32m4(val_internal, RIGHT_SHIFT(shift), vl);

    vbool8_t mask = vmslt_vx_i32m4_b8(val_internal, 0, vl);
    threshold = vadd_vx_i32m4_m(mask, threshold, threshold, 1, vl);

    mask = vmsgt_vv_i32m4_b8(remainder, threshold, vl);
    val_internal = vadd_vx_i32m4_m(mask, val_internal, val_internal, 1, vl);

    return val_internal;
}

static inline vint32m2_t
muriscv_nn_requantize_vint32m2(vint32m2_t val, vint32m2_t multiplier, vint32m2_t shift, size_t vl)
{
    // TODO(fabianpedd): implement MURISCV_NN_USE_SINGLE_ROUNDING

    // shift = -shift;
    vuint32m2_t u_shift = vreinterpret_v_i32m2_u32m2(vneg_v_i32m2(shift, vl));

    // int32_t dividend = (int32_t)(((int64_t)multiplier * val + (1 << 30)) >> 31);
    vint32m2_t dividend = vsmul_vv_i32m2(val, multiplier, vl);

    // int32_t result = dividend >> shift;
    vint32m2_t result = vsra_vv_i32m2(dividend, u_shift, vl);

    // int32_t remainder_mask = (1 << shift) - 1;
    vint32m2_t remainder_mask = vsub_vx_i32m2(vsll_vv_i32m2(vmv_v_x_i32m2(1, vl), u_shift, vl), 1, vl);

    // int32_t threshold = remainder_mask >> 1;
    vint32m2_t threshold = vsra_vx_i32m2(remainder_mask, 1, vl);

    // if (result < 0) threshold++;
    vbool16_t mask = vmslt_vx_i32m2_b16(result, 0, vl);
    threshold = vadd_vx_i32m2_m(mask, threshold, threshold, 1, vl);

    // int32_t remainder = remainder_mask & dividend;
    vint32m2_t remainder = vand_vv_i32m2(remainder_mask, dividend, vl);

    // if (remainder > threshold) result++;
    mask = vmsgt_vv_i32m2_b16(remainder, threshold, vl);
    result = vadd_vx_i32m2_m(mask, result, result, 1, vl);

    return result;
}
#endif
//MURISCV_NN END OF NEW CODE
//MURISCV_NN NEW CODE
/**
 * @brief           memcpy optimized for RVV
 * @param[in, out]  dst         Destination pointer
 * @param[in]       src         Source pointer
 * @param[in]       block_size  Number of bytes to copy
 *
 */
static inline void muriscv_nn_memcpy(int8_t *dst, const int8_t *src, size_t block_size)
{
#if defined(USE_VEXT)
    for (size_t vl; block_size > 0; block_size -= vl, src += vl, dst += vl)
    {
        vl = vsetvl_e8m8(block_size);
        vint8m8_t vec_src = vle8_v_i8m8(src, vl);
        vse8_v_i8m8(dst, vec_src, vl);
    }
#else
    memcpy(dst, src, block_size);
#endif
}

/**
 * @brief           memset optimized for RVV
 * @param[in, out]  dst         Destination pointer
 * @param[in]       src         Value to set
 * @param[in]       block_size  Number of bytes to set
 *
 */
static inline void muriscv_nn_memset(int8_t *dst, const int8_t val, size_t block_size)
{
#if defined(USE_VEXT)
    for (size_t vl; block_size > 0; block_size -= vl, dst += vl)
    {
        vl = vsetvl_e8m8(block_size);
        vint8m8_t vec_src = vmv_v_x_i8m8(val, vl);
        vse8_v_i8m8(dst, vec_src, vl);
    }
#else
    memset(dst, val, block_size);
#endif
}
//MURISCV_NN END OF NEW CODE
//MURISCV_NN CUSTOM CODE
/**
 * @brief           memset optimized for MVE TODO: update for RISCV-VEXT
 * @param[in, out]  dst         Destination pointer
 * @param[in]       val         Value to set
 * @param[in]       block_size  Number of bytes to copy.
 *
 */
__STATIC_FORCEINLINE void muriscv_nn_memset_s8(int8_t *dst, const int8_t val, uint32_t block_size)  //supposed to be __STATIC_FORCEINLINE, TODO:
{
/*#if defined(ARM_MATH_MVEI)
    __asm volatile("   vdup.8                  q0, %[set_val]             \n"
                   "   wlstp.8                 lr, %[cnt], 1f             \n"
                   "2:                                                    \n"
                   "   vstrb.8                 q0, [%[in]], #16            \n"
                   "   letp                    lr, 2b                     \n"
                   "1:                                                    \n"
                   : [in] "+r"(dst)
                   : [cnt] "r"(block_size), [set_val] "r"(val)
                   : "q0", "memory", "r14");
#else*/
    memset(dst, val, block_size);
//#endif
}

#if defined(USE_PEXT)

//MURISCV_NN CUSTOM CODE
/**
 * @brief read and expand one s4 word into two s8 words.
 */
__STATIC_FORCEINLINE void read_and_pad_s4(const int8_t *source, int32_t *out1, int32_t *out2)
{
    //UNIMP FOR RISCV
    int16_t in = muriscv_nn_read_s8x2(source);
    int32_t inA = (in & 0x00FF) | ((in & 0xFF00) << 8);

    //*out1 = SXTB16_RORn(__sxtb16(inA << 4), 4);
    //*out2 = SXTB16_RORn(__sxtb16(inA), 4);
    out1 = NULL;
    out2 = NULL;
}

//MURISCV_NN CUSTOM CODE
/**
 * @brief read and expand one s4 word into two s8 words.
 * @details   The s4 elements are not evenly aligned on the byte boundary, so 3 bytes need to be read instead of 2.
 *            In other words first nibble to read start at the middle of a byte.
 *            byte index, s4 element
 *            0,          s4_x
 *            0,          s4_0
 *            1,          s4_1
 *            1,          s4_2
 *            2,          s4_3
 *            2,          s4_x
 */
__STATIC_FORCEINLINE void read_and_pad_s4_uneven(const int8_t *source, int32_t *out1, int32_t *out2)
{
    //UNIMP FOR RISCV
    int32_t inA1 = (source[0] & 0xFF) | ((source[1] & 0xFF) << 16);
    int32_t inA2 = (source[1] & 0xFF) | ((source[2] & 0xFF) << 16);

    //*out1 = SXTB16_RORn(__sxtb16(inA2 << 4), 4);
    //*out2 = SXTB16_RORn(__sxtb16(inA1), 4);
    out1 = NULL;
    out2 = NULL;
    
}

//MURISCV_NN CUSTOM CODE
/**
 * @brief read and expand one s4 word into two s16 words with ordering.
 */
__STATIC_FORCEINLINE void read_and_pad_s4_ordered(const int8_t *source, int32_t *out1, int32_t *out2)
{
    //UNIMP FOR RISCV
    int16_t in = muriscv_nn_read_s8x2(source);
    int32_t inA = (in & 0x00FF) | ((in & 0xFF00) << 8);
    //int32_t inAbuf1 = SXTB16_RORn(__sxtb16(inA), 4);
    //int32_t inAbuf2 = SXTB16_RORn(__sxtb16(inA << 4), 4);
    #ifndef ARM_MATH_BIG_ENDIAN
    //*out2 = (int32_t)(PKHTB(inAbuf1, inAbuf2, 16));
    //*out1 = (int32_t)(PKHBT(inAbuf2, inAbuf1, 16));
    #else
    //*out1 = (int32_t)(PKHTB(inAbuf1, inAbuf2, 16));
    //*out2 = (int32_t)(PKHBT(inAbuf2, inAbuf1, 16));
    #endif
    out1 = NULL;
    out2 = NULL;
    
}

//MURISCV_NN CUSTOM CODE
/**
 * @brief read and expand one s8 word into two s16 words with ordering.
 */
__STATIC_FORCEINLINE const int8_t *read_and_pad(const int8_t *source, int32_t *out1, int32_t *out2)
{
    //UNIMP FOR RISCV
    int32_t inA = muriscv_nn_read_s8x4_ia(&source);
    //int32_t inAbuf1 = SXTB16_RORn((uint32_t)inA, 8);
    //int32_t inAbuf2 = SXTB16(inA);

    #ifndef ARM_MATH_BIG_ENDIAN
    //*out2 = (int32_t)(PKHTB(inAbuf1, inAbuf2, 16));
    //*out1 = (int32_t)(PKHBT(inAbuf2, inAbuf1, 16));
    #else
    //*out1 = (int32_t)(PKHTB(inAbuf1, inAbuf2, 16));
    //*out2 = (int32_t)(PKHBT(inAbuf2, inAbuf1, 16));
    #endif
    out1 = NULL;
    out2 = NULL;

    return source;
}

//MURISCV_NN CUSTOM CODE
/**
 * @brief read and expand one s8 word into two s16 words with ordering and addition.
 */
__STATIC_FORCEINLINE void read_pad_and_add_s8(const int8_t *source, int32_t *out1, int32_t *out2, const uint32_t add)
{
    //UNIMP FOR RISCV
    int32_t inA = muriscv_nn_read_s8x4(source);
    //int32_t inAbuf1 = SXTAB16_RORn(add, (uint32_t)inA, 8);
    //int32_t inAbuf2 = SXTAB16(add, inA);

    #ifndef ARM_MATH_BIG_ENDIAN
    //*out2 = (int32_t)(PKHTB(inAbuf1, inAbuf2, 16));
    //*out1 = (int32_t)(PKHBT(inAbuf2, inAbuf1, 16));
    #else
    //*out1 = (int32_t)(PKHTB(inAbuf1, inAbuf2, 16));
    //*out2 = (int32_t)(PKHBT(inAbuf2, inAbuf1, 16));
    #endif
    out1 = NULL;
    out2 = NULL;
}

//MURISCV_NN CUSTOM CODE
/**
 * @brief read and expand two bytes into one word with ordering.
 */
__STATIC_FORCEINLINE void read_and_pad_s8x2(const int8_t *source, int32_t *out)
{
    //UNIMP FOR RISCV
    int16_t in = muriscv_nn_read_s8x2(source);
    int32_t inA = (in & 0x00FF) | ((in & 0xFF00) << 8);
    //*out = SXTB16(inA);
    out = NULL;
}

//MURISCV_NN CUSTOM CODE
/**
 * @brief read and expand two bytes into one word with ordering and addition.
 */
__STATIC_FORCEINLINE void read_pad_and_add_s8x2(const int8_t *source, int32_t *out, const uint32_t add)
{
    //UNIMP FOR RISCV
    int16_t in = muriscv_nn_read_s8x2(source);
    int32_t inA = (in & 0x00FF) | ((in & 0xFF00) << 8);
    //*out = SXTAB16(add, inA);
    out = NULL;
}

//MURISCV_NN CUSTOM CODE
/**
 * @brief read and expand one s8 word into two s16 words with no additional ordering.
 */
__STATIC_FORCEINLINE const int8_t *read_and_pad_reordered(const int8_t *source, int32_t *out1, int32_t *out2)
{
    //UNIMP FOR RISCV
    int32_t inA = muriscv_nn_read_s8x4_ia(&source);
    #ifndef ARM_MATH_BIG_ENDIAN
    //*out2 = SXTB16(ROR((uint32_t)inA, 8));
    //*out1 = SXTB16(inA);
    #else
    //*out1 = SXTB16(ROR((uint32_t)inA, 8));
    //*out2 = SXTB16(inA);
    #endif
    out1 = NULL;
    out2 = NULL;

    return source;
}

#endif

/**
 * @brief Matrix-multiplication function for convolution with per-channel requantization and 4 bit weights.
 * @param[in]       input_a            pointer to operand A, int8 packed with 2x int4.
 * @param[in]       input_b            pointer to operand B, always consists of 2 vectors.
 * @param[in]       output_ch          number of rows of A
 * @param[in]       out_shift          pointer to per output channel requantization shift parameter.
 * @param[in]       out_mult           pointer to per output channel requantization multiplier parameter.
 * @param[in]       out_offset         output tensor offset.
 * @param[in]       activation_min     minimum value to clamp the output to. Range : int8
 * @param[in]       activation_max     maximum value to clamp the output to. Range : int8
 * @param[in]       num_col_a          number of columns of A
 * @param[in]       output_bias        per output channel bias. Range : int32
 * @param[in,out]   out_0              pointer to output
 * @return     The function returns one of the two
 *              1. The incremented output pointer for a successful operation or
 *              2. NULL if implementation is not available.
 *
 * @details   This function does the matrix multiplication of weight matrix for all output channels
 *            with 2 columns from im2col and produces two elements/output_channel. The outputs are
 *            clamped in the range provided by activation min and max.
 *            Supported framework: TensorFlow Lite micro.
 */
int8_t *muriscv_nn_mat_mult_kernel_s4_s16(const int8_t *input_a,
                                      const int16_t *input_b,
                                      const uint16_t output_ch,
                                      const int32_t *out_shift,
                                      const int32_t *out_mult,
                                      const int32_t out_offset,
                                      const int32_t activation_min,
                                      const int32_t activation_max,
                                      const int32_t num_col_a,
                                      const int32_t *const output_bias,
                                      int8_t *out_0);
//MURISCV_NN CUSTOM CODE
/**
 * @brief Matrix-multiplication function for convolution with per-channel requantization.
 * @param[in]       input_a     pointer to operand A
 * @param[in]       input_b     pointer to operand B, always consists of 2 vectors.
 * @param[in]       output_ch   number of rows of A
 * @param[in]       out_shift  pointer to per output channel requantization shift parameter.
 * @param[in]       out_mult   pointer to per output channel requantization multiplier parameter.
 * @param[in]       out_offset      output tensor offset.
 * @param[in]       activation_min   minimum value to clamp the output to. Range : int8
 * @param[in]       activation_max   maximum value to clamp the output to. Range : int8
 * @param[in]       num_col_a   number of columns of A
 * @param[in]       output_bias per output channel bias. Range : int32
 * @param[in,out]   out_0       pointer to output
 * @return     The function returns one of the two
 *              1. The incremented output pointer for a successful operation or
 *              2. NULL if implementation is not available.
 *
 * @details   This function does the matrix multiplication of weight matrix for all output channels
 *            with 2 columns from im2col and produces two elements/output_channel. The outputs are
 *            clamped in the range provided by activation min and max.
 *            Supported framework: TensorFlow Lite micro.
 */
q7_t *muriscv_nn_mat_mult_kernel_s8_s16(const q7_t *input_a,
                                        const q15_t *input_b,
                                        const uint16_t output_ch,
                                        const int32_t *out_shift,
                                        const int32_t *out_mult,
                                        const int32_t out_offset,
                                        const int16_t activation_min,
                                        const int16_t activation_max,
                                        const uint16_t num_col_a,
                                        const int32_t *const output_bias,
                                        q7_t *out_0);

/**
 * @brief Matrix-multiplication function for convolution with per-channel requantization, supporting an address offset
 * between rows.
 * @param[in]       input_a            pointer to operand A
 * @param[in]       input_b            pointer to operand B, always consists of 2 vectors.
 * @param[in]       output_ch          number of rows of A
 * @param[in]       out_shift          pointer to per output channel requantization shift parameter.
 * @param[in]       out_mult           pointer to per output channel requantization multiplier parameter.
 * @param[in]       out_offset         output tensor offset.
 * @param[in]       activation_min     minimum value to clamp the output to. Range : int8
 * @param[in]       activation_max     maximum value to clamp the output to. Range : int8
 * @param[in]       num_col_a          number of columns of A
 * @param[in]       aligned_num_col_a  number of columns of A aligned by 4
 * @param[in]       output_bias        per output channel bias. Range : int32
 * @param[in]       row_address_offset address offset between rows in the output
 * @param[in,out]   out_0              pointer to output
 * @return     The function returns one of the two
 *              1. The incremented output pointer for a successful operation or
 *              2. NULL if implementation is not available.
 *
 * @details   This function does the matrix multiplication of weight matrix for all output channels
 *            with 2 columns from im2col and produces two elements/output_channel. The outputs are
 *            clamped in the range provided by activation min and max.
 *
 *            This function is slighly less performant than muriscv_nn_mat_mult_kernel_s8_s16, but allows support for
 * grouped convolution. Supported framework: TensorFlow Lite micro.
 */
int8_t *muriscv_nn_mat_mult_kernel_row_offset_s8_s16(const int8_t *input_a,
                                                 const int16_t *input_b,
                                                 const uint16_t output_ch,
                                                 const int32_t *out_shift,
                                                 const int32_t *out_mult,
                                                 const int32_t out_offset,
                                                 const int16_t activation_min,
                                                 const int16_t activation_max,
                                                 const int32_t num_col_a,
                                                 const int32_t aligned_num_col_a,
                                                 const int32_t *const output_bias,
                                                 const int32_t row_address_offset,
                                                 int8_t *out_0);

/**
 * @brief Common softmax function for s8 input and s8 or s16 output
 * @param[in]  input          Pointer to the input tensor
 * @param[in]  num_rows       Number of rows in the input tensor
 * @param[in]  row_size       Number of elements in each input row
 * @param[in]  mult           Input quantization multiplier
 * @param[in]  shift          Input quantization shift within the range [0, 31]
 * @param[in]  diff_min       Minimum difference with max in row. Used to check if
 *                            the quantized exponential operation can be performed
 * @param[in]  int16_output   Indicating s8 output if 0 else s16 output
 * @param[out] output         Pointer to the output tensor
 *
 * @note Supported framework: TensorFlow Lite micro (bit-accurate)
 *
 */
void muriscv_nn_softmax_common_s8(const int8_t *input,
                              const int32_t num_rows,
                              const int32_t row_size,
                              const int32_t mult,
                              const int32_t shift,
                              const int32_t diff_min,
                              const bool int16_output,
                              void *output);

/**
 * @brief macro for adding rounding offset
 */
#ifndef MURISCV_NN_TRUNCATE
    #define NN_ROUND(out_shift) ((0x1 << out_shift) >> 1)
#else
    #define NN_ROUND(out_shift) 0
#endif

// Macros for shortening quantization functions' names and avoid long lines
#define MUL_SAT(a, b) muriscv_nn_doubling_high_mult((a), (b))
#define MUL_SAT_MVE(a, b) muriscv_nn_doubling_high_mult_mve_32x4((a), (b))
#define MUL_POW2(a, b) muriscv_nn_mult_by_power_of_two((a), (b))

#define DIV_POW2(a, b) muriscv_nn_divide_by_power_of_two((a), (b))
#define DIV_POW2_MVE(a, b) muriscv_nn_divide_by_power_of_two_mve((a), (b))

#define EXP_ON_NEG(x) muriscv_nn_exp_on_negative_values((x))
#define ONE_OVER1(x) muriscv_nn_one_over_one_plus_x_for_x_in_0_1((x))

/**
 * @brief           Saturating doubling high multiply. Result matches
 *                  NEON instruction VQRDMULH.
 * @param[in]       m1        Multiplicand. Range: {NN_Q31_MIN, NN_Q31_MAX}
 * @param[in]       m2        Multiplier. Range: {NN_Q31_MIN, NN_Q31_MAX}
 * @return          Result of multiplication.
 *
 */
__STATIC_FORCEINLINE int32_t muriscv_nn_doubling_high_mult(const int32_t m1, const int32_t m2)
{
    int32_t result = 0;
    // Rounding offset to add for a right shift of 31
    int64_t mult = 1 << 30;

    if ((m1 < 0) ^ (m2 < 0))
    {
        mult = 1 - mult;
    }
    // Gets resolved as a SMLAL instruction
    mult = mult + (int64_t)m1 * m2;

    // Utilize all of the upper 32 bits. This is the doubling step
    // as well.
    result = (int32_t)(mult / (1ll << 31));

    if ((m1 == m2) && (m1 == (int32_t)NN_Q31_MIN))
    {
        result = NN_Q31_MAX;
    }
    return result;
}

/**
 * @brief           Doubling high multiply without saturation. This is intended
 *                  for requantization where the scale is a positive integer
 *
 * @param[in]       m1        Multiplicand. Range: {NN_Q31_MIN, NN_Q31_MAX}
 * @param[in]       m2        Multiplier Range: {NN_Q31_MIN, NN_Q31_MAX}
 * @return          Result of multiplication.
 * @note            The result of this matches that of neon instruction
 *                  VQRDMULH for m1 in range {NN_Q31_MIN, NN_Q31_MAX} and m2 in
 *                  range {NN_Q31_MIN + 1, NN_Q31_MAX}. Saturation occurs when
 *                  m1 equals m2 equals NN_Q31_MIN and that is not handled by
 *                  this function.
 *
 */
__STATIC_FORCEINLINE int32_t muriscv_nn_doubling_high_mult_no_sat(const int32_t m1, const int32_t m2)
{
    int32_t result = 0;
    union muriscv_nn_long_long mult;

    // Rounding offset to add for a right shift of 31
    mult.word.low = 1 << 30;
    mult.word.high = 0;

    // Gets resolved as a SMLAL instruction
    mult.long_long = mult.long_long + (int64_t)m1 * m2;

    // Utilize all of the upper 32 bits. This is the doubling step
    // as well.
    result = (int32_t)(mult.long_long >> 31);

    return result;
}

/**
 * @brief           Rounding divide by power of two.
 * @param[in]       dividend - Dividend
 * @param[in]       exponent - Divisor = power(2, exponent)
 *                             Range: [0, 31]
 * @return          Rounded result of division. Midpoint is rounded away from zero.
 *
 */
__STATIC_FORCEINLINE int32_t muriscv_nn_divide_by_power_of_two(const int32_t dividend, const int32_t exponent)
{
    int32_t result = 0;
    const int32_t remainder_mask = (1 << exponent) - 1;
    int32_t remainder = remainder_mask & dividend;

    // Basic division
    result = dividend >> exponent;

    // Adjust 'result' for rounding (mid point away from zero)
    int32_t threshold = remainder_mask >> 1;
    if (result < 0)
    {
        threshold++;
    }
    if (remainder > threshold)
    {
        result++;
    }

    return result;
}

/**
 * @brief           Requantize a given value.
 * @details         Essentially returns (val * multiplier)/(2 ^ shift) with different rounding depending if
 *                  MURISCV_NN_USE_SINGLE_ROUNDING is defined or not.
 * @param[in]       val         Value to be requantized
 * @param[in]       multiplier  Multiplier. Range {NN_Q31_MIN + 1, Q32_MAX}
 * @param[in]       shift       Shift. Range: {-31, 30}
 *                              Default branch:
 *                                  If shift is positive left shift 'val * multiplier' with shift
 *                                  If shift is negative right shift 'val * multiplier' with abs(shift)
 *                              Single round branch:
 *                                  Input for total_shift in divide by '2 ^ total_shift'
 *
 * @return          Default branch:
 *                      Returns (val * multiplier) with rounding divided by (2 ^ shift) with rounding
 *                  Single round branch:
 *                      Returns (val * multiplier)/(2 ^ (31 - shift)) with rounding
 *
 */
__STATIC_FORCEINLINE int32_t muriscv_nn_requantize(const int32_t val, const int32_t multiplier, const int32_t shift)
{
#ifdef MURISCV_NN_USE_SINGLE_ROUNDING
    const int64_t total_shift = 31 - shift;
    const int64_t new_val = val * (int64_t)multiplier;

    int32_t result = new_val >> (total_shift - 1);
    result = (result + 1) >> 1;

    return result;
#else
    return muriscv_nn_divide_by_power_of_two(muriscv_nn_doubling_high_mult_no_sat(val * (1 << LEFT_SHIFT(shift)), multiplier),
                                         RIGHT_SHIFT(shift));
#endif
}

/**
 * @brief           Requantize a given 64 bit value.
 * @param[in]       val                 Value to be requantized in the range {-(1<<47)} to {(1<<47) - 1}
 * @param[in]       reduced_multiplier  Reduced multiplier in the range {NN_Q31_MIN + 1, Q32_MAX} to {Q16_MIN + 1,
 * Q16_MAX}
 * @param[in]       shift               Left or right shift for 'val * multiplier' in the range {-31} to {7}
 *
 * @return          Returns (val * multiplier)/(2 ^ shift)
 *
 */
__STATIC_FORCEINLINE int32_t muriscv_nn_requantize_s64(const int64_t val,
                                                   const int32_t reduced_multiplier,
                                                   const int32_t shift)
{
    const int64_t new_val = val * reduced_multiplier;

    int32_t result = new_val >> (14 - shift); // 64->32 bit reduction
    result = (result + 1) >> 1;               // Last shift position and insert round

    return result;
}

//MURISCV_NN CUSTOM CODE
/**
 * @brief           memcpy optimized for RVV
 * @param[in, out]  dst         Destination pointer
 * @param[in]       src         Source pointer
 * @param[in]       block_size  Number of bytes to copy
 *
 */
__STATIC_FORCEINLINE void muriscv_nn_memcpy_s8(int8_t *dst, const int8_t *src, size_t block_size)
{
#if defined(USE_VEXT)
    for (size_t vl; block_size > 0; block_size -= vl, src += vl, dst += vl)
    {
        vl = vsetvl_e8m8(block_size);
        vint8m8_t vec_src = vle8_v_i8m8(src, vl);
        vse8_v_i8m8(dst, vec_src, vl);
    }
#else
    memcpy(dst, src, block_size);
#endif
}

//MURISCV_NN CUSTOM CODE
/**
 * @brief           memcpy wrapper for int16
 * @param[in, out]  dst         Destination pointer
 * @param[in]       src         Source pointer.
 * @param[in]       block_size  Number of bytes to copy.
 *
 */
__STATIC_FORCEINLINE void muriscv_nn_memcpy_q15(int16_t *dst, const int16_t *src, uint32_t block_size)
{
    memcpy(dst, src, block_size);
}

#if defined(USE_VEXT)
//MURISCV_NN CUSTOM CODE
/**
 * @brief           Vector saturating doubling high multiply returning high half.
 * @param[in]       m1        Multiplicand
 * @param[in]       m2        Multiplier
 * @return          Result of multiplication.
 *
 */
__STATIC_FORCEINLINE int32x4_t muriscv_nn_doubling_high_mult_mve(const int32x4_t m1, const int32_t m2)
{
     //return vqrdmulhq_n_s32(m1, m2);
     return 0;
}

//MURISCV_NN CUSTOM CODE
/**
 * @brief           Vector rounding divide by power of two.
 * @param[in]       dividend - Dividend vector
 * @param[in]       exponent - Divisor = power(2, exponent)
 *                             Range: [0, 31]
 * @return          Rounded result of division. Midpoint is rounded away from zero.
 *
 */
__STATIC_FORCEINLINE int32x4_t muriscv_nn_divide_by_power_of_two_mve(const int32x4_t dividend, const int32_t exponent)
{
     //const int32x4_t shift = vdupq_n_s32(-exponent);
     //const int32x4_t fixup = vshrq_n_s32(vandq_s32(dividend, shift), 31);
     //const int32x4_t fixed_up_dividend = vqaddq_s32(dividend, fixup);
     //return vrshlq_s32(fixed_up_dividend, shift);
     return 0;
}

//MURISCV_NN CUSTOM CODE
/**
 * @brief           Requantize a given vector.
 * @param[in]       val         Vector to be requantized
 * @param[in]       multiplier  multiplier
 * @param[in]       shift       shift
 *
 * @return          Returns (val * multiplier)/(2 ^ shift)
 *
 */
__STATIC_FORCEINLINE int32x4_t muriscv_nn_requantize_mve(const int32x4_t val, const int32_t multiplier, const int32_t shift)
{
     //#ifdef CMSIS_NN_USE_SINGLE_ROUNDING
     //const int right_shift = MIN(-1, shift);
     //const int left_shift = shift - right_shift;

     //const int32x4_t left_shift_dup = vdupq_n_s32(left_shift);
     //const int32x4_t right_shift_dup = vdupq_n_s32(right_shift);

     //int32x4_t result = vqdmulhq_n_s32(vshlq_s32(val, left_shift_dup), multiplier);
     //result = vrshlq_s32(result, right_shift_dup);

     //return result;
     //#else
     //return muriscv_nn_divide_by_power_of_two_mve(
     //    muriscv_nn_doubling_high_mult_mve(vshlq_s32(val, vdupq_n_s32(LEFT_SHIFT(shift))), multiplier), RIGHT_SHIFT(shift));
     //#endif
     return 0;
}

/**
 * @brief           Vector saturating doubling high multiply with predication returning high half.
 * @param[in]       m1        Multiplicand
 * @param[in]       m2        Multiplier
 * @param[in]       p         Vector predication mask
 * @param[in]       v_zero    Vector of zeroes for merging predication intrinsic
 * @return          Result of multiplication.
 *
 */
__STATIC_FORCEINLINE int32x4_t muriscv_nn_doubling_high_mult_mve_pred(const int32x4_t m1,
                                                               const int32_t m2,
                                                               const mve_pred16_t p,
                                                               const int32x4_t v_zero)
{
    return vqrdmulhq_m_n_s32(v_zero, m1, m2, p);
}

/**
 * @brief           Vector rounding divide by power of two with predication.
 * @param[in]       dividend - Dividend vector
 * @param[in]       exponent - Divisor = power(2, exponent)
 *                             Range: [0, 31]
 * @param[in]       p        - Vector predication mask
 * @param[in]       v_zero   - Vector of zeroes for merging predication intrinsic
 * @return          Rounded result of division. Midpoint is rounded away from zero.
 *
 */
__STATIC_FORCEINLINE int32x4_t muriscv_nn_divide_by_power_of_two_mve_pred(const int32x4_t dividend,
                                                                   const int32_t exponent,
                                                                   const mve_pred16_t p,
                                                                   const int32x4_t v_zero)
{
    const int32x4_t shift = vdupq_x_n_s32(-exponent, p);
    const int32x4_t fixup = vshrq_x_n_s32(vandq_x_s32(dividend, shift, p), 31, p);
    const int32x4_t fixed_up_dividend = vqaddq_m_s32(v_zero, dividend, fixup, p);
    return vrshlq_m_s32(v_zero, fixed_up_dividend, shift, p);
}

/**
 * @brief           Requantize a given vector with predication.
 * @param[in]       val         Vector to be requantized
 * @param[in]       multiplier  multiplier
 * @param[in]       shift       shift
 * @param[in]       p           Vector predication mask
 *
 * @return          Returns (val * multiplier)/(2 ^ shift)
 *
 */
__STATIC_FORCEINLINE int32x4_t muriscv_nn_requantize_mve_pred(const int32x4_t val,
                                                       const int32_t multiplier,
                                                       const int32_t shift,
                                                       const mve_pred16_t p)
{
    #ifdef MURISCV_NN_USE_SINGLE_ROUNDING
    const int right_shift = MIN(-1, shift);
    const int left_shift = shift - right_shift;
    const int32x4_t v_zero = vcreateq_s32(0, 0);

    const int32x4_t left_shift_dup = vdupq_x_n_s32(left_shift, p);
    const int32x4_t right_shift_dup = vdupq_x_n_s32(right_shift, p);

    int32x4_t result = vqrdmulhq_m_n_s32(v_zero, vshlq_m_s32(v_zero, val, left_shift_dup, p), multiplier, p);
    result = vrshlq_m_s32(v_zero, result, right_shift_dup, p);

    return result;
    #else
    const int32x4_t v_zero = vcreateq_s32(0, 0);
    return muriscv_nn_divide_by_power_of_two_mve_pred(
        muriscv_nn_doubling_high_mult_mve_pred(
            vshlq_m_s32(v_zero, val, vdupq_x_n_s32(LEFT_SHIFT(shift), p), p), multiplier, p, v_zero),
        RIGHT_SHIFT(shift),
        p,
        v_zero);
    #endif
}

//MURISCV_NN CUSTOM CODE
__STATIC_FORCEINLINE int32x4_t muriscv_nn_doubling_high_mult_mve_32x4(const int32x4_t m1, const int32x4_t m2)
{
     //return vqrdmulhq_s32(m1, m2);
     return 0;
}

//MURISCV_NN CUSTOM CODE
__STATIC_FORCEINLINE int32x4_t muriscv_nn_divide_by_power_of_two_mve_32x4(const int32x4_t dividend, const int32x4_t exponent)
{
     //const int32x4_t shift = -exponent;
     //const int32x4_t fixup = vshrq_n_s32(vandq_s32(dividend, shift), 31);
     //const int32x4_t fixed_up_dividend = vqaddq_s32(dividend, fixup);
     //return vrshlq_s32(fixed_up_dividend, shift);
     return 0;
}

//MURISCV_NN CUSTOM CODE
__STATIC_FORCEINLINE int32x4_t muriscv_nn_requantize_mve_32x4(const int32x4_t val,
                                                        const int32x4_t multiplier,
                                                        const int32x4_t shift)
{
     //#ifdef CMSIS_NN_USE_SINGLE_ROUNDING
     //const int32x4_t right_shift = vminq_s32(vdupq_n_s32(-1), shift);
     //const int32x4_t left_shift = vqsubq_s32(shift, right_shift);

     //int32x4_t result = vqdmulhq_s32(vshlq_s32(val, left_shift), multiplier);
     //result = vrshlq_s32(result, right_shift);

     //return result;
     //#else
     //const int32x4_t zz = vdupq_n_s32(0);
     //const mve_pred16_t p = vcmpgtq_n_s32(shift, 0);

     //const int32x4_t left_shift = vpselq_s32(shift, zz, p);
     //const int32x4_t right_shift = -vpselq_s32(zz, shift, p);

     //return muriscv_nn_divide_by_power_of_two_mve_32x4(muriscv_nn_doubling_high_mult_mve_32x4(vshlq_s32(val, left_shift), multiplier),
     //                                           right_shift);
     //#endif
     return 0;
}
#endif

// @note The following functions are used only for softmax layer, scaled bits = 5 assumed

__STATIC_FORCEINLINE int32_t muriscv_nn_exp_on_negative_values(int32_t val)
{
    int32_t mask = 0;
    int32_t shift = 24;

    const int32_t val_mod_minus_quarter = (val & ((1 << shift) - 1)) - (1 << shift);
    const int32_t remainder = val_mod_minus_quarter - val;
    const int32_t x = (val_mod_minus_quarter << 5) + (1 << 28);
    const int32_t x2 = MUL_SAT(x, x);

    int32_t result = 1895147668 +
        MUL_SAT(1895147668, x + DIV_POW2(MUL_SAT(DIV_POW2(MUL_SAT(x2, x2), 2) + MUL_SAT(x2, x), 715827883) + x2, 1));

#define SELECT_IF_NON_ZERO(x)                                                                                          \
    {                                                                                                                  \
        mask = MASK_IF_NON_ZERO(remainder & (1 << shift++));                                                           \
        result = SELECT_USING_MASK(mask, MUL_SAT(result, x), result);                                                  \
    }

    SELECT_IF_NON_ZERO(1672461947)
    SELECT_IF_NON_ZERO(1302514674)
    SELECT_IF_NON_ZERO(790015084)
    SELECT_IF_NON_ZERO(290630308)
    SELECT_IF_NON_ZERO(39332535)
    SELECT_IF_NON_ZERO(720401)
    SELECT_IF_NON_ZERO(242)

#undef SELECT_IF_NON_ZERO

    mask = MASK_IF_ZERO(val);
    return SELECT_USING_MASK(mask, NN_Q31_MAX, result);
}

__STATIC_FORCEINLINE int32_t muriscv_nn_mult_by_power_of_two(const int32_t val, const int32_t exp)
{
    const int32_t thresh = ((1 << (31 - exp)) - 1);
    int32_t result = val << exp;
    result = SELECT_USING_MASK(MASK_IF_NON_ZERO(val > thresh), NN_Q31_MAX, result);
    result = SELECT_USING_MASK(MASK_IF_NON_ZERO(val < -thresh), NN_Q31_MIN, result);
    return result;
}

__STATIC_FORCEINLINE int32_t muriscv_nn_one_over_one_plus_x_for_x_in_0_1(int32_t val)
{
    const int64_t sum = (int64_t)val + (int64_t)NN_Q31_MAX;
    const int32_t half_denominator = (int32_t)((sum + (sum >= 0 ? 1 : -1)) / 2L);
    int32_t x = 1515870810 + MUL_SAT(half_denominator, -1010580540);

    const int32_t shift = (1 << 29);
    x += MUL_POW2(MUL_SAT(x, shift - MUL_SAT(half_denominator, x)), 2);
    x += MUL_POW2(MUL_SAT(x, shift - MUL_SAT(half_denominator, x)), 2);
    x += MUL_POW2(MUL_SAT(x, shift - MUL_SAT(half_denominator, x)), 2);

    return MUL_POW2(x, 1);
}

/**
  @brief         Write 2 s16 elements and post increment pointer.
  @param[in]     dest_q15  Pointer to pointer that holds address of destination.
  @param[in]     src_q31   Input value to be written.
 */
__STATIC_FORCEINLINE void muriscv_nn_write_q15x2_ia(int16_t **dest_q15, int32_t src_q31)
{
    int32_t val = src_q31;

    memcpy(*dest_q15, &val, 4);
    *dest_q15 += 2;
}

/**
  @brief         Write 2 s8 elements and post increment pointer.
  @param[in]     dst  Pointer to pointer that holds address of destination.
  @param[in]     src  Input value to be written.
 */
__STATIC_FORCEINLINE void muriscv_nn_write_s8x2_ia(int8_t **dst, int16_t src)
{
    memcpy(*dst, &src, 2);
    *dst += 2;
}

// Support functions for LSTM
/**
 * @brief Update LSTM function for an iteration step using s8 input and output, and s16 internally.
 *
 * @param[in]   data_in                         Data input pointer
 * @param[in]   hidden_in                       Hidden state/ recurrent input pointer
 * @param[out]  hidden_out                      Hidden state/ recurrent output pointer
 * @param[in]   params                          Struct containg all information about the lstm operator, see
 * muriscv_nn_types.
 * @param[in]   buffers                         Struct containg pointers to all temporary scratch buffers needed for the
 * lstm operator, see muriscv_nn_types.
 * @param[in]   batch_offset                    Number of timesteps between consecutive batches.
 * E.g for params->timing_major = true, all batches for t=0 are stored sequentially, so batch offset = 1.
 * For params->time major = false, all time steps are stored continously before the next batch, so
 * batch offset = params->time_steps.
 * @return                                      The function returns MURISCV_NN_SUCCESS

 */
muriscv_nn_status muriscv_nn_lstm_step_s8(const int8_t *data_in,
                                        const int8_t *hidden_in,
                                        int8_t *hidden_out,
                                        const muriscv_nn_lstm_params *params,
                                        muriscv_nn_lstm_context *buffers,
                                        const int32_t batch_offset);

/**
 * @brief Update LSTM function for an iteration step using s16 input and output, and s16 internally.
 *
 * @param[in]   data_in                         Data input pointer
 * @param[in]   hidden_in                       Hidden state/ recurrent input pointer
 * @param[out]  hidden_out                      Hidden state/ recurrent output pointer
 * @param[in]   params                          Struct containg all information about the lstm operator, see
 * muriscv_nn_types.
 * @param[in]   buffers                         Struct containg pointers to all temporary scratch buffers needed for the
 * lstm operator, see muriscv_nn_types.
 * @param[in]   batch_offset                    Number of timesteps between consecutive batches.
 * E.g for params->timing_major = true, all batches for t=0 are stored sequentially, so batch offset = 1.
 * For params->time major = false, all time steps are stored continously before the next batch, so
 * batch offset = params->time_steps.
 * @return                                      The function returns MURISCV_NN_SUCCESS

 */
muriscv_nn_status muriscv_nn_lstm_step_s16(const int16_t *data_in,
                                         const int16_t *hidden_in,
                                         int16_t *hidden_out,
                                         const muriscv_nn_lstm_params *params,
                                         muriscv_nn_lstm_context *buffers,
                                         const int32_t batch_offset);

/**
 * @brief Updates a LSTM gate for an iteration step of LSTM function, int8x8_16 version.
 *
 * @param[in]   data_in                         Data input pointer
 * @param[in]   hidden_in                       Hidden state/ recurrent input pointer
 * @param[in]   gate_data                       Struct containing all information about the gate caluclation, see
 * muriscv_nn_types.
 * @param[in]   params                          Struct containing all information about the lstm_operation, see
 * muriscv_nn_types
 * @param[out]  output                          Hidden state/ recurrent output pointer
 * @param[in]   batch_offset                    Number of timesteps between consecutive batches, see
 * muriscv_nn_lstm_step_s8.
 * @return                                      The function returns MURISCV_NN_SUCCESS
 */
muriscv_nn_status muriscv_nn_lstm_calculate_gate_s8_s16(const int8_t *data_in,
                                                      const int8_t *hidden_in,
                                                      const muriscv_nn_lstm_gate *gate_data,
                                                      const muriscv_nn_lstm_params *params,
                                                      int16_t *output,
                                                      const int32_t batch_offset);

/**
 * @brief Updates a LSTM gate for an iteration step of LSTM function, int16x8_16 version.
 *
 * @param[in]   data_in                         Data input pointer
 * @param[in]   hidden_in                       Hidden state/ recurrent input pointer
 * @param[in]   gate_data                       Struct containing all information about the gate caluclation, see
 * muriscv_nn_types.
 * @param[in]   params                          Struct containing all information about the lstm_operation, see
 * muriscv_nn_types
 * @param[out]  output                          Hidden state/ recurrent output pointer
 * @param[in]   batch_offset                    Number of timesteps between consecutive batches, see
 * muriscv_nn_lstm_step_s16.
 * @return                                      The function returns MURISCV_NN_SUCCESS
 */
muriscv_nn_status muriscv_nn_lstm_calculate_gate_s16(const int16_t *data_in,
                                                   const int16_t *hidden_in,
                                                   const muriscv_nn_lstm_gate *gate_data,
                                                   const muriscv_nn_lstm_params *params,
                                                   int16_t *output,
                                                   const int32_t batch_offset);

/**
 * @brief The result of the multiplication is accumulated to the passed result buffer.
 * Multiplies a matrix by a "batched" vector (i.e. a matrix with a batch dimension composed by input vectors independent
 * from each other).
 *
 * @param[in]   lhs              Batched vector
 * @param[in]   rhs              Weights - input matrix (H(Rows)xW(Columns))
 * @param[in]   effective_bias   Bias + lhs_offset * kernel_sum term precalculated into a constant vector.
 * @param[out]  dst              Output
 * @param[in]   dst_multiplier   Multiplier for quantization
 * @param[in]   dst_shift        Shift for quantization
 * @param[in]   rhs_cols         Vector/matarix column length
 * @param[in]   rhs_rows         Row count of matrix
 * @param[in]   batches          Batch size
 * @param[in]   batch_offset     Number of timesteps between consecutive batches in input, see muriscv_nn_lstm_step_s8. Note
 that the output is always stored with sequential batches.
 * @return                       The function returns <code>MURISCV_NN_SUCCESS</code>

 */
muriscv_nn_status muriscv_nn_vec_mat_mul_result_acc_s8_s16(const int8_t *lhs,
                                                         const int8_t *rhs,
                                                         const int32_t *effective_bias,
                                                         int16_t *dst,
                                                         const int32_t dst_multiplier,
                                                         const int32_t dst_shift,
                                                         const int32_t rhs_cols,
                                                         const int32_t rhs_rows,
                                                         const int32_t batches,
                                                         const int32_t batch_offset);

/**
 * @brief The result of the multiplication is accumulated to the passed result buffer.
 * Multiplies a matrix by a "batched" vector (i.e. a matrix with a batch dimension composed by input vectors independent
 * from each other).
 *
 * @param[in]   lhs              Batched vector
 * @param[in]   rhs              Weights - input matrix (H(Rows)xW(Columns))
 * @param[in]   effective_bias   Bias + lhs_offset * kernel_sum term precalculated into a constant vector.
 * @param[out]  dst              Output
 * @param[in]   dst_multiplier   Multiplier for quantization
 * @param[in]   dst_shift        Shift for quantization
 * @param[in]   rhs_cols         Vector/matarix column length
 * @param[in]   rhs_rows         Row count of matrix
 * @param[in]   batches          Batch size
 * @param[in]   batch_offset     Number of timesteps between consecutive batches in input, see muriscv_nn_lstm_step_s16.
 Note that the output is always stored with sequential batches.
 * @return                       The function returns <code>MURISCV_NN_SUCCESS</code>

 */
muriscv_nn_status muriscv_nn_vec_mat_mul_result_acc_s16(const int16_t *lhs,
                                                      const int8_t *rhs,
                                                      const int64_t *effective_bias,
                                                      int16_t *dst,
                                                      const int32_t dst_multiplier,
                                                      const int32_t dst_shift,
                                                      const int32_t rhs_cols,
                                                      const int32_t rhs_rows,
                                                      const int32_t batches,
                                                      const int32_t batch_offset);

/**
 * @brief s16 elementwise multiplication with s8 output
 * @param[in]       input_1_vect        pointer to input vector 1
 * @param[in]       input_2_vect        pointer to input vector 2
 * @param[in,out]   output              pointer to output vector
 * @param[in]       out_offset          output offset
 * @param[in]       out_mult            output multiplier
 * @param[in]       out_shift           output shift
 * @param[in]       block_size          number of samples per batch
 * @param[in]       batch_size          number of samples per batch
 * @param[in]       batch_offset        Number of timesteps between consecutive batches in output, see
 * muriscv_nn_lstm_step_s8. Note that it is assumed that the input is stored with sequential batches.
 * @return          The function returns MURISCV_NN_SUCCESS
 *
 * @details   Supported framework: TensorFlow Lite micro
 */
muriscv_nn_status muriscv_nn_elementwise_mul_s16_s8(const int16_t *input_1_vect,
                                               const int16_t *input_2_vect,
                                               int8_t *output,
                                               const int32_t out_offset,
                                               const int32_t out_mult,
                                               const int32_t out_shift,
                                               const int32_t block_size,
                                               const int32_t batch_size,
                                               const int32_t batch_offset);

/**
 * @brief s16 elementwise multiplication with s16 output
 * @param[in]       input_1_vect        pointer to input vector 1
 * @param[in]       input_2_vect        pointer to input vector 2
 * @param[in,out]   output              pointer to output vector
 * @param[in]       out_offset          output offset
 * @param[in]       out_mult            output multiplier
 * @param[in]       out_shift           output shift
 * @param[in]       block_size          number of samples per batch
 * @param[in]       batch_size          number of samples per batch
 * @param[in]       batch_offset        Number of timesteps between consecutive batches in output, see
 * muriscv_nn_lstm_step_s16. Note that it is assumed that the input is stored with sequential batches.
 * @return          The function returns MURISCV_NN_SUCCESS
 *
 * @details   Supported framework: TensorFlow Lite micro
 */
muriscv_nn_status muriscv_nn_elementwise_mul_s16_batch_offset(const int16_t *input_1_vect,
                                                         const int16_t *input_2_vect,
                                                         int16_t *output,
                                                         const int32_t out_offset,
                                                         const int32_t out_mult,
                                                         const int32_t out_shift,
                                                         const int32_t block_size,
                                                         const int32_t batch_size,
                                                         const int32_t batch_offset);

/**
 * @brief s16 elementwise multiplication. The result of the multiplication is accumulated to the passed result buffer.
 * @param[in]       input_1_vect        pointer to input vector 1
 * @param[in]       input_2_vect        pointer to input vector 2
 * @param[in]       input_1_offset      offset for input 1. Not used.
 * @param[in]       input_2_offset      offset for input 2. Not used.
 * @param[in,out]   output              pointer to output vector
 * @param[in]       out_offset          output offset. Not used.
 * @param[in]       out_mult            output multiplier
 * @param[in]       out_shift           output shift
 * @param[in]       out_activation_min  minimum value to clamp output to. Min: -32768
 * @param[in]       out_activation_max  maximum value to clamp output to. Max: 32767
 * @param[in]       block_size          number of samples
 * @return          The function returns MURISCV_NN_SUCCESS
 *
 * @details   Supported framework: TensorFlow Lite micro
 */
muriscv_nn_status muriscv_nn_elementwise_mul_acc_s16(const int16_t *input_1_vect,
                                                const int16_t *input_2_vect,
                                                const int32_t input_1_offset,
                                                const int32_t input_2_offset,
                                                int16_t *output,
                                                const int32_t out_offset,
                                                const int32_t out_mult,
                                                const int32_t out_shift,
                                                const int32_t out_activation_min,
                                                const int32_t out_activation_max,
                                                const int32_t block_size);

#ifdef __cplusplus
}
#endif

#endif /* MURISCV_NNSUPPORT_FUNCTIONS_H */
