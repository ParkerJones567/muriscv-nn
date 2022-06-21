#pragma once
#include <stdint.h>

const int32_t basic_biases[1] = {14820};
const int8_t basic_input[40] = {-9,  -38, 76,  -40, 99,  60, 64,  52,  47,  -43, 72, 28,  -82, 61,
                                -63, 48,  -21, -47, 74,  29, -28, 8,   -38, 13,  33, -45, 59,  -25,
                                -8,  -50, 107, 81,  -77, 43, -82, 125, 83,  23,  17, 15};
const int32_t basic_output_mult[1] = {1877929154};
const int32_t basic_output_shift[1] = {-5};
const int8_t basic_weights[8] = {69, -84, -127, -24, 28, 45, 51, -53};

const int32_t stride2pad1_biases[1] = {4318};
const int8_t stride2pad1_input[49] = {27,   70,  -117, 45,   99,   100,  107, -24, 5,   75,  106,  -19, -70,
                                      -123, 30,  55,   24,   -49,  71,   36,  -35, -46, -96, -102, -15, -127,
                                      121,  37,  -37,  -10,  -115, 82,   53,  -60, -74, 38,  -109, 4,   53,
                                      -95,  120, 5,    -122, -71,  -117, 6,   39,  61,  88};
const int32_t stride2pad1_output_mult[1] = {1373179967};
const int32_t stride2pad1_output_shift[1] = {-8};
const int8_t stride2pad1_weights[9] = {85, 77, -30, 10, -12, 97, 34, 127, -4};

const int32_t depthwise_eq_in_out_ch_biases[6] = {11638, 15523, 23835, 6771, 24700, -31756};
const int8_t depthwise_eq_in_out_ch_input[120] = {
    74,   -116, -83, 2,    59,   39, -46, 96,   34,   -79,  81,   -99, 13,  88,  66,  67,  -63, -20, -87,  -100,
    -60,  115,  -21, -117, -31,  85, -76, 85,   25,   25,   -105, 109, 65,  -6,  -57, 7,   -2,  81,  106,  -87,
    108,  -124, 5,   10,   16,   17, -31, 106,  -47,  -26,  -93,  -67, 59,  99,  -88, -72, 0,   -19, -108, 92,
    -127, 55,   72,  90,   -121, -9, 0,   -31,  -110, -108, 51,   -9,  92,  15,  77,  82,  -38, 10,  125,  112,
    -93,  -47,  62,  98,   58,   -1, 15,  -123, 112,  0,    94,   71,  72,  22,  102, -33, -62, 67,  64,   -70,
    -88,  79,   -65, -116, -100, 21, -38, -16,  13,   24,   18,   108, -44, -68, 85,  -44, 62,  -5,  -96,  78};
const int32_t depthwise_eq_in_out_ch_output_mult[6] =
    {1964839021, 1857386938, 1918788128, 1688533548, 1811335929, 1581081349};
const int32_t depthwise_eq_in_out_ch_output_shift[6] = {-9, -9, -9, -9, -9, -9};
const int8_t depthwise_eq_in_out_ch_weights[36] = {47,   13, 45,   44,  -57,  -51, -11,  -98, -109, -51, -89, -76,
                                                 -2,   10, -88,  -80, -127, -92, -127, 127, 65,   -59, 100, 127,
                                                 -115, 12, -127, -99, 25,   123, -81,  86,  27,   127, 27,  -85};
