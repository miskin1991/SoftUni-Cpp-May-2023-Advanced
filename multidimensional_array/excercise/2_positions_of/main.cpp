#include <iostream>


using namespace std;

int main()
{
    int r, c;

    cin >> r >> c;

    int matrix[r][c];
    
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> matrix[i][j];
        }
    }
    
    int find;

    cin >> find;
    bool found = false;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if (find == matrix[i][j]) {
                cout << i << ' ' << j << endl;
                found = true;
            }
        }
    }

    if (!found)
        cout << "not found" << endl;

    return 0;
}