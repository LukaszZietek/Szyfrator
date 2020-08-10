

#ifndef SZYFRATOR_ENCRYPTIONCONTROLLER_H
#define SZYFRATOR_ENCRYPTIONCONTROLLER_H

#include "Algorithms.h"
#include "CezarAlgorithm.h"
#include "SecondAlgorithm.h"
#include "DatabaseModel.h"

// Klasa zosta³a zaimplementowana aby by³a kontrolerem ³¹cz¹cym aplikacjê z baz¹ danych oraz algorytmami.

template <class T> // ZASTOSOWANIE SZABLONU W CELU WYKORZYSTANIA POLIMORFIZMU // SZABLON
class EncryptionController { //Wszystkie algorytmy zaimplementowane s¹ w pliku nag³ówkowym, poniewa¿ inaczej wystêpowa³y b³êdy z linkowaniem tej klasy
private:
    Algorithms* usedAlgorithm; // Deklaracja zmiennej s³u¿¹cej do wykorzystania polimorfizmu
    DatabaseModel db; // KOMPOZYCJA
public:
    EncryptionController()
    {
        usedAlgorithm = new T(); // SZABLON
        if (typeid(T).name() == typeid(SecondAlgorithm).name()) // zbadanie, ktory algorytm ma zostac wykorzystany i stworzenie odpowiedniej bazy danych
        {
            db = DatabaseModel("second.txt");
        }
        else
        {
            db = DatabaseModel("cezar.txt");
        }
    }





    ~EncryptionController() // destruktor // ZARZADZANIE PAMIECIA ZASADA TRZECH
    {
        delete usedAlgorithm;
    }


    EncryptionController(const EncryptionController& encr) // konstruktor kopiujacy // ZARZADZANIE PAMIECIA ZASADA TRZECH
    {
        delete usedAlgorithm;
        usedAlgorithm = new T();
    }

    template <class T2> // DRUGI SZABLON
    EncryptionController<T>& operator=(const EncryptionController<T2>& encr) // PRZECIAZANIE OPERATORA PRZYPISANIA,
                                                                                // Wykorzystany szablon aby mozna bylo przypisywac jeden algorytm do drugiego.
    {
        delete usedAlgorithm;                                                   // ZARZADZANIE PAMIECIA ZASADA TRZECH
        usedAlgorithm = new T2();
        return *this;
    }

    void readFromDatabase() // Funkcja sluzaca do czytania z bazy danych ( obslugi bledow itd)
    {
        try {  // OBSLUGA WYJATKOW
            db.readFromFile();
        }
        catch (const char* msg)
        {
            std::cerr << msg << std::endl;
        }
        catch (...)
        {
            std::cerr << "Error" << std::endl;
        }
    }

    void saveToDatabase()  // Funkcja sluzaca do zapisywania do bazy danych ( obslugi bledow itd)
    {
        try {  // OBSLUGA WYJATKOW
            db.saveToTheFile();
        }
        catch (const char* msg)
        {
            std::cerr << msg << std::endl;
        }
        catch (...)
        {
            std::cerr << "Error" << std::endl;
        }

    }

    void deleteFromDatabase(int id)  // Funkcja sluzaca do obslugi usuwania z bazy danych( obslugi bledow itd)
    {
        try {  // OBSLUGA WYJATKOW
            db.deleteFromDatabase(id);
        }
        catch (const char* msg)
        {
            std::cerr << msg << std::endl;
        }
        catch (...)
        {
            std::cerr << "Error during deleting object" << std::endl;
        }
    }

    void showDatabase()  // Funkcja sluzaca do pokazywania bazy danych
    {
        std::cout << db;

    }

    std::string encryptionText(std::string text) // Funkcja sluzy do przekazania tekstu do szyfrowania i zapisanie do bazy danych szyfrogramu.
    {
        std::string output = usedAlgorithm->encryption(text);
        if (output.length() != 0)
        {
            db.addToDatabase(output);
            return output;
        }
        return "";
    }

    std::string decryptionText(std::string text = " ", int id = -1) // Funkcja sluzaca do przekazania tekstu do deszyfrowania.
    {
        std::string output;
        if (id < 0) {
            output = usedAlgorithm->decryption(text);
            return output;
        }

        if (id > 0)
        {
            try { // OBSLUGA WYJATKOW
                output = db.backStringFromDatabase(id);
                output = usedAlgorithm->decryption(output);
            }
            catch (const char* msg)
            {
                std::cerr << msg << std::endl;
            }
            catch (...)
            {
                std::cerr << "Error" << std::endl;
            }
            return output;
        }
        return "";
    }


    /* Algorithms * Test() // funkcja testowa
     {
         return usedAlgorithm;
     }
     */

};







#endif //SZYFRATOR_ENCRYPTIONCONTROLLER_H
