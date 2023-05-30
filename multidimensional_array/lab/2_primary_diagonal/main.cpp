#include <iostream>

using namespace std;

int main()
{
    int size;

    cin >> size; cin.ignore();

    int matrix[size][size];
    for (size_t i = 0; i < size; i++)
        for (size_t j = 0; j < size; j++)
            cin >> matrix[i][j];

    int sum = 0;
    for (size_t i = 0, j = 0; i < size; i++, j++) {
        sum += matrix[i][j];
    }
    cout << sum << endl;
        
    return 0;
}