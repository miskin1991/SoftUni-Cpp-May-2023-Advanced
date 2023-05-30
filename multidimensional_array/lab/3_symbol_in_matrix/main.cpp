#include <iostream>

using namespace std;

int main()
{
    int size;

    cin >> size; cin.ignore();

    char matrix[size][size];
    for (size_t i = 0; i < size; i++)
        for (size_t j = 0; j < size; j++)
            cin >> matrix[i][j];

    char symbol;
    cin >> symbol; cin.ignore();

    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            if (matrix[i][j] == symbol) {
                cout << '(' << i << ", " << j << ')' << endl;
                return 0;
            }
        }
    }

    cout << symbol << " does not occur in the matrix" << endl;

    return 0;
}