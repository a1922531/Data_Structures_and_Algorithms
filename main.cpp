#include <iostream>
#include <string>
#include "Truckloads.h"
#include "Reverser.h"

int main() {
    std::cout << "Truckloads tests:" << std::endl;
    Truckloads test;
    std::cout << test.numTrucks(14, 3) << std::endl;

    Truckloads test2;
    std::cout << test2.numTrucks(15, 1) << std::endl;

    Truckloads test3;
    std::cout << test3.numTrucks(1024, 5) << std::endl;

    std::cout << "\nReverser tests:" << std::endl;
    Reverser r;
    std::cout << r.reverseDigit(12345) << std::endl;
    std::cout << r.reverseString("hello") << std::endl;
    std::cout << r.reverseString("") << std::endl;

    return 0;
}
