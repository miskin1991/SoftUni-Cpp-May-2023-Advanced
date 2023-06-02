#include <iostream>
#include <sstream>

using namespace std;

char** CreateMatrix(istream& buffer, size_t& rows, size_t& cols) {
    buffer >> rows >> cols; buffer.ignore();

    char** matrix = new char*[rows];

    for (int i = 0; i < rows; i++) {
        matrix[i] = new char[cols];
        string input;
        getline(buffer, input);
        stringstream sstr(input);
        char value = 0;
        for (int j = 0; j < cols; j++) {
            sstr >> value;
            matrix[i][j] = value;
        }
    }

    return matrix;
}

void DeleteMatrix(char** matrix, size_t& rows) {
    for(int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
    return;
}

void DeleteMatrix(int** matrix, size_t& rows) {
    for(int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
    return;
}

void PrintMatrix(char** matrix, size_t& rows, size_t& cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

void PrintMatrix(int** matrix, size_t& rows, size_t& cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

void MarkMine(int** counters, size_t r, size_t c) {
    counters[r][c]++;
}

void FindMines(char** mines, size_t& rows, size_t& cols, int** counters) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mines[i][j] == '.')
                continue;
            if(i) {
                if(j)
                    MarkMine(counters, i-1, j-1);
                MarkMine(counters, i-1, j);
                if(j < cols - 1)
                    MarkMine(counters, i-1, j+1);
            }

            if(j)
                MarkMine(counters, i, j-1);
            MarkMine(counters, i, j);
            if(j < cols - 1)
                MarkMine(counters, i, j+1);
            
            if(i < rows - 1) {
                if(j)
                    MarkMine(counters, i+1, j-1);
                MarkMine(counters, i+1, j);
                if(j < cols - 1)
                    MarkMine(counters, i+1, j+1);
            }
        }
    }
}

int main() {
    size_t r1 = 0, c1 = 0;
    char** m1 = CreateMatrix(cin, r1, c1);
    int** m2 = new int*[r1];
    for (int i = 0; i < r1; i++) {
        m2[i] = new int[c1] { 0 };
    }

    FindMines(m1, r1, c1, m2);

    // PrintMatrix(m1, r1, c1);
    PrintMatrix(m2, r1, c1);
    DeleteMatrix(m1, r1);
    DeleteMatrix(m2, r1);

    return 0;
}

/*
5 5
.....
...!.
.....
.....
.....

5 5
.....
....!
.....
.....
.....

5 8
........
...!....
....!...
........
...!....
*/