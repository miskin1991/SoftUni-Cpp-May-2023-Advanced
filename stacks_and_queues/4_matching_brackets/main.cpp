#include <iostream>
#include <sstream>
#include <stack>

bool SearchForStartAndEnd(const std::string& input, int& start, int& end)
{
    int counter { 0 };
    start = 0;
    end = 0;
    for(int i { 0 }; i < input.length(); i++)
    {
        if (input[i] == '(')
        {
            if(!counter)
                start = i;
            counter++;
        }
        else if (input[i] == ')')
        {
            counter--;
            if (!counter)
            {
                end = i;
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
        remainingStr = input.substr(end + 1);
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