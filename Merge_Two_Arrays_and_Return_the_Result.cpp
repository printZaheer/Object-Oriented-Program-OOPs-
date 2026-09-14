#include <iostream>
using namespace std;

int* mergeArrays(int *arr1, int size1, int *arr2, int size2) {
    int mergedSize = size1 + size2;
    int *merged = new int[mergedSize];

    for (int i = 0; i < size1; i++) {
        merged[i] = arr1[i];
    }
    for (int j = 0; j < size2; j++) {
        merged[size1 + j] = arr2[j];
    }
    return merged;
}
int main() {
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {5, 6, 7, 8, 9};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int *merged = mergeArrays(arr1, size1, arr2, size2);
    int mergedSize = size1 + size2;

    cout << "Merged array: ";
    for (int i = 0; i < mergedSize; i++) {
        cout << merged[i] << " ";
    }
    cout << endl;
    delete[] merged;
    return 0;
}
