#include <iostream>


using namespace std;

void FillMatrixRow(char* ptr, int size, string& word, int& index, int increment) {
    if (increment < 0)
        ptr += size - 1;
    for (int i = 0; i < size; i++) {
        *ptr = word[index];
        ptr += increment;
        if (index >= word.size() - 1)
            index = 0;
        else
            index++;
    }
}

int main()
{
    int r, c;

    cin >> r >> c; cin.ignore();

    string word;
    getline(cin, word);

    char matrix [r][c];

    int wordIdx = 0;
    int direction = 1;

    for (int i = 0; i < r; i++) {
        FillMatrixRow(&matrix[i][0], c, word, wordIdx, direction);
        direction *= -1;
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}