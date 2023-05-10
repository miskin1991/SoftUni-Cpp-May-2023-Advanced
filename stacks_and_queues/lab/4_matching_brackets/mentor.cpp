#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

int main()
{
    string input;
    getline(cin, input);

    stack<string> myStack;
    string curStr, auxStr;

    for (int i = 0; i < input.length(); i++)
    {
        switch (input[i])
        {
            case '(':
                if(curStr.length())
                {
                    myStack.push(curStr);
                    curStr.clear();
                }
                curStr.push_back(input[i]);
                break;
            case ')':
                curStr.push_back(input[i]);
                auxStr.append(curStr);
                std::cout << curStr << std::endl;
                if (myStack.size())
                {
                    curStr = myStack.top();
                    myStack.pop();   
                    curStr.append(auxStr);
                    auxStr.clear();
                }
                break;
            default:
                curStr.push_back(input[i]);
                break;
        }
    }

    return 0;
}