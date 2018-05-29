#include <iostream>
#include <fstream>

using std::cout;
using std::endl;

bool check_k_n_m(int k, int n, int m) {
  // 1 <= n,m <= 10^9
  // 0 <= k <= 1000
  return (k >= 0 && k <= 1000)
          && (n >= 1 && n <= 1e+9)
          && (m >= 1 && m <= 1e+9);
}

bool check_r_c1_c2(int r, int c1, int c2, int n, int m) {
  // 1 <= r <= n
  // 1 <= c1,c2 <= m
  return (r >= 1 && r <= n)
          && (c1 >= 1 && c1 <= m)
          && (c2 >= 1 && c2 <= m);
}

int **createAndFillMatrix(int n, int m) {
  int** matrix = new int*[n];
  for (int i = 0; i < n; i++) {
    matrix[i] = new int[m];

    for (int j = 0; j < m; j++) {
      matrix[i][j] = 0;
    }
  }

  return matrix;
}

int calculateZeros(int **matrix, int n, int m) {
  int result = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] == 0) {
        result++;
      }
    }
  }

  return result;
}

void printMatrix(int **matrix, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cout << "Wrong arguments. Usage: ./matrix[.exe] file_name" << endl;
    return 1;
  }

  std::ifstream file(argv[1]);

  if (!file.is_open()) {
    cout << "Could not open input file" << endl;
    return 1;
  }

  int n = 0,
      m = 0,
      k = 0,
      r = 0,
      c1 = 0,
      c2 = 0,
      result = 0;

  // first line is a: n (rows), m (columns), k (count of tram tracks)
  file >> n >> m >> k;

  if (!check_k_n_m(k, n, m)) {
    cout << "Wrong input data!" << endl;
    return 1;
  }

  int** matrix = createAndFillMatrix(n, m);

  int i = 1;
  while (file >> r >> c1 >> c2) {
    if (i > k) {
      break;
    }

    if (!check_r_c1_c2(r, c1, c2, n, m)) {
      cout << "Wrong input data!" << endl;
      return 1;
    }

    cout << "r: " << r << ", c1: " << c1 << ", c2: " << c2 << endl;
    for (int j = c1 - 1; j < c2; j++) {
      matrix[r - 1][j] = 1;
    }
    
    i++;
  }

  result = calculateZeros(matrix, n, m);

  cout << endl << "Matrix:" << endl;
  printMatrix(matrix, n, m);
  cout << endl << "Result: " << result << endl;

  file.close();

  return 0;
}