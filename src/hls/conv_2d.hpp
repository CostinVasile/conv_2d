#include "ap_axi_sdata.h"
#include "hls_stream.h"

#define x_matrix 4
#define y_matrix 4
#define x_kernel 2
#define y_kernel 2
#define strides 1
#define x_result (((x_matrix - x_kernel) / strides) + 1)
#define y_result (((y_matrix - y_kernel) / strides) + 1)

void conv_2d(hls::stream< ap_axis<16,2,5,6> > matrix,
			 hls::stream< ap_axis<16,2,5,6> > kernel,
			 hls::stream< ap_axis<16,2,5,6> > result);
