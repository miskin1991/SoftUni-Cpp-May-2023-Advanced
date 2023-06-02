#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string input;
    string text;

    while(true) {
        getline(cin, input);

        if (input == "###")
            break;
        
        stringstream sstr(input);
        while(sstr >> input) {
            text.append(input);
            text.append(" ");
        }
    }

    int lineSize;
    cin >> lineSize; cin.ignore();

    stringstream sstr(text);
    size_t currCount = 0, count = 0;
    while(sstr >> input) {
        count = currCount + input.size();
        if (count > lineSize) {
            cout << endl;
            currCount = input.size();
            cout << input;
        } else {
            cout << input;
            currCount = count;
        }
        cout << ' '; currCount++;
    }

    return 0;
}

/*
D/1770 L1, popularly known as Lexell's 
Comet after its orbit computer Anders Johan 
Lexell, was a comet discovered by astronomer Charles Messier in June
1770.[note 1] It is notable for having passed closer to Earth than any other
comet in recorded history, approaching to a distance of only 0.015
astronomical 
units 
(2,200,000 km;
1,400,000 mi).[1][3][4] The comet has not been seen since 1770 and is considered a lost comet.
###
38

every     word   in this text is
too  wide
    to    
fit in  the   line width
###
1


*/