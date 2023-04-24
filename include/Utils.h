#ifndef UTILS_H
#define UTILS_H

#include <math.h>

template<typename ... T> std::string fstring(const char *format, T ... argv)
{
    int nbytes = std::snprintf(nullptr, 0, format, argv...) + 1;
    size_t maxsize = static_cast<size_t>(nbytes);
    char str[maxsize];

    std::snprintf(str, maxsize, format, argv...);

    return std::string(str);
}

int charDigitToInt(char digit)
{
    switch(digit)
    {
        case '0':
            return 0;

        case '1':
            return 1;

        case '2':
            return 2;
        case '3':
            return 3;

        case '4':
            return 4;

        case '5':
            return 5;
        case '6':
            return 6;

        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;

        case 'a':
            return 10;

        case 'b':
            return 11;

        case 'c':
            return 12;

        case 'd':
            return 13;

        case 'e':
            return 14;

        case 'f':
            return 15;

        case 'A':
            return 10;

        case 'B':
            return 11;

        case 'C':
            return 12;

        case 'D':
            return 13;

        case 'E':
            return 14;

        case 'F':
            return 15;

        default:
            return 0;
    }
}

int convertToInt(const char *number, unsigned int length, unsigned int base = 10)
{
    int num = 0;
    bool negative = false;
    char firstDigit = number[0];


    if(firstDigit == '-') negative = true;

    for(int i = 0, j = length - 1; i < length; i++, j--)
    {
        num += charDigitToInt(number[i]) * (int) pow(base, j);
    }

    return negative? -num : num;
}


#endif // UTILS_H
