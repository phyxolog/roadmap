#include <iostream>

// For input/output
using std::cin;
using std::cout;
using std::endl;

void onlyPrint() {
  // Create array with static size
  const int SIZE = 3;
  int array[SIZE] = { 4, 5, 3 };

  // Print array
  for (int i = 0; i < SIZE; i++) {
    cout << array[i] << endl;
  }

  cout << endl;
}

void calcAverage() {
  const int SIZE = 8;
  // Initialize array
  int array[SIZE] = { 4, 5, 8, 7, 9, 7, 4, 1 };
  // In this var we are write a average
  float avg;
  int sum = 0;

  // Next calculate a sum of array
  for (int i = 0; i < SIZE; i++) {
    sum += array[i];
  }

  avg = sum / SIZE;

  cout << "Average sum: " << avg << endl << endl;
}

void copyFrom() {
  const int SIZE = 11;
  int array[SIZE] = { 5, 7, 8, 9, 5, 4, 7, 8, 4, 5, 4 },
      array2[SIZE]; // To this array we are write a number, whose index >= 3

  for (int i = 0; i < SIZE; i++) {
    if (i >= 3) {
      array2[i - 3] = array[i];
    }
  }

  for (int i = 0; i < SIZE - 3; i++) {
    cout << "Element " << i << ": " << array2[i] << endl;
  }

  cout << endl;
}

int calculateSum(int array[], int length) {
	int sum = 0;
	bool all = array[0] > 0;
	for (int i = 0; i < length; i++) {
		sum += all ? array[i] :
			i % 2 != 0 ? array[i] : 0;
	}
	return sum;
}

void doubleSum() {
  const int SIZE = 15;
  int array[SIZE] = { 5, 7, 8, 9, 5, 4, 7, 8, 4, 5, 4, 54, 7, 4, 1 };

  cout << "Array sum 1: " << calculateSum(array, SIZE) << endl;
  array[0] = 0;
  cout << "Array sum 2: " << calculateSum(array, SIZE) << endl;
  cout << endl;
}

int getgtPaired(int array[], int length) {
	int data[2] = { 0, array[0] };
	for (int i = 0; i < length; i++) {
		if (array[i] % 2 == 0) {
			if (data[1] < array[i]) {
				data[0] = i;
				data[i] = array[i];
			}
		}
	}

	return data[0];
}

void gtPaired() {
	int k;
	
	cout << "Enter k: ";
	cin >> k;

  // Now we are using pointers.
  // Closer I'll get to know them a little better.
  // And we doesn't check for overflow
  // bacause now it's overhead.
	int *arr = new int[k];

	for (int i = 0; i < k; i++) {
		cout << "Enter " << i + 1 << " number:";
		cin >> arr[i];
	}

	cout << "Gt paired: " << getgtPaired(arr, k) << endl;
}

int main(int argc, char *argv[]) {
  onlyPrint();

  calcAverage();

  copyFrom();

  doubleSum();

  gtPaired();

  return 0;
}