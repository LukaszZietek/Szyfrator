


#include "MyOwnAlgorithm.h"

MyOwnAlgorithm::MyOwnAlgorithm() : alphanum("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz")
{
}

std::string MyOwnAlgorithm::getRandomSalt(int length) {

    srand((unsigned)time(NULL));
    std::string temp_s;

    for (int i = 0; i < length; ++i)
    {
        temp_s += alphanum[rand() % (alphanum.length() - 1)];
    }

    return temp_s;
}


/* Szyfrowanie dzia³a na zasadzie wygenerowania losowego stringa (salt) o d³ugoœci danych wejœciowych, dodanie wartoœci ka¿dej
 * literki do literki ze s³owa wejœciowego. Dodawanie to odbywa siê modulo zbiory liter alfanumerycznych tzn. ¿e istniej¹ 3 zbiory
 * dodaj¹c wartoœæ losowego stringa poruszamy siê po tych zbiorach wartoœci. Temat opracowany tak, ¿e gdy mamy jak¹œ literkê ze s³owa wejœciowego
 * to odejmujemy od niej wartoœæ pocz¹tku zbioru, dodajemy t¹ wartoœæ do pozosta³ej do dodania wartoœci dziêki czemu zaczynamy od pocz¹tku
 * zbioru, a potem to zwyk³e dodawanie modulo zbiory. Literki z poza zbioru alfanumerycznych pozostawiamy bez zmian. Na koniec do
 * ci¹gu wejœciowego dodawana jest tzw. salt i mieszana za pomoc¹ szyfru przestawieniowego.*/
std::string MyOwnAlgorithm::encryption(std::string inputData)
{
    if (inputData == "" || inputData.length() == 0)
    {
        return inputData;
    }
    std::string salt = getRandomSalt(inputData.length());


    for (int i = 0; i < inputData.length(); ++i)
    {
        if ((inputData[i] >= 'A' && inputData[i] <= 'Z') || (inputData[i] >= '0' && inputData[i] <= '9')
            || (inputData[i] >= 'a' && inputData[i] <= 'z')) // sprawdzanie czy jest alfanumeryczny, jak nie to zostawiamy
        {


            unsigned int flag = 0; // flaga mówi¹ca w którym przedziale powinna byæ wynikowa liczba

            int value = salt[i];

            int j = 0;

            if (inputData[i] >= 48 && inputData[i] <= 57) { // sprawdzanie do ktorego zbioru nalezy
                int helpfulValue = inputData[i] - 48;
                value += helpfulValue;
            }
            else if (inputData[i] >= 65 && inputData[i] <= 90) {
                int helpfulValue = inputData[i] - 65;
                value += helpfulValue;
                j = 1;
            }
            else {
                int helpfulValue = inputData[i] - 97;
                value += helpfulValue;
                j = 2;
            }

            for (j; value > 0; ++j) { // dodawanie modulo zbiory ( odejmowanie sumy pozostalej do dodania)
                if (j % 3 == 0) {
                    value -= 9;
                    flag = 0;
                }
                else if (j % 3 == 1) {
                    value -= 25;
                    flag = 1;
                }
                else {
                    value -= 25;
                    flag = 2;
                }
            }
            if (flag == 0)
            {
                inputData[i] = 57 - abs(value);
            }
            else if (flag == 1)
            {
                inputData[i] = 90 - abs(value);
            }
            else
            {
                inputData[i] = 122 - abs(value);
            }

        }


    }


    inputData += salt;

    for (int i = 0; i < inputData.length() - 1; i += 2) // szyfr przestawieniowy
    {
        std::swap(inputData[i], inputData[i + 1]);
    }

    return inputData;
}

/* Dzia³a na podobnej zasadzie jak kodowanie z tym, ¿e operacje dokonywane s¹ w odwrotnej kolenoœci, i w tym wypadku salt odejmujemy
 * od przechowywanej literki modulo zbiory.*/
std::string MyOwnAlgorithm::decryption(std::string outputData) {
    if (outputData == "" || outputData.length() == 0)
    {
        return outputData;
    }

    for (int i = 0; i < outputData.length() - 1; i += 2) // szyfr przestawieniowy
    {
        std::swap(outputData[i], outputData[i + 1]);
    }

    std::string salt = outputData.substr(outputData.length() / 2, outputData.length()); // wyciagniecie salt


    outputData.erase(outputData.length() / 2, outputData.length());

    for (int i = 0; i < outputData.length(); ++i)
    {
        if ((outputData[i] >= 'A' && outputData[i] <= 'Z') || (outputData[i] >= '0' && outputData[i] <= '9')
            || (outputData[i] >= 'a' && outputData[i] <= 'z')) { // czy nalezy do zbioru alfanumerycznych jak nie to zostawiamy

            unsigned int flag = 0; // flaga mówi¹ca w którym przedziale powinna byæ wynikowa liczba

            int value = salt[i];


            int j = 0;
            if (outputData[i] >= 48 && outputData[i] <= 57) { // wracanie na koniec zbioru i dodawanie wartosci
                int helpfulValue = 57 - outputData[i];
                value += helpfulValue;
                j = 2;
            }
            else if (outputData[i] >= 65 && outputData[i] <= 90) {
                int helpfulValue = 90 - outputData[i];
                value += helpfulValue;
                j = 1;
            }
            else {
                int helpfulValue = 122 - outputData[i];
                value += helpfulValue;
                j = 0;
            }

            for (j; value > 0; ++j) { // odejmowanie salt modulo zbiory ( odejmowanie pozostalej wartosci do odjecia)
                if (j % 3 == 0) {
                    value -= 25;
                    flag = 0;
                }
                else if (j % 3 == 1) {
                    value -= 25;
                    flag = 1;
                }
                else {
                    value -= 9;
                    flag = 2;
                }
            }
            if (flag == 0) {
                outputData[i] = 97 + abs(value);
            }
            else if (flag == 1) {
                outputData[i] = 65 + abs(value);
            }
            else {
                outputData[i] = 48 + abs(value);
            }
        }


    }

    return outputData;

}

