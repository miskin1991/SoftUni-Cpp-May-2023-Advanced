#include <iostream>
#include <sstream>
#include <stack>

void ProcessIntegerFromInput(std::stringstream& stream, std::stack<int>& stack)
{
    std::string input;
    stream >> input;
    stack.push(atoi(input.c_str()));
    return;
}

int main()
{
    std::stack<int> addStack;
    std::stack<int> removeStack;
    std::string input;
    int sum { 0 };

    // start processing
    getline(std::cin, input);
    std::stringstream myStream(input);
    
    myStream >> input;
    // we set the first value at sum already.
    sum = atoi(input.c_str());

    while(myStream >> input)
    {
        if (input == "-")
        {
            ProcessIntegerFromInput(myStream, removeStack);
        }
        else if (input == "+")
        {
            ProcessIntegerFromInput(myStream, addStack);
        }
        else
        {
            std::cout << "invalid operand -> exit with error" << std::endl;
            return -1;
        }
    }

    while (!addStack.empty())
    {
        sum += addStack.top();
        addStack.pop();
    }

    while (!removeStack.empty())
    {
        sum -= removeStack.top();
        removeStack.pop();
    }

    std::cout << sum << std::endl;

    return 0;
}