#include <iostream>
#include <memory>

using namespace std;

int main() {
    int n, m, value;

    cin >> n >> m;

    unique_ptr<int[]> matrix(new int[n*m]);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> value;
            matrix[i*m + j] = value;
        }
    }

    int r, c;

    cin >> r >> c;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << matrix[i*m + j] << ' ';
        }
        cout << endl;
    }
    return 0;
}

/*
3 4 
1 2 3 4 
11 22 33 44
111 222 333 444 
3 3

4 4 
2 2 2 2 
5 6 7 8 
0 1 0 2 
9 7 5 3 
2 4

4 4 
2 2 2 2 
5 6 7 8 
0 1 0 2 
9 7 5 3 
4 2
*/