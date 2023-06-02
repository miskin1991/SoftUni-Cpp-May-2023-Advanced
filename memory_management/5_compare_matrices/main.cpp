#include <iostream>
#include <sstream>

using namespace std;

int** ReadMatrix(istream& buffer, size_t& rows, size_t& cols) {
    buffer >> rows; buffer.ignore();

    int** matrix = new int*[rows];

    for (int i = 0; i < rows; i++) {
        string input;
        getline(buffer, input);
        stringstream sstr(input);
        int value = 0;
        cols = 0;
        matrix[i] = new int[10];
        while(sstr >> value) {
            matrix[i][cols] = value;
            cols++;
        }
    }

    return matrix;
}

void DeleteMatrix(int** matrix, size_t& rows) {
    for(int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
    return;
}

void PrintMatrix(int** matrix, size_t& rows, size_t& cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

bool EqualMatrix(int** m1, size_t& r1, size_t& c1, int** m2, size_t& r2, size_t& c2) {
    if (r1 != r2 || c1 != c2)
        return false;
    
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            if (m1[i][j] != m2[i][j])
                return false;
        }
    }

    return true;
}

int main() {
    size_t r1 = 0, c1 = 0, r2 = 0, c2 = 0;
    int** m1 = ReadMatrix(cin, r1, c1);
    int** m2 = ReadMatrix(cin, r2, c2);
    // PrintMatrix(m1, r1, c1);
    // PrintMatrix(m2, r2, c2);

    bool equal { EqualMatrix(m1, r1, c1, m2, r2, c2)};

    cout << (equal ? "equal" : "not equal") << endl;

    return 0;
}