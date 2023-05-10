#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

std::vector<std::string> ReadInput()
{
    std::vector<std::string> words;
    std::string input;
    getline(std::cin, input);
    std::stringstream myStream(input);
    
    while (myStream >> input)
    {
        words.push_back(input);
    }

    return words;
}

void PrintReverseInput(std::vector<std::string>& words)
{
    std::stack<std::string> myStack;
    
    for (std::string& word : words) 
    {
        std::reverse(word.begin(), word.end());
        myStack.push(word);
    }

    while(!myStack.empty())
    {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }
    std::cout << std::endl;

    return;
}

int main()
{
    std::vector<std::string> words = ReadInput();
    PrintReverseInput(words);
}