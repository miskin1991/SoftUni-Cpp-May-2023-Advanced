#include <iostream>

using namespace std;

int main()
{
    int rows, cols;

    cin >> rows >> cols; cin.ignore();

    int matrix[rows][cols];
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            cin >> matrix[i][j];

    for (size_t j = 0; j < cols; j++) {
        int sum = 0;
        for (size_t i = 0; i < rows; i++)
            sum += matrix[i][j];
        cout << sum << endl;
    }
        
    return 0;
}