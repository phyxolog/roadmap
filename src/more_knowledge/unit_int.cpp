#include <iostream>
#include <cmath>

using namespace std;

int method1(int n) {
  int i = 10;
  int c = 0;

  while ((c = n % i) != n) {
    n -= c;
    i *= 10;
  }
  
  return n;
}

// Get counts of digits
// Complexity: constant
int getCountsOfDigits(int n) {
  return n == 0 ? 1 : ceil(log10(abs(n) + 0.5));
}

int method2(int n) {
  int c = getCountsOfDigits(n);
  int d = pow(10, c - 1);
  return n - (n % d);
}

int main(int argc, char *argv[]) {
  const int n = 835047;

  cout << "Method 1: " << method1(n) << endl; // 800000
  cout << "Method 2: " << method2(n) << endl; // 800000

  return 0;
}