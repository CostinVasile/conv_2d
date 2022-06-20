#include <iostream>
#include <chrono>

#define matrix_width  1000
#define matrix_height 1000
#define kernel_width  10
#define kernel_height 10
#define strides 1
#define output_width  int(((matrix_width - kernel_width) / strides) + 1)
#define output_height int(((matrix_height - kernel_height) / strides) + 1)


using namespace std::chrono;
using namespace std;


int matrix[matrix_width][matrix_height];
int kernel[kernel_width][kernel_height];
int output[output_width][output_height];


void constructData() {
//    cout << "Input matrix: " << endl;
    for (int i = 0; i < matrix_width; i++) {
        for (int j = 0; j < matrix_height; j++) {
            matrix[i][j] = rand() % 10;
//            cout << matrix[i][j] << ' ';
        }
//        cout << endl;
    }

//    cout << endl;
//    cout << "Kernel: " << endl;
    for (int i = 0; i < kernel_width; i++) {
        for (int j = 0; j < kernel_height; j++) {
            kernel[i][j] = rand() % 10;
//            cout << kernel[i][j] << ' ';
        }
//        cout << endl;
    }
}


void conv2d() {
#ifdef USE_OPENMP
#pragma omp parallel for
#endif
    for (int i = 0; i < output_width; i++) {
        for (int j = 0; j < output_height; j++) {
            output[i][j] = 0;
            for (int m = 0; m < kernel_width; m++) {
                for (int n = 0; n < kernel_height; n++) {
                    output[i][j] += matrix[i * strides + m][j * strides + n] * kernel[m][n];
                }
            }
        }
    }
}


void printResults() {
    cout << endl;
    cout << "Result: " << endl;
    for (int i = 0; i < output_width; i++) {
        for (int j = 0; j < output_height; j++) {
            cout << output[i][j] << ' ';
        }
        cout << endl;
    }
}


int main() {
    #ifdef USE_OPENMP
        cout << "Using OPENMP optimization features" << endl;
    #else
	cout << "Not using OPENMP optimization features" << endl;
    #endif
    
    constructData();

    auto start = std::chrono::high_resolution_clock::now();
    conv2d();
    auto stop = std::chrono::high_resolution_clock::now();

//    printResults();
    cout << "Computing done in " << duration_cast<std::chrono::milliseconds>(stop - start).count() << " ms"
         << std::endl;
    return 0;
}
