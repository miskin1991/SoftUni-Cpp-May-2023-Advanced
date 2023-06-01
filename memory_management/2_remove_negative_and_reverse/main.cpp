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

    bool print = false;
    for (int j = elements - 1; j > -1; j--) {
        if (arr[j] > 0) {
            cout << arr[j] << ' ';
            print = true;
        }
    }

    if (!print)
        cout << "empty";
    cout << endl;

    delete[] arr;

    return 0;
}