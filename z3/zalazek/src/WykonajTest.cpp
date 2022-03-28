#include "WykonajTest.hh"
#include "StatystykaTestu.hh"
#include "WyrazenieZesp.hh"
#include <iostream>


/*!
 * Realizuje działanie testu liczb zespolonych
 * Argumenty:
 *    &rStrmWe - referencja strumienia wejsciowego
 */
void WykonajTest(std::istream &rStrmWej)
{
    WyrazenieZesp WyrZ; // zmienna przechowująca wyrażenie zespolone
    LZespolona Zesp; // Zesp- liczba zespolona wczytana od użytkownika, Wynik- rezultat funkcji Oblicz()
    StatystykaTestu statystyka; // obiekt statystyki
    statystyka.inicjuj_stat(); // zerujemy statystyke

    do
    {
        wczytaj_wyrazenie(rStrmWej,WyrZ); // wczytujemy wyrażenie w z pliku

        std::cout<< std::endl<<":? Podaj wynik operacji: ";
        std::cout << WyrZ;

        bool pom=wczytaj_zesp(Zesp); // wczytujemy odpowiedź urzytkownika

        sprawdz_wynik(WyrZ, Zesp, pom, statystyka); // wykonujemy weryfikacje wyniku
          
        std::cout << std::endl;
        rStrmWej.clear();  // czyścimy strumień wejściowy
        rStrmWej.ignore(1000, '\n'); 
    } while (!rStrmWej.eof() && rStrmWej.good()); // zadajemy pytania do czasu aż plik się nie zakończy i jest poprawny

    std::cout << "Koniec testu" << std::endl;
    std::cout << std::endl;

    statystyka.Wyswietl(); // wyświetlamy statystykę testu

    std::cout << std::endl;  
} 

/*!
 * Realizuje wczytywanie wyrażenia zespolonego z pliku
 * Argumenty:
 *    &rStrmWe - referencja strumienia wejsciowego
 *    &WyrZ - referencja klasy przechowującej wyrażenie zespolone
 */
void wczytaj_wyrazenie(std::istream &rStrmWej, WyrazenieZesp &WyrZ) 
{
    rStrmWej >> WyrZ;  // Wczytywanie wyrażenia zespolonego z pliku
        while(rStrmWej.fail()) //Sprawdzanie poprawności wczytywania z pliku
        {
          std::cerr << "Napotkano bledne wyrazenie. Zostalo ono pominiete." << std::endl;
          rStrmWej.clear();
          rStrmWej.ignore(1000, '\n');
          rStrmWej >> WyrZ;   // Wczytywanie wyrażenia zespolonego z pliku
        }
}

/*!
 * Realizuje wczytywanie wyrażenia zespolonego z pliku
 * Argumenty:
 *   &Zesp - referencja liczby zespolonej do ktorej użytkownik wpisuje odpowiedź
 * Zwraca:
 *   pom - zmienna logiczna informuje czy pętla wczytywania została wykonana 3 razy
 */
bool wczytaj_zesp(LZespolona &Zesp)
{
    bool pom=false; // zmienna mówiąca czy pętla wykonała się 3 razy czy nie.
        for(int i=0; i<3; ++i) // Trzy próby wpisania poprawnej odpowiedzi
        {
        std::cout<< std::endl << " Twoja odpowiedz: ";
        std::cin >> Zesp;   // Wczytywanie odpowiedzi użytkownika
          if(std::cin.fail()) // przypadek błędnego wpisania liczby zespolonej
          {
           if(i!=2) std::cerr << "Blad wczytywania liczby zespolonej. Wpisz poprawna liczbe!" << std::endl;
           std::cin.clear();
           std::cin.ignore(1000, '\n');
           if(i==2) pom=true; // jeśli pętala obróci 3 razy ustaw pom na true aby zaliczyć błąd
          }   else break;
        }
    return pom; 
}

/*!
 * Realizuje weryfikacje poprawnosci i obsluguje statystyke testu
 * Argumenty:
 *    Zesp - liczba zespolona od urzytkowanika
 *    WyrZ - wyrażenie zespolone w pliku
 *    pom - zmienna logiczna przechowujaca informacje o wczesniejszym dzialaniu programu
 *    &statystyka - referencja klasy statystyka przechowującej informacje o poprawnych i blednych odpowiedziach
 */
void sprawdz_wynik(WyrazenieZesp WyrZ, LZespolona Zesp, bool pom, StatystykaTestu &statystyka)
{
    LZespolona Wynik;
    Wynik= WyrZ.Oblicz();
    if(Zesp==Wynik && pom!=true) // w przypadku, gdy odpowiedź jest poprawna
          {
            std::cout<<":) Odpowiedz poprawna" << std::endl;
            statystyka.poprawna_odp();
          }
          else   // w przypadku gdy, odpowiedź jest niepoprawna lub 3 razy źle wpisano
          { 
            std::cout<< ":( Blad. Prawidlowym wynikiem jest: ";
            std::cout<< Wynik << std::endl;
            statystyka.bledna_odp();
          }
}