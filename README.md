Powyższy program ma na celu szyfrowanie tekstu i zapisywanie go do bazy danych (pliku). Wykonuje on
dwa szyfry, jednym jest szyfr cezara o przestawieniu 3 liter, drugim natomiast szyfr przestawieniowy,
który zamienia miejscami sąsiadujące ze soba litery.

Działanie:
Zostały utworzone następujące klasy:
-DatabaseModel (klasa odpowiadająca za przechowywanie danych, oraz ich obsługę ( tzn. wyświetlanie, zapisywanie, odczytywanie, dodawanie nowych danych)
-Algorithms ( klasa abstrakcyjna, napisana w celu późniejszego wykorzystania polimorfizmu)
-CezarAlgorithm( dziedziczy po klasie abstrakcyjnej Algorithms i implementuje jej metody, które odpowiadają za szyfrowanie i deszyfrowanie tekstu).
-SecondAlgorithm( drugi algorytm, również dziedziczący po klasie absktrakcyjnej Algorithms i implementujący jej metody)
-EncryptionController( kontroler, który łączy baze danych, algorytmy szyfrujące i je obsługuje, udostępniając interfejs obsługi dla klasy Application)
-Application( klasa odpowiadajaca za wyswietlanie programu, i wszelaką interakcję z użytkownikiem).

W projekcie zostały wyróźnione 3 warstwy:
1. Warstwa backendu wykonująca operacje z danymi i zwracająca wyniki
2. Warstwa kontrolera, która łączy interakcję użytkownika z warstwą backendu
3. Warstwa frontendu, odpowiadająca za wygląd i komunikację z użytkownikiem.

W funkcjach w większości przypadków przekazywane są kopie obiektów, w celu jak największego oddzielenia
od siebie każdej z warstw. Zabieg sprawić ma, że dane warstwy będą od siebie niezależne.


Szyfr cezara działa na zasadzie przesunięcia każdej literki na tą o 3 dalszą np. A->D
Szyfr przestawieniowy(Second Algorithm) działa na zasadzie, że zamienia miejscami sąsiadujące ze sobą litery.


