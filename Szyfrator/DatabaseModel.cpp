

#include "DatabaseModel.h"
DatabaseModel::DatabaseModel(std::string filePath)
{
    path = filePath;
}


void DatabaseModel::saveToTheFile()
{
    std::ofstream file(path, std::ofstream::out); // otwiera bufor plikowy
    if (file.good()) // sprawdza czy siê uta³o otworzyc
    {
        for (int i = 0; i < outputDatabase.size(); i++) { // kolejno zapisuje do pliku
            file << outputDatabase[i] << std::endl;
        }
        file.close(); // zamyka bufor
    }
    else // inaczej rzuca wyjatkiem
    {
        throw "Nie udalo sie zapisac do pliku"; // rzuca wyj¹tkiem o widocznej wiadomosci // ROZPOCZECIE IMPLEMENTACJI OBSLUGI BLEDOW
    }

}


void DatabaseModel::readFromFile()
{
    std::ifstream file;
    file.open(path, std::ios::in); // otwarcie bufora

    if (file.good()) // sprawdzenie czy sie udalo utworzyc bufor
    {
        outputDatabase.clear(); // czysci wektor
        while (!file.eof()) // czyta do konca pliku
        {
            std::string helpfulText;
            getline(file, helpfulText);
            addToDatabase(helpfulText);
        }
        file.close();
    }
    else // jesli sie nie udalo otworzyc rzucenie wyjatku
    {
        throw "Nie udalo sie odczytac bazy danych z pliku"; // rzuca wyjatkiem o widocznej wiadomosci // ROZPOCZECIE IMPLEMENTACJI OBSLUGI BLEDOW
    }



}
void DatabaseModel::addToDatabase(std::string outputText)
{
    if (!outputText.empty())
        outputDatabase.push_back(outputText);

}
void DatabaseModel::deleteFromDatabase(int id)
{
    id = id - 1;
    if (id < outputDatabase.size() && id >= 0)
    {
        outputDatabase.erase(outputDatabase.begin() + id); // tworzy iterator pokazuj¹cy na pierwsze miejsce w wektorze i
    }
    else                                                          // dodaje do niego podan¹ wartoœæ id
    {
        throw "Nie ma w bazie danych elementu o podanym id"; // ROZPOCZECIE IMPLEMENTACJI OBSLUGI BLEDOW
    }
}



std::ostream& operator<<(std::ostream& os, const DatabaseModel db)
{
    if (db.outputDatabase.size() > 0)
    {
        for (int i = 0; i < db.outputDatabase.size(); i++)
        {
            os << i + 1 << ": " << db.outputDatabase[i] << std::endl;
        }
    }
    else
    {
        os << "Baza danych nie zostala jeszcze utworzona" << std::endl;
    }
    return os;

}

std::string DatabaseModel::backStringFromDatabase(int id)
{
    if (outputDatabase.size() > (id - 1))
    {
        return outputDatabase[id - 1];
    }
    else
    {
        throw "Nie istnieje element o takim ID"; // rzuca wyjatkiem o widocznej wiadomosci // ROZPOCZECIE IMPLEMENTACJI OBSLUGI BLEDOW
    }

}