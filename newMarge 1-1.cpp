
#include <iostream>
using namespace std;

void MERGE(int A[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    // Merge the temporary arrays back into A[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

// Utility function to print an array
void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

// Driver code to test above functions
int main() {
    int A[] = {12, 11, 13, 5, 6, 7};
    int array_size = sizeof(A) / sizeof(A[0]);

    cout << "Given array is \n";
    printArray(A, array_size);

    int left = 0;
    int right = array_size - 1;
    int mid = left + (right - left) / 2;

    MERGE(A, left, mid, right);

    cout << "\nMerged array is \n";
    printArray(A, array_size);

    return 0;
}
