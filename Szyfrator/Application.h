
#ifndef SZYFRATOR_APPLICATION_H
#define SZYFRATOR_APPLICATION_H

#include <iostream>
#include <limits>
#include <Windows.h>
#include "EncryptionController.h"

class Application {

public:
    void runApp(); // Funkcja, ktora kontroluje glowne menu i uruchamia funkcje algorithmMenu jesli wybierze sie algorytm, ktory ma zostac wykorzystany

    template<class T>
    void algorithmMenu(EncryptionController<T>& enc); // Funkcja, ktora kontroluje menu odpowiedzialne za wspolprace z algorytmami

};
#endif //SZYFRATOR_APPLICATION_H
