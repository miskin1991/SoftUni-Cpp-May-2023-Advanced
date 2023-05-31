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

    // calculate primary diagonal
    int sumPrimary = 0;
    for (size_t i = 0, j = 0; i < size; i++, j++) {
        sumPrimary += matrix[i][j];
    }

    // calculate secondary diagonal
    int sumSecondary = 0;
    for (size_t i = 0, j = size - 1; i < size; i++, j--) {
        sumSecondary += matrix[i][j];
    }
    
    int diference = abs(sumPrimary - sumSecondary);
    cout << diference << endl;
        
    return 0;
}