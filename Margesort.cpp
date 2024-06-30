
#include <iostream>
using namespace std;

void merge(int* A, int* B, int* C, int n, int m) {
    int i = 0, j = 0, k = 0;

    // Merge the arrays A and B into C
    while (i < n && j < m) {
        if (A[i] > B[j]) {
            C[k++] = B[j++];
        } else {
            C[k++] = A[i++];
        }
    }

    // Copy the remaining elements of A, if any
    while (i < n) {
        C[k++] = A[i++];
    }

    // Copy the remaining elements of B, if any
    while (j < m) {
        C[k++] = B[j++];
    }
}

int main() {
    int A[] = {1, 3, 5, 7};
    int B[] = {2, 4, 6, 8};
    int n = sizeof(A) / sizeof(A[0]);
    int m = sizeof(B) / sizeof(B[0]);
    int C[n + m];  // Array to hold the merged elements

    merge(A, B, C, n, m);

    // Print the merged array
    for (int i = 0; i < n + m; i++) {
        cout << C[i] << " ";
    }

    return 0;
}
