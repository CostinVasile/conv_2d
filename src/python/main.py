import time
import numpy as np
import random

debug = False


def build_input_matrix(width, height):
    matrix = np.zeros((width, height), np.uint16)
    for i in range(width):
        for j in range(height):
            matrix[i][j] = random.randint(0, 100)

    return matrix


def build_kernel(width, height):
    kernel = np.zeros((width, height), np.uint16)
    for i in range(width):
        for j in range(height):
            kernel[i][j] = random.randint(0, 100)

    return kernel


def sw_conv2d(matrix, kernel, strides):
    x_matrix = matrix.shape[0]
    y_matrix = matrix.shape[1]
    x_kernel = kernel.shape[0]
    y_kernel = kernel.shape[1]
    x_output = int(((x_matrix - x_kernel) / strides) + 1)
    y_output = int(((y_matrix - y_kernel) / strides) + 1)

    if debug:
        print("x_matrix = {}".format(x_matrix))
        print("y_matrix = {}".format(y_matrix))
        print("x_kernel = {}".format(x_kernel))
        print("y_kernel = {}".format(y_kernel))
        print("x_output = {}".format(x_output))
        print("y_output = {}".format(y_output))
        print("strides = {}".format(strides))

    # output matrix
    output = np.zeros((x_output, y_output), np.uint16)

    for i in range(x_output):
        if debug:
            print("i={}".format(i))

        for j in range(y_output):
            if debug:
                print("j={}".format(i))

            matrix_slice = matrix[i*strides:i*strides+x_kernel, j*strides:j*strides+y_kernel]
            output[i][j] = (matrix_slice*kernel).sum()

    return output


def hw_conv_2d():
    raise NotImplementedError


if __name__ == '__main__':
    print("Execution started")

    input_matrix_width = 1000
    input_matrix_height = 1000

    matrix = build_input_matrix(input_matrix_width, input_matrix_height)
    kernel = build_kernel(2, 2)

    if debug:
        print("Input matrix:")
        print(matrix)
        print()
        print("Kernel:")
        print(kernel)
        print()

    start_time = time.time() * (10**3)
    output = sw_conv2d(matrix, kernel, 2)
    end_time = time.time() * (10**3)

    if debug:
        print("Output matrix")
        print(output)

    print("Execution finished in {} miliseconds".format(end_time - start_time))

