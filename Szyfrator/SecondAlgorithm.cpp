

#include "SecondAlgorithm.h"

std::string SecondAlgorithm::encryption(std::string inputdata) // szyfruje dane poprzez zamiane miejscami s¹siaduj¹cych ze sob¹ liter
{
    if (inputdata.length() != 0)
    {

        for (int i = 0; i < inputdata.length() - 1; i += 2)
        {
            std::swap(inputdata[i], inputdata[i + 1]);
        }


    }
    else
    {
        throw 5;
    }

    return inputdata;

}
std::string SecondAlgorithm::decryption(std::string outputdata) // odszyfrowuje dane poprzez zamiane miejscami s¹siaduj¹cych ze sob¹ liter.
{
    if (outputdata.length() != 0)
    {
        for (int i = 0; i < outputdata.length() - 1; i += 2)
        {
            std::swap(outputdata[i], outputdata[i + 1]);
        }

    }
    else
    {
        throw 5;
    }
    return outputdata;
}