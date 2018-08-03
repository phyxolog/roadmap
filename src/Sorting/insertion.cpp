//
// Created by phyxolog on 03.08.18.
//

#include <iostream>

using namespace std;

void insertionSort(int *array, const int arrayLength) {
    int temp = 0, j = 0;

    for (int i = 0; i < arrayLength; i++) {
        j = i;
        while (j > 0 && array[j] < array[j - 1]) {
            temp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = temp;
            j--;
        }
    }
}

int main() {
    const int arrayLength = 6;
    int array[arrayLength] = { 5, 3, 1, 8, 2, 20 };

    insertionSort(array, arrayLength);

    for (int i = 0; i < arrayLength; i++) {
        cout << array[i] << " ";
    }

    return 0;
}