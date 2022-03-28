#ifndef WYKONAJTEST_HH
#define WYKONAJTEST_HH
#include "WyrazenieZesp.hh"
#include "StatystykaTestu.hh"
#include <iostream>
#include <fstream>

/*!
 *  Plik zawiera funkcje wynonaj test i
 *  funkcje pomocnicze służące do wykonywania
 *  testy arytmetyki liczb zespolonych
 */
void WykonajTest(std::istream &rStrmWej);
void wczytaj_wyrazenie(std::istream &rStrmWej, WyrazenieZesp &WyrZ) ;
bool wczytaj_zesp(LZespolona &Zesp);
void sprawdz_wynik(WyrazenieZesp WyrZ, LZespolona Zesp, bool pom, StatystykaTestu &statystyka);

#endif
