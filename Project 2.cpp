#ifdef _WIN32
#include <windows.h>
#endif
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
void putarMatriksSearahJarumJam(vector<vector<long long>>& matriks);
void putarmatriksBerlawananJarumJam(vector<vector<long long>>& matriks);
void putarMatriks180Derajat(vector<vector<long long>>& matriks);
void cetakMatriks(const vector<vector<long long>>& matriks, const string& label);
bool numeric(const string& str);
void cetakHeader(const string& text);
void pilihWarna(int warna);
void kembalikanWarna();

int main() {
    char Pilihan;

    do {
        system("cls");
        int b;
        vector<vector<long long>> matriks;
        int rows, cols;

        cetakHeader("Program Rotated Matriks");

        cout << "Masukkan jumlah baris matriks: ";
        string inputRows;
        cin >> inputRows;
        while (!numeric(inputRows) && stoi(inputRows) != 0) {
            pilihWarna(4);
            cout << "Input harus berupa angka. Masukkan input baris dengan benar : ";
            kembalikanWarna();
            cin >> inputRows;
        }
        rows = stoi(inputRows);
        cout << "Masukkan jumlah kolom matriks: ";
        string inputCols;
        cin >> inputCols;
        while (!numeric(inputCols) && stoi(inputCols) != 0) {
            pilihWarna(4);
            cout << "Input harus berupa angka. Masukkan input kolom dengan benar : ";
            kembalikanWarna();
            cin >> inputCols;
        }
        cols = stoi(inputCols);
        matriks.resize(rows, vector<long long>(cols));


        cout << "Masukkan elemen-elemen matriks:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "Masukkan elemen matriks [" << i + 1 << "][" << j + 1 << "]: ";
                string element;
                cin >> element;

        while (!(numeric(element) || (element[0] == '-' && numeric(element.substr(1))))) {
            pilihWarna(4);  // Red text
            cout << "Input harus berupa angka. Masukkan elemen matriks dengan benar: ";
            kembalikanWarna();
            cin >> element;
        }

        matriks[i][j] = stoll(element);
    }
}


        cetakMatriks(matriks, "Matriks Awal");
        cetakHeader("Silahkan Dipilih");
        cout << "1. Clockwise(90)\n2. Counter Clockwise(90)\n3. Rotated 180\n";
        cout << "Masukkan Pilihan Anda: ";
        cin >> b;

        if (b == 1) {
            putarMatriksSearahJarumJam(matriks);
            pilihWarna(2);
            cetakMatriks(matriks, "Matriks Setelah Diputar 90 Derajat Clockwise");
            kembalikanWarna();
        } else if (b == 2) {
            putarmatriksBerlawananJarumJam(matriks);
            pilihWarna(2);
            cetakMatriks(matriks, "Matriks Setelah Diputar 90 Derajat Counter-Clockwise");
            kembalikanWarna();
        } else if (b == 3) {
            putarMatriks180Derajat(matriks);
            pilihWarna(2);
            cetakMatriks(matriks, "Matriks Setelah Diputar 180 Derajat Counter-Clockwise");
            kembalikanWarna();
        } else {
            pilihWarna(1);
            cout << "Pilihan tidak ada" << endl;
            kembalikanWarna();
        }

        cout << "\nApakah Anda ingin melanjutkan (y for yes / any key for no)? ";
        cin >> Pilihan;
    } while (Pilihan == 'y' || Pilihan == 'Y');

    return 0;
}


void putarMatriksSearahJarumJam(vector<vector<long long>>& matriks) {
    int n = matriks.size();

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(matriks[j][i], matriks[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        reverse(matriks[i].begin(), matriks[i].end());
    }
}

void putarmatriksBerlawananJarumJam(vector<vector<long long>>& matriks) {
    int n = matriks.size();

    for (int i = 0; i < n; ++i) {
        reverse(matriks[i].begin(), matriks[i].end());
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(matriks[j][i], matriks[i][j]);
        }
    }
}
void putarMatriks180Derajat(vector<vector<long long>>& matriks) {
    int n = matriks.size();

    for (int i = 0; i < n; ++i) {
        reverse(matriks[i].begin(), matriks[i].end());
    }

    reverse(matriks.begin(), matriks.end());
}


void cetakMatriks(const vector<vector<long long>>& matriks, const string& label) {
    int rows = matriks.size();
    int cols = matriks[0].size();

    pilihWarna(3);
    cout <<"\n"<< label << ":\n";
    kembalikanWarna();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(4) << matriks[i][j] << " ";
        }
        cout << endl;
    }
}

void cetakHeader(const string& text) {
    int consoleWidth = 80;
    int padding = ((consoleWidth - text.length() - 8) / 2);
    cout<<endl;
    pilihWarna(6);
    cout << " <==" << setw(padding) << "" << text << setw(padding) << "" << "==> "<<endl<<endl;
    kembalikanWarna();
}

bool numeric(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

void pilihWarna(int warna) {
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), warna);
#else
    cout << "\033[1;" << warna << "m";
#endif
}

void kembalikanWarna() {
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
#else
    cout << "\033[0m";
#endif
}
