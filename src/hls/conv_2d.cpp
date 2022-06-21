#include <cstddef>
#include <cstdint>
#include "ap_axi_sdata.h"
#include "hls_stream.h"
#include "conv_2d.hpp"


//#include <stdint.h>
//#include <stdio.h>
//
//void conv_2d(uint16_t matrix[x_matrix][y_matrix],
//			 uint16_t kernel[x_kernel][y_kernel],
//			 uint16_t result[x_result][y_result]){
//
//	for(int i = 0; i<x_result; i++){
//		for(int j = 0; j<y_result; j++){
//			result[i][j] = 0;
//			for(int k = i*strides; k<i*strides+x_kernel; k++){
//				for(int l = j*strides; l<j*strides+y_kernel; l++){
//					result[i][j] += matrix[k][l]*kernel[k-(i*strides)][l-(j*strides)];
//				}
//			}
//		}
//	}
//}

void conv_2d(hls::stream< ap_axis<32,2,5,6> > &matrix,
//			 hls::stream< ap_axis<16,2,5,6> > &kernel,
			 hls::stream< ap_axis<32,2,5,6> > &result){

#pragma HLS INTERFACE axis port=matrix
//#pragma HLS INTERFACE axis port=kernel
#pragma HLS INTERFACE axis port=result
#pragma hls interface s_axilite port=return

	uint32_t matrix_buffer[4][4];
	uint32_t kernel_buffer[2][2];
	uint32_t result_buffer[3][3];

	ap_axis<32,2,5,6> tmp;

	for(int i = 0; i<4; i++){
		for(int j = 0; j<4; j++){
			matrix.read(tmp);
			matrix_buffer[i][j] = tmp.data.to_int();
		}
	}

	for(int i = 0; i<2; i++){
		for(int j = 0; j<2; j++){
			matrix.read(tmp);
			kernel_buffer[i][j] = tmp.data.to_int();
		}
	}

	for(int i = 0; i<x_result; i++){
		for(int j = 0; j<y_result; j++){
			result_buffer[i][j] = 0;
			for(int k = 0; k<x_kernel; k++){
				for(int l = 0; l<y_kernel; l++){
					result_buffer[i][j] += matrix_buffer[i*strides+k][j*strides+l]*kernel_buffer[k][l];
				}
			}
		}
	}

	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			tmp.data = result_buffer[i][j];
			result.write(tmp);
		}
	}
}
