
#include "CezarAlgorithm.h"

CezarAlgorithm::CezarAlgorithm(int key)
{
    if (key >= 0) {                      // jako, ¿e klucze nie mo¿e byæ ujemny to w zale¿noœæi od podanego klucza inicjalizujê jego wartoœci¹ albo
        keyToEncryption = key;          // jego odwrotnoœci¹.
    }
    else
    {
        keyToEncryption = -key;
    }
}


std::string CezarAlgorithm::encryption(std::string inputdata)
{

    for (int i = 0; i < inputdata.length(); i++)  // przeszukuje ca³¹ d³ugoœæ podanego string-a i jeœli mieœci siê w przedziale alfabetu to zmienia a
    {                                           // jeœli nie to pozostawia bez zmian
        if (inputdata[i] >= 'A' && inputdata[i] <= 'Z')
        {
            if (inputdata[i] + keyToEncryption <= 'Z')  // sprawdza czy dodanie klucza nie spowoduje wyjœcia poza alfabet
            {
                inputdata[i] += keyToEncryption;
            }
            else
            {
                inputdata[i] = inputdata[i] + keyToEncryption - 26; // zastosowanie w sytuacji gdy dodanie klucza powoduje wyjscie poza alfabet
            }

        }
        else if (inputdata[i] >= 'a' && inputdata[i] <= 'z')
        {
            if (inputdata[i] + keyToEncryption <= 'z')
            {
                inputdata[i] += keyToEncryption;
            }
            else
            {
                inputdata[i] = inputdata[i] + keyToEncryption - 26;
            }


        }

    }
    return inputdata;
}
std::string CezarAlgorithm::decryption(std::string outputdata) // dzia³a analogicznie jak inputdata tylko w drug¹ stronê. odejmuje zamiast dodawaæ.
{
    for (int i = 0; i < outputdata.length(); i++)
    {
        if (outputdata[i] >= 'A' && outputdata[i] <= 'Z')
        {
            if (outputdata[i] - keyToEncryption >= 'A')
            {
                outputdata[i] -= keyToEncryption;
            }
            else
            {
                outputdata[i] = outputdata[i] + 26 - keyToEncryption;
            }

        }
        else if (outputdata[i] >= 'a' && outputdata[i] <= 'z')
        {
            if (outputdata[i] - keyToEncryption >= 'a')
            {
                outputdata[i] -= keyToEncryption;
            }
            else
            {
                outputdata[i] = outputdata[i] + 26 - keyToEncryption;
            }


        }

    }
    return outputdata;
}