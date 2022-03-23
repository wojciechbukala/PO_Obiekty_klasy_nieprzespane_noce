#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH


#include <iostream>
#include <fstream>
#include "LZespolona.hh"


/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
};


bool WczytajWyrazenieZesp(WyrazenieZesp &rWyrZ, std::istream &rStrmWe);
void WyswietlWyrazenie(WyrazenieZesp  WyrZ);
LZespolona Oblicz(WyrazenieZesp  WyrZ);
std::istream & operator >> (std::istream &rStrmWe, WyrazenieZesp &WyrZ); // Przeciążenie operatora >> do wczytywania wyrażenia zespolonego
std::ostream & operator << (std::ostream &rStrmWy, WyrazenieZesp WyrZ); // Przeciążenie operatora << do wypisywania wyrażenia zespolonego

#endif
