#include <iostream>


using namespace std;

bool AllElementsAreEqual(char m[2][2])
{
    return (
        m[0][0] == m[0][1] &&
        m[0][0] == m[1][0] && 
        m[0][0] == m[1][1]
    );
}

int main()
{
    int r, c;

    cin >> r >> c;

    char matrix[r][c];
    
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> matrix[i][j];
        }
    }

    int total = 0;

    for(int i = 0; i < r - 1; i++) {
        for(int j = 0; j < c - 1; j++) {
            char m[2][2] { matrix[i][j], matrix[i][j + 1], matrix[i + 1][j], matrix[i + 1][j + 1]};
            bool result {AllElementsAreEqual(m)};
            total += static_cast<int>(result);
        }
    }

    cout << total << endl;

    return 0;
}

/*
3 4
A B B D 
E B B B 
I J B B

*/