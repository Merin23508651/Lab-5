
#include <iostream>
#include <cstdlib>  // for srand, rand
#include <ctime>    // for time

using namespace std;

// Function to dynamically allocate a matrix
int** createMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for(int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

// Function to deallocate a matrix
void deleteMatrix(int** matrix, int rows) {
    for(int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Function to fill a matrix with random values
void fillMatrixWithRandomValues(int** matrix, int rows, int cols) {
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 100;  // Random values between 0 and 99
        }
    }
}

// Function to print a matrix
void printMatrix(int** matrix, int rows, int cols) {
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to add two matrices
int** addMatrices(int** A, int** B, int rows, int cols) {
    int** result = createMatrix(rows, cols);
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

// Function to subtract two matrices
int** subtractMatrices(int** A, int** B, int rows, int cols) {
    int** result = createMatrix(rows, cols);
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices
int** multiplyMatrices(int** A, int** B, int rowsA, int colsA, int colsB) {
    int** result = createMatrix(rowsA, colsB);
    for(int i = 0; i < rowsA; ++i) {
        for(int j = 0; j < colsB; ++j) {
            result[i][j] = 0;
            for(int k = 0; k < colsA; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

// Function to transpose a matrix
int** transposeMatrix(int** matrix, int rows, int cols) {
    int** result = createMatrix(cols, rows);
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}

int main() {
    srand(time(0));  // Seed the random number generator

    int rows = 3, cols = 3;

    // Create and fill matrices with random values
    int** matrixA = createMatrix(rows, cols);
    int** matrixB = createMatrix(rows, cols);
    fillMatrixWithRandomValues(matrixA, rows, cols);
    fillMatrixWithRandomValues(matrixB, rows, cols);

    cout << "Matrix A:" << endl;
    printMatrix(matrixA, rows, cols);

    cout << "Matrix B:" << endl;
    printMatrix(matrixB, rows, cols);

    // Matrix addition
    int** sumMatrix = addMatrices(matrixA, matrixB, rows, cols);
    cout << "Sum of A and B:" << endl;
    printMatrix(sumMatrix, rows, cols);

    // Matrix subtraction
    int** diffMatrix = subtractMatrices(matrixA, matrixB, rows, cols);
    cout << "Difference of A and B:" << endl;
    printMatrix(diffMatrix, rows, cols);

    // Matrix multiplication
    int** productMatrix = multiplyMatrices(matrixA, matrixB, rows, cols, cols);
    cout << "Product of A and B:" << endl;
    printMatrix(productMatrix, rows, cols);

    // Matrix transpose
    int** transposedMatrix = transposeMatrix(matrixA, rows, cols);
    cout << "Transpose of A:" << endl;
    printMatrix(transposedMatrix, cols, rows);

    // Clean up memory
    deleteMatrix(matrixA, rows);
    deleteMatrix(matrixB, rows);
    deleteMatrix(sumMatrix, rows);
    deleteMatrix(diffMatrix, rows);
    deleteMatrix(productMatrix, rows);
    deleteMatrix(transposedMatrix, cols);

    return 0;
}
