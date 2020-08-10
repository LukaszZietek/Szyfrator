

#ifndef SZYFRATOR_SECONDALGORITHM_H
#define SZYFRATOR_SECONDALGORITHM_H


#include "Algorithms.h"
#include <algorithm>

class SecondAlgorithm : public Algorithms { //dziedziczenie po klasie abstrakcyjnej // POLIMORFIZM

public:
    virtual std::string encryption(std::string inputdata); // funkcja s³u¿y do szyfrowania tekstu
    virtual std::string decryption(std::string outputdata); // funkcja s³u¿y do odszyfrowywania tekstu

};


#endif //SZYFRATOR_SECONDALGORITHM_H
