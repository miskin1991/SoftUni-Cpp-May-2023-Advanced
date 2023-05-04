#include <iostream>
#include <sstream>
#include <stack>

bool SearchForStartAndEnd(const std::string& input, int& start, int& end)
{
    int counter { 0 };
    start = 0;
    end = 0;
    for(size_t i { input.length() - 1 }; i != 0; i--)
    {
        if (input[i] == ')')
        {
            if(!counter)
                end = i;
            counter++;
        }
        else if (input[i] == '(')
        {
            counter--;
            if (!counter)
            {
                start = i;
                break;
            }
            
        }
    }

    return (start != end);
}

void FindExpression(const std::string& input, std::stack<std::string>& stack)
{
    int start = 0;
    int end = 0;
    bool result = false;
    std::string remainingStr;

    result = SearchForStartAndEnd(input, start, end);
    
    if (result)
    {
        remainingStr = input.substr(0, start);
        std::string currentStr(input.substr(start + 1, end - start - 1));
        stack.push(currentStr);
        FindExpression(currentStr, stack);
        if (remainingStr.length() > 0)
        {
            FindExpression(remainingStr, stack);
        }
    }
    else
    {
        if (remainingStr.length() > 0)
        {
            FindExpression(remainingStr, stack);
        }
    }

    return;
}

int main()
{
    std::string input;
    std::stack<std::string> myStack;
    getline(std::cin,input);
    FindExpression(input, myStack);
    while(!myStack.empty())
    {
        std::cout << "(" << myStack.top() << ")" << std::endl;
        myStack.pop();
    }
    return 0;
}