#include "Reverser.h"

int Reverser::countDigits(int value) {
    if (value < 10) {
        return 1;
    }
    return 1 + countDigits(value / 10);
}

int Reverser::powerOfTen(int exponent) {
    if (exponent == 0) {
        return 1;
    }
    return 10 * powerOfTen(exponent - 1);
}

int Reverser::reverseDigit(int value) {
    if (value < 0) {
        value = -value;
    }

    if (value < 10) {
        return value;
    }

    int digits = countDigits(value);
    return (value % 10) * powerOfTen(digits - 1) + reverseDigit(value / 10);
}

std::string Reverser::reverseString(std::string value) {
    if (value.empty()) {
        return "ERROR";
    }
    if (value.length() <= 1) {
        return value;
    }
    return reverseString(value.substr(1)) + value[0];
}
