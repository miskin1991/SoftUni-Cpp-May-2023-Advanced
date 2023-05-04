#include <iostream>
#include <sstream>
#include <queue>

int main()
{
    std::string input;
    std::getline(std::cin, input);
    std::stringstream myStream(input);
    std::queue<int> myQueue;

    while (myStream >> input)
    {
        int value { atoi(input.c_str()) };
        if (value % 2 == 0)
            myQueue.push(value);
    }

    while (myQueue.size() > 1)
    {
        std::cout << myQueue.front() << ", ";
        myQueue.pop();
    }
    std::cout << myQueue.front() << std::endl;
    myQueue.pop();

    return 0;
}