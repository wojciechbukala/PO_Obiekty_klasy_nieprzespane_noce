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
    LZespolona Zesp, Wynik; // Zesp- liczba zespolona wczytana od użytkownika, Wynik- rezultat funkcji Oblicz()
    StatystykaTestu statystyka; // obiekt statystyki
    statystyka.inicjuj_stat(); // zerujemy statystyke

    do
    {
        //wczytaj(rStrmWej,WyrZ);
        rStrmWej >> WyrZ;  // Wczytywanie wyrażenia zespolonego z pliku
        while(rStrmWej.fail()) //Sprawdzanie poprawności wczytywania z pliku
        {
          std::cerr << "Napotkano bledne wyrazenie. Zostalo ono pominiete." << std::endl;
          rStrmWej.clear();
          rStrmWej.ignore(1000, '\n');
          rStrmWej >> WyrZ;   // Wczytywanie wyrażenia zespolonego z pliku
        }

        std::cout<< std::endl<<":? Podaj wynik operacji: ";
        std::cout << WyrZ;
        Wynik= WyrZ.Oblicz();

        bool pom=false;
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
        std::cout << std::endl;
        rStrmWej.clear();  // czyścimy strumień wejściowy
        rStrmWej.ignore(1000, '\n'); 
    } while (!rStrmWej.eof() && rStrmWej.good()); // zadajemy pytania do czasu aż plik się nie zakończy i jest poprawny

    std::cout << "Koniec testu" << std::endl;
    std::cout << std::endl;

    statystyka.Wyswietl(); // wyświetlamy statystykę testu

    std::cout << std::endl;  
} 

void wczytaj(std::istream &rStrmWej, WyrazenieZesp WyrZ) 
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