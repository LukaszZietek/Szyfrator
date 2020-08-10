

#include "Tests.h"
#include "DatabaseModel.h"
#include "EncryptionController.h"

/*
void Tests::Test1() { // Testuje zapisywanie do pliku
    DatabaseModel db;
    db.addToDatabase("Hello");
    db.addToDatabase("World");
    db.saveToTheFile();


}


void Tests::Test2() { // Testuje odczytywanie z pliku
    DatabaseModel db;
    db.readFromFile();
    std::cout << db;


}

void Tests::Test3() { // Testuje usuwanie elementu
    DatabaseModel db;
    db.readFromFile();
    std::cout << db;
    db.deleteFromDatabase(1);
    db.deleteFromDatabase(1);
    std::cout << "Usunalem" << std::endl;
    std::cout << db;
}

void Tests::TestSecondAlgorithm() {
    Algorithms * algorytmy;
    SecondAlgorithm sa;
    algorytmy = &sa;
    std::string szyfrowanie = "Ala ma kota";
    szyfrowanie = algorytmy->encryption(szyfrowanie);
    std::cout << "Zaszyfrowane: " << szyfrowanie << std::endl;
    szyfrowanie = algorytmy->decryption(szyfrowanie);
    std::cout << "Odszyfrowane: " << szyfrowanie << std::endl;

}

void Tests::TestCezarAlgorithm() {
    Algorithms * algorytmy;
    CezarAlgorithm sa;
    algorytmy = &sa;
    std::string szyfrowanie = "Ala ma kota z lolkiem Z lolkiem";
    szyfrowanie = algorytmy->encryption(szyfrowanie);
    std::cout << "Zaszyfrowane: " << szyfrowanie << std::endl;
    szyfrowanie = algorytmy->decryption(szyfrowanie);
    std::cout << "Odszyfrowane: " << szyfrowanie << std::endl;

    szyfrowanie = "Kot";
    szyfrowanie = algorytmy->encryption(szyfrowanie);
    std::cout << "Zaszyfrowane: " << szyfrowanie << std::endl;
    szyfrowanie = algorytmy->decryption(szyfrowanie);
    std::cout << "Odszyfrowane: " << szyfrowanie << std::endl;

    szyfrowanie = "K";
    szyfrowanie = algorytmy->encryption(szyfrowanie);
    std::cout << "Zaszyfrowane: " << szyfrowanie << std::endl;
    szyfrowanie = algorytmy->decryption(szyfrowanie);
    std::cout << "Odszyfrowane: " << szyfrowanie << std::endl;

    szyfrowanie = "";
    szyfrowanie = algorytmy->encryption(szyfrowanie);
    std::cout << "Zaszyfrowane: " << szyfrowanie << std::endl;
    szyfrowanie = algorytmy->decryption(szyfrowanie);
    std::cout << "Odszyfrowane: " << szyfrowanie << std::endl;

    szyfrowanie = "ala////";
    szyfrowanie = algorytmy->encryption(szyfrowanie);
    std::cout << "Zaszyfrowane: " << szyfrowanie << std::endl;
    szyfrowanie = algorytmy->decryption(szyfrowanie);
    std::cout << "Odszyfrowane: " << szyfrowanie << std::endl;
}



void Tests::TestUseEncryptionController() {
    EncryptionController<SecondAlgorithm> e1;


    EncryptionController<CezarAlgorithm> e2;

    std::cout << e1.Test() << " " << typeid(*(e1.Test())).name()  << std::endl;
    std::cout << e2.Test() << " " << typeid(*(e2.Test())).name() << std::endl;
    e1 = e2;
   std::cout << e1.Test() << " " << typeid(*(e1.Test())).name() << std::endl;
    std::cout << e2.Test() << " " << typeid(*(e2.Test())).name() << std::endl;






}

*/