
#ifndef SZYFRATOR_ALGORITHMS_H
#define SZYFRATOR_ALGORITHMS_H

#include <string>

class Algorithms { // klasa abstrakcyjna, nie moze istniec sama w sobie
public:
    virtual std::string encryption(std::string inputdata) = 0; // funkcja wirtualna
    virtual std::string decryption(std::string outputdata) = 0; // funkcja wirtualna
};


#endif //SZYFRATOR_ALGORITHMS_H
