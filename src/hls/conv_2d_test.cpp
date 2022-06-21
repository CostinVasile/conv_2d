#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "conv_2d.hpp"

int main(){
	printf("\n\n************************************************\n");

	uint16_t matrix[4][4];
	uint16_t kernel[2][2];
	uint16_t result[3][3];

	// build the input matrix
	printf("Input matrix:\n");
	for(int matrix_i = 0; matrix_i<4; matrix_i++){
		for(int matrix_j = 0; matrix_j<4; matrix_j++){
			matrix[matrix_i][matrix_j] = rand()%100;
			printf("%hu ", matrix[matrix_i][matrix_j]);
		}
		printf("\n");
	}

	// build the kernel
	printf("\nKernel matrix:\n");
	for(int kernel_i = 0; kernel_i<2; kernel_i++){
		for(int kernel_j = 0; kernel_j<2; kernel_j++){
			kernel[kernel_i][kernel_j] = rand()%100;
			printf("%hu ", kernel[kernel_i][kernel_j]);
		}
		printf("\n");
	}

	// main function call
//	conv_2d(matrix, kernel, result);

	// data output
	printf("\nResult:\n");
	for(int output_i = 0; output_i<3; output_i++){
		for(int output_j = 0; output_j<3; output_j++){
			printf("%hu ", result[output_i][output_j]);
		}
		printf("\n");
	}


	printf("\n************************************************\n\n");
}
