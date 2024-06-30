
#include <bits/stdc++.h>
using namespace std;

void merge(int A[], int B[], int n, int m, int C[]) {
    int i = 0, j = 0, k = 0;

    // Merge the two arrays into C
    while (i <= n - 1 && j <= m - 1) {
        if (A[i] > B[j]) {
            C[k++] = B[j++];
        } else {
            C[k++] = A[i++];
        }
    }

    // Copy remaining elements of A, if any
    while (i <= n - 1) {
        C[k++] = A[i++];
    }

    // Copy remaining elements of B, if any
    while (j <= m - 1) {
        C[k++] = B[j++];
    }
}

int main() {
    int A[] = {1, 3, 5, 7};
    int B[] = {2, 4, 6, 8};
    int n = sizeof(A) / sizeof(A[0]);
    int m = sizeof(B) / sizeof(B[0]);

    int C[n + m];

    merge(A, B, n, m, C);

    std::cout << "Merged array: ";
    for (int i = 0; i < n + m; i++) {
        std::cout << C[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
