#pragma once

#ifndef SZYFRATOR_MYOWNALGORITHM_H
#define SZYFRATOR_MYOWNALGORITHM_H

#include "Algorithms.h"
#include <time.h>
#include <stdlib.h>

class MyOwnAlgorithm : public Algorithms {
private:
    const std::string alphanum;
    std::string getRandomSalt(int length);
public:
    MyOwnAlgorithm();
    virtual std::string encryption(std::string inputData);
    virtual std::string decryption(std::string outputData);

};


#endif //SZYFRATOR_MYOWNALGORITHM_H


