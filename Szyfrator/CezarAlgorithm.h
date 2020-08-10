

#ifndef SZYFRATOR_CEZARALGORITHM_H
#define SZYFRATOR_CEZARALGORITHM_H


#include "Algorithms.h"

class CezarAlgorithm : public Algorithms { // zaimplementowane dziedziczenie w celu uzyskania polimorfizmu // POLIMORFIZM
private:
    int keyToEncryption;
public:
    explicit CezarAlgorithm(int key = 3); // konstruktor, który domyœlnie przyjmuje wartoœæ 3 poniewa¿ szyfr cezara domyœlnie przesuwa o 3 cyfry
    virtual std::string encryption(std::string inputdata); // funkcja s³u¿y do szyfrowania tekstu // POLIMORFIZM
    virtual std::string decryption(std::string outputdata); // funkcja s³u¿y do odszyfrowywania tekstu // POLIMORFIZM


};


#endif //SZYFRATOR_CEZARALGORITHM_H

