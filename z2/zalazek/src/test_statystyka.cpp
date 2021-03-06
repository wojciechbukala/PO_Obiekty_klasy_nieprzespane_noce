#include "test_statystyka.hh"
#include "WyrazenieZesp.hh"
#include "LZespolona.hh"
#include <iostream>


/*!
 * Realizuje wyswietlanie i obliczanie wyrażeń zespolonych (docelowo funkcji wykonująca test)
 * Argumenty:
 *    &rStrmWe - referencja strumienia wejsciowego
 */
void WykonajTest(std::istream &rStrmWej)
{
  WyrazenieZesp   WyrZ;
  
    while (WczytajWyrazenieZesp(WyrZ, rStrmWej)) {
    WyswietlWyrazenie(WyrZ);
    std::cout<< std::endl;
    WyswietlZesp(Oblicz(WyrZ));

    std::cout<< std::endl << std::endl;}
}

