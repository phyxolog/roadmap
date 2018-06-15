#include <iostream>

using namespace std;

void selectionSort(int *array, const int arrayLength) {
  for (int i = 0; i < arrayLength - 1; i++) {
    int min = i;

    for (int j = i + 1; j < arrayLength; j++) {
      if (array[j] < array[min]) {
        min = j;
      }
    }

    if (min != i) {
      // swap i and min
      int temp = array[i];
      array[i] = array[min];
      array[min] = temp;
    }
  }
}

int main() {
  const int arrayLength = 6;
  int array[arrayLength] = { 5, 3, 1, 8, 2, 20 };
  
  selectionSort(array, arrayLength);

  for (int i = 0; i < arrayLength; i++) {
    cout << array[i] << " ";
  }

  return 0;
}