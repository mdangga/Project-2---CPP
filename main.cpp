#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotateMatrixCounterClockwise(vector<vector<int>>& matrix) {
    int n = matrix.size();

    for (int i = 0; i < n; ++i) {
        reverse(matrix[i].begin(), matrix[i].end());
    }

    // Transpose the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(matrix[j][i], matrix[i][j]);
        }
    }
}

void rotateMatrixClockwise(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Transpose the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(matrix[j][i], matrix[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix;
    int rows, cols;

    cout << "Masukkan jumlah baris matriks: ";
    cin >> rows;

    cout << "Masukkan jumlah kolom matriks: ";
    cin >> cols;

    // Mengalokasikan ruang untuk matriks
    matrix.resize(rows, vector<int>(cols));

    cout << "Masukkan elemen-elemen matriks:\n";

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Masukkan elemen matriks [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }

    cout << "Matriks Awal:" << endl;
    printMatrix(matrix);

    int b;
    cout << "Masukkan angka: ";
    cin >> b; // 1. searah jarum jam, 2. berlawanan jarum jam

    if (b == 1) {
        rotateMatrixClockwise(matrix);
        cout << "\nMatriks Setelah Diputar 90 Derajat Clockwise:" << endl;
        printMatrix(matrix);
    } else if (b == 2) {
        rotateMatrixCounterClockwise(matrix);
        cout << "\nMatriks Setelah Diputar 90 Derajat Counter-Clockwise:" << endl;
        printMatrix(matrix);
    } else {
        cout << "Pilihan tidak ada" << endl;
    }

    return 0;
}
