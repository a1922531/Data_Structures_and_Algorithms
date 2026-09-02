#ifndef REVERSER_H
#define REVERSER_H

#include <string>

class Reverser {
public:
    int reverseDigit(int value);
    std::string reverseString(std::string value);

private:
    int countDigits(int value);
    int powerOfTen(int exponent);
};

#endif
