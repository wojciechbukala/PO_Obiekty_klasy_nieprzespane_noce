#include "StatystykaTestu.hh"
#include "WyrazenieZesp.hh"
#include "LZespolona.hh"
#include <iostream>
#include <cmath>
#include <fstream>

/*
void Wyswietl( StatystykaTestu  StatTestu )
{
} */

/*!
 * Realizuje działanie testu liczb zespolonych
 * Argumenty:
 *    &rStrmWe - referencja strumienia wejsciowego
 */
void WykonajTest(std::istream &rStrmWej)
{
    WyrazenieZesp WyrZ; // zmienna przechowująca wyrażenie zespolone
    LZespolona Zesp, Wynik; // Zesp- liczba zespolona wczytana od użytkownika, Wynik- rezultat funkcji Oblicz()
    do
    {
        WczytajWyrazenieZesp(WyrZ, rStrmWej); // Wczytywanie wyrażenia z pliku
        std::cout<< std::endl<<": ? Podaj wynik operacji: ";
        WyswietlWyrazenie(WyrZ);
        std::cout<< std::endl << " Twoja odpowiedz: ";
        WczytajZesp(Zesp, std::cin);   // Wczytywanie odpowiedzi użytkownika
        Wynik= Oblicz(WyrZ);
        if(Zesp==Wynik) std::cout<<":) Odpowiedz poprawna" << std::endl;
        else 
        {
            std::cout<< ":( Blad. Prawidlowym wynikiem jest: ";
            WyswietlZesp(Wynik);
        }
        std::cout << std::endl;
    } while (rStrmWej.good());
       
} 


/*!
 * Realizuje wyswietlanie i obliczanie wyrażeń zespolonych (docelowo funkcji wykonująca test)
 * Argumenty:
 *    &rStrmWe - referencja strumienia wejsciowego
 */
/*
void WykonajTest(std::istream &rStrmWej)
{
  WyrazenieZesp   WyrZ;
  
    while (WczytajWyrazenieZesp(WyrZ, rStrmWej)) {
    WyswietlWyrazenie(WyrZ);
    std::cout<< std::endl;
    WyswietlZesp(Oblicz(WyrZ));

    std::cout<< std::endl << std::endl;}
} */
