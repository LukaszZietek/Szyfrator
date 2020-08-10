

#ifndef SZYFRATOR_CEZARALGORITHM_H
#define SZYFRATOR_CEZARALGORITHM_H


#include "Algorithms.h"

class CezarAlgorithm : public Algorithms { // zaimplementowane dziedziczenie w celu uzyskania polimorfizmu // POLIMORFIZM
private:
    int keyToEncryption;
public:
    explicit CezarAlgorithm(int key = 3); // konstruktor, kt�ry domy�lnie przyjmuje warto�� 3 poniewa� szyfr cezara domy�lnie przesuwa o 3 cyfry
    virtual std::string encryption(std::string inputdata); // funkcja s�u�y do szyfrowania tekstu // POLIMORFIZM
    virtual std::string decryption(std::string outputdata); // funkcja s�u�y do odszyfrowywania tekstu // POLIMORFIZM


};


#endif //SZYFRATOR_CEZARALGORITHM_H

