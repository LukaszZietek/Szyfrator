

#ifndef SZYFRATOR_DATABASEMODEL_H
#define SZYFRATOR_DATABASEMODEL_H
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class DatabaseModel {
private:
    std::vector<std::string> outputDatabase; // Baza danych z szyframi, kt�re b�d� zapisane do pliku // KONTENER STL
    std::string path; // �cie�ka do pliku // U�YCIE STRING
public:
    explicit DatabaseModel(std::string filePath = "data.txt"); // konstruktor, w kt�rym mo�na poda� �cie�k� do pliku, explicit aby nie by�o wywo�ania niejawnego
    void saveToTheFile(); // zapisywanie wektora do pliku .txt // OBSLUGA PLIKU
    void readFromFile(); // czytanie z pliku .txt do wektora // OBSLUGA PLIKU
    void addToDatabase(std::string outputText); // dodawanie szyfrogramu do bazy danych // SETER (AKCESOR)
    void deleteFromDatabase(int id); // usuwanie szyfrogramy z bazy danych po id // SETER (AKCESOR)
    std::string backStringFromDatabase(int id); // zwraca string z wektora o okre�lonym id // GETTER CZYLI AKCESOR
    friend std::ostream& operator<<(std::ostream& os, const DatabaseModel db); //przeci��enie operatora << w celu wy�wietlania // PRZECI��ANIE OPERATORA


};


#endif //SZYFRATOR_DATABASEMODEL_H
