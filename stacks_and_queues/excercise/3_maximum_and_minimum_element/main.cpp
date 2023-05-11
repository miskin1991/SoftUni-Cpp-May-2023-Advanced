#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

int GetMaximum(stack<int> myStack)
{
    int maximum = INT32_MIN;

    while (myStack.size())
    {
        myStack.top() > maximum ? maximum = myStack.top() : maximum;
        myStack.pop();
    }

    return maximum;
}

int GetMinimum(stack<int> stack)
{
    int minimum = INT32_MAX;

    while (stack.size())
    {
        stack.top() < minimum ? minimum = stack.top() : minimum;
        stack.pop();
    }

    return minimum;
}

int main()
{
    string input;
    int iterations;
    int command, number;
    stack<int> numbers;

    cin >> iterations;

    while(iterations--)
    {
        cin >> command;

        switch (command)
        {
        case 1:
            cin >> number;
            numbers.push(number);
            break;
        case 2:
            if(numbers.size())
                numbers.pop();
            break;
        case 3:
            if (numbers.size())
                cout << GetMaximum(numbers) << endl;
            break;
        case 4:
            if (numbers.size())
                cout << GetMinimum(numbers) << endl;
            break;
        default:
            break;
        }

    }

    while (numbers.size())
    {
        cout << numbers.top();
        numbers.pop();
        if (numbers.size())
            cout << ", ";
    }
    cout << endl;

    return 0;
}