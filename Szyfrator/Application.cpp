

#include "Application.h"
template <class T>
void Application::algorithmMenu(EncryptionController<T>& enc)
{
    std::string textToEncryption;
    std::string outputText = "";
    bool ifWantBack = false; // zmienna ktora sluzy do powrotu do wczesniejszego menu gdy zostanie wybrana odpowiednia opcja/ badz pojawi sie blad
    while (1)
    {
        //system("cls");
        char menuChoose2;
        std::cout << "-------------------------------------------------------------------------------------" << std::endl;
        std::cout << "1. Szyfruj tekst" << std::endl;
        std::cout << "2. Deszyfruj tekst" << std::endl;
        std::cout << "3. Pokaz baze danych" << std::endl;
        std::cout << "4. Wczytaj baze danych z pliku(aktualna baza danych zostanie utracona)" << std::endl;
        std::cout << "5. Usun z bazy danych szyfrogram o podanym ID" << std::endl;
        std::cout << "6. Wroc do wyboru szyfru" << std::endl;
        std::cout << "9. Koniec" << std::endl;
        std::cout << "-------------------------------------------------------------------------------------" << std::endl;
        std::cout << "Twoj wybor: ";
        std::cin >> menuChoose2;
        std::cin.ignore(256, '\n');
        std::cin.clear();
        if (std::cin.fail()) // jesli wystapi blad czysci bufor
        {
            std::cin.ignore(256,'\n');
            std::cin.clear();
            fflush(stdin);
            break;
        }
        fflush(stdin);
        std::cout << "\n";
        switch (menuChoose2)
        {
        case '1': { // Szyfrowanie tekstu i dodawanie do bazy danych
            std::string textToDecryption;
            // system("cls");
            std::cout << "Podaj tekst, ktory nalezy zaszyfrowac :";
            std::cin.clear();
            std::getline(std::cin, textToDecryption);
            std::cout << "\n";
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore();
                ifWantBack = true;
                break;
            }
            fflush(stdin);
            outputText = enc.encryptionText(textToDecryption);
            std::cout << "Zaszyfrowany tekst: " << outputText << std::endl;
            std::cout << "\n Tekst zostal dodany rowniez do bazy danych gdybys chcial do niego powrocic"
                << std::endl;
            Sleep(5000);
        }
                break;

        case '2': { // Deszyfrowanie tekstu z klawiatury lub z bazy danych
            char menuChoose3;
            //system("cls");
            std::cout << "Zdeszyfruj tekst z: " << std::endl;
            std::cout << "-------------------------------------------------------------------------------------"
                << std::endl;
            std::cout << "1.Klawiatury" << std::endl;
            std::cout << "2.Bazy danych" << std::endl;
            std::cout << "-------------------------------------------------------------------------------------"
                << std::endl;
            std::cout << "Twoj wybor: ";
            /*std::cin.ignore(256, '\n');*/
            std::cin.clear();
            std::cin >> menuChoose3;
            std::cin.ignore(256, '\n');
            std::cout << "\n";
            if (!std::cin.good())
            {
                std::cin.ignore();
                std::cin.clear();
                break;
            }
            fflush(stdin);
            switch (menuChoose3) {
            case '1': { // Deszyfrowanie z klawiatury
                std::cout << "Podaj zaszyfrowany tekst: ";
                /*std::cin.ignore(256, '\n');*/
                std::cin.clear();
                std::getline(std::cin, textToEncryption);
                std::cout << "\n";
                if (!std::cin.good())
                {
                    std::cin.ignore();
                    std::cin.clear();
                    ifWantBack = true;
                    break;
                }
                fflush(stdin);
                outputText = enc.decryptionText(textToEncryption);
                std::cout << "Odszyfrowany tekst: " << outputText << std::endl;
                Sleep(5000);
            }
                    break;
            case '2': { // Deszyfrowanie z bazy danych
                int id;
                std::cout << "Podaj ID z bazy danych zaszyfrowanego tekstu: ";
                /*std::cin.ignore(256, '\n');*/
                std::cin.clear();
                std::cin >> id;
                std::cout << "\n";
                if (!std::cin.good())
                {
                    std::cin.ignore();
                    std::cin.clear();
                    ifWantBack = true;
                    break;
                }
                fflush(stdin);
                outputText = enc.decryptionText("", id);
                std::cout << "Odszyfrowany tekst: " << outputText << std::endl;
                Sleep(5000);
            }
                    break;
            default:
                break;
            }
        }
                break;
        case '3': { // Pokazywanie bazy danych
            // system("cls");
            enc.showDatabase();
        }
                break;
        case '4': { // Wczytywanie bazy danych z pliku
            enc.readFromDatabase();
            Sleep(2000);
        }
                break;
        case '5': { // Usuwanie szyfrogramu z bazy danych
            int id;
            std::cout << "\nKtory szyfrogram usunac? (Podaj ID): ";
            std::cin >> id;
            if (!std::cin.good()) {
                std::cin.ignore();
                std::cin.clear();
                break;
            }
            fflush(stdin);
            enc.deleteFromDatabase(id);
        }
                break;
        case '6': { // Powrot do menu wyboru algorytmu
            ifWantBack = true;
        }
                break;
        case '9': { // wylaczenie programu
            std::cout << "---Dziekujemy za skorzystanie z programu---" << std::endl;
            enc.saveToDatabase();
            exit(0);
        }
        default: {
            std::cout << "Kliknieto zly przycisk sproboj ponownie" << std::endl;
            Sleep(500);
        }
               break;

        }
        menuChoose2 = ' ';
        if (ifWantBack)
        {
            enc.saveToDatabase();
            return;
        }
    }

    return;

}

void Application::runApp()
{
    int menuChoose;
    while (1)
    {
        //system("cls");
        std::cout << "Witamy w programie szyfrujacym tekst, wybierz z jakiego szyfru chcesz skorzystac" << std::endl;
        std::cout << "-------------------------------------------------------------------------------------" << std::endl;
        std::cout << "1. Szyfr cezara" << std::endl;
        std::cout << "2. Szyfr przestawieniowy" << std::endl;
        std::cout << "9. Koniec" << std::endl;
        std::cout << "-------------------------------------------------------------------------------------" << std::endl;
        std::cout << "Twoj wybor: ";
        std::cin >> menuChoose;
        if (!std::cin.good())
        {
            std::cin.ignore();
            std::cin.clear();
        }
        fflush(stdin);
        std::cout << "\n";
        switch (menuChoose)
        {
        case 1: { // Wybranie szyfru cezara
            EncryptionController<CezarAlgorithm> enc;
            algorithmMenu(enc);
        }
              break;
        case 2: // Wybranie szyfru przestawieniowego
        {
            EncryptionController<SecondAlgorithm> enc;
            algorithmMenu(enc);
        }
        break;
        case 9: { // wylaczenie programu
            std::cout << "---Dziekujemy za skorzystanie z programu---" << std::endl;
            exit(0);
        }
        default:
        {
            std::cout << "Nie istnieje taki wybor, sprobuj ponownie" << std::endl;
        }
        break;

        }
        menuChoose = 0;
    }
}