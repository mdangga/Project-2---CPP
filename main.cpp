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
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int b;
    vector<vector<int>> matrix = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};

    cout << "Matriks Awal:" << endl;
    printMatrix(matrix);
    cout<<"masukkan angka: ";cin>>b;// 1. searah jarum jam, 2. berlawanan jarum jam

    if(b == 1){
        rotateMatrixClockwise(matrix);
        cout << "\nMatriks Setelah Diputar 90 Derajat Clockwise:" << endl;
        printMatrix(matrix);
    }if else(b == 2){
        rotateMatrixCounterClockwise(matrix);
        cout << "\nMatriks Setelah Diputar 90 Derajat Counter-Clockwise:" << endl;
        printMatrix(matrix);
    }else{
        cout<<"pilihan tidak ada"<<endl;
    }


    return 0;
}
