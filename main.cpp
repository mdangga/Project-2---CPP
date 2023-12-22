#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotateMatrixCounterClockwise(vector<vector<int>>& matrix, int rows, int cols) {
    int n = matrix.size();

    for (int i = 0; i < rows; ++i) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    // Transpose the matrix
    for (int i = 0; i < rows; ++i) {
        for (int j = i + 1; j < cols; ++j) {
            swap(matrix[j][i], matrix[i][j]);
        }
    }

}
void rotateMatrixClockwise(vector<vector<int>>& matrix, int rows, int cols) {
    int n = matrix.size();

    // Transpose the matrix
    for (int i = 0; i < rows; ++i) {
        for (int j = i + 1; j < cols; ++j) {
            swap(matrix[j][i], matrix[i][j]);
        }
    }
    for (int i = 0; i < rows; ++i) {
        reverse(matrix[i].begin(), matrix[i].end());
    }

}

void printMatrix(const vector<vector<int>>& matrix, int rows, int cols) {
    int n = matrix.size();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void fungsi1(){
    //vector<vector<int>> matrix = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    vector<vector<int>>matrix;
    int rows, cols;

    cout << "Masukkan jumlah baris matriks: ";
    cin >> rows;
    cin.ignore();

    cout << "Masukkan jumlah kolom matriks: ";
    cin >> cols;
    cin.ignore();

    // Mengalokasikan ruang untuk matriks
    matrix.resize(rows, vector<int>(cols));

    cout << "Masukkan elemen-elemen matriks:\n";

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Masukkan elemen matriks [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
            cin.ignore();
        }
    }

    cout << "Matriks Awal:" << endl;
    printMatrix(matrix, rows, cols);
     int b;
    cout<<"masukkan angka: ";cin>>b;cin.ignore();// 1. searah jarum jam, 2. berlawanan jarum jam

    if(b == 1){
        rotateMatrixClockwise(matrix, rows, cols);
        cout << "\nMatriks Setelah Diputar 90 Derajat Clockwise:" << endl;
        printMatrix(matrix, rows, cols);
    }else if(b == 2){
        rotateMatrixCounterClockwise(matrix, rows, cols);
        cout << "\nMatriks Setelah Diputar 90 Derajat Counter-Clockwise:" << endl;
        printMatrix(matrix, rows, cols);
    }else{
        cout<<"pilihan tidak ada"<<endl;
    }
}

int main() {
    char per;

    do {
        fungsi1();

        cout << "Apakah anda ingin mengulang? (y/n): ";
        cin >> per;

        if (per == 'y' || per == 'Y') {
            system("cls");
        }

    } while (per == 'y' || per == 'Y');
}
