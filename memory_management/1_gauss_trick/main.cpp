#include <iostream>
#include <sstream>

using namespace std;

int main() {
    int* arr = new int[1000];
    string input;
    getline(cin, input);
    stringstream sstr(input);
    int value;

    int elements = 0;
    while (sstr >> value ) {
        arr[elements] = value;
        elements++;
    }

    for (int i = 0, j = elements - 1; i < elements / 2; i++, j--)
    {
        cout << arr[i] + arr[j] << ' ';
    }

    if (elements % 2)
        cout << arr[(elements / 2)];
    
    cout << endl;

    return 0;
}