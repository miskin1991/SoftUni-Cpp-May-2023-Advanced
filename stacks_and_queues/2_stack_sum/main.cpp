#include <iostream>
#include <sstream>
#include <stack>

void ProcessIntegerFromInput(std::stringstream& stream, std::stack<int>& stack)
{
    std::string input;
    while (stream >> input)
    {
        stack.push(atoi(input.c_str()));
    }
    return;
}

void ReadInitialInput(std::stack<int>& stack)
{
    std::string input;
    getline(std::cin, input);
    std::stringstream myStream(input);
    ProcessIntegerFromInput(myStream, stack);    
    return;
}

void ReadOperationalInput(std::stack<int>& stack)
{
    const std::string delimiter { "end" };

    while(true)
    {
        std::string input;
        getline(std::cin, input);
        std::stringstream myStream(input);
        std::string operation;
        myStream >> operation;

        for (char& letter : operation)
        {
            letter = std::tolower(letter);
        }

        if(operation == delimiter)
        {
            break;
        }
        else if (operation == "add")
        {
            ProcessIntegerFromInput(myStream, stack);
        }
        else if (operation == "remove")
        {
            myStream >> input;
            int elements { atoi(input.c_str()) };
            
            if (elements > 0 && elements < stack.size())
            {
                while (elements > 0)
                {
                    stack.pop();
                    elements--;
                }
            }
        }
        else
        {
            std::cout << "Wrong operation" << std::endl;
        }
    }
  
    return;
}


int main()
{
    std::stack<int> addStack;
    ReadInitialInput(addStack);
    ReadOperationalInput(addStack);
    
    int sum { 0 };
    while(!addStack.empty())
    {
        sum += addStack.top();
        addStack.pop();
    }

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}