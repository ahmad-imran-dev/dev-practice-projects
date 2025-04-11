#ifndef CONSOLE_H // Prevent duplicate inclusion
#define CONSOLE_H

#include <iostream>

struct console_structure
{
    template <typename P>
    void output(P val, bool newLine = false)
    {
        std::cout << val;
        if (newLine)
            std::cout << std::endl;
    }

    template <typename T>
    T input(std::string msg, bool newLine = false)
    {
        output(msg, newLine);
        T val;
        std::getline(std::cin, val);
        return val;
    }
};

console_structure console;

#endif