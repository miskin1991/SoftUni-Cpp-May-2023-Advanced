#include <iostream>
#include <sstream>

using namespace std;

const int MAX_DIM = 10;

bool IsEqual(int m1[MAX_DIM][MAX_DIM], size_t m1rows, size_t m1cols,
                int m2[MAX_DIM][MAX_DIM], size_t m2rows, size_t m2cols) {
    if (m1cols != m2cols || m1rows != m2rows)
        return false;
    
    for (int i = 0; i < m1rows; i++)
        for (int j = 0; j < m1cols; j++) {
            if (m1[i][j] != m2[i][j])
                return false;
        }
    
    return true;
}

void FillMatrix(int matrix[MAX_DIM][MAX_DIM], size_t size, size_t& raws, size_t& cols) {
    for (size_t i = 0; i < size; i++) {
        string line;
        int value;
        getline(cin, line);
        stringstream sstr(line);
        int j = 0;
        while(sstr >> value) {
            matrix[i][j] = value;
            j++;
        }
        cols = j;
    }
    raws = size;
    return;
}

int main()
{
    size_t m1Size, m2Size;
    size_t m1rows, m1cols, m2rows, m2cols;
    int m1[MAX_DIM][MAX_DIM], m2[MAX_DIM][MAX_DIM];
    string line;
    getline(cin, line);
    stringstream sstr(line);
    sstr >> m1Size; sstr.str(""); sstr.clear();
    FillMatrix(m1, m1Size, m1rows, m1cols);
    getline(cin, line);
    sstr.str(line);
    sstr >> m2Size; sstr.str(""); sstr.clear();
    FillMatrix(m2, m2Size, m2rows, m2cols);
    
    if (IsEqual(m1, m1rows, m1cols, m2, m2rows, m2cols))
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;

    return 0;
}