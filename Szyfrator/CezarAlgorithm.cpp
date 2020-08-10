
#include "CezarAlgorithm.h"

CezarAlgorithm::CezarAlgorithm(int key)
{
    if (key >= 0) {                      // jako, �e klucze nie mo�e by� ujemny to w zale�no��i od podanego klucza inicjalizuj� jego warto�ci� albo
        keyToEncryption = key;          // jego odwrotno�ci�.
    }
    else
    {
        keyToEncryption = -key;
    }
}


std::string CezarAlgorithm::encryption(std::string inputdata)
{

    for (int i = 0; i < inputdata.length(); i++)  // przeszukuje ca�� d�ugo�� podanego string-a i je�li mie�ci si� w przedziale alfabetu to zmienia a
    {                                           // je�li nie to pozostawia bez zmian
        if (inputdata[i] >= 'A' && inputdata[i] <= 'Z')
        {
            if (inputdata[i] + keyToEncryption <= 'Z')  // sprawdza czy dodanie klucza nie spowoduje wyj�cia poza alfabet
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
std::string CezarAlgorithm::decryption(std::string outputdata) // dzia�a analogicznie jak inputdata tylko w drug� stron�. odejmuje zamiast dodawa�.
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