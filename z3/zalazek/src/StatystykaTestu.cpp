#include "StatystykaTestu.hh"
#include <iostream>
#include <cmath>
#include <fstream>

void inicjuj_stat(StatystykaTestu &statystyka) //Inicjuje statystykę poprawne=0 i bledne=0
{
  statystyka.poporawne=0;
  statystyka.bledne=0;
}

void poprawne( StatystykaTestu &statystyka) //Dodaje poprawną odpowiedź
{
  ++statystyka.poporawne;
}

void bledne(StatystykaTestu &statystyka) //Dodaje błędnoą odpowiedź
{
  ++statystyka.bledne;
}

void Wyswietl( StatystykaTestu  statystyka ) //Wyświetla statystykę
{
  std::cout << "Ilosc dobrych odpowiedzi: " << statystyka.poporawne << std::endl;
  std::cout << "Ilosc blednych odpowiedzi: " << statystyka.bledne << std::endl;
  std::cout << "Wynik procentowy poprawnych odpowiedzi:   ";
  std::cout << (double)statystyka.poporawne/(statystyka.poporawne + statystyka.bledne) * 100;
  std::cout << "%" << std::endl;
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
