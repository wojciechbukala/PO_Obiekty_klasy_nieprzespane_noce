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
class WyrazenieZesp {
    LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
    Operator     Op;     // Opertor wyrazenia arytmetycznego
    LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego

  public:
    LZespolona Oblicz();
    LZespolona zwrocArg1() const {return Arg1;};
    LZespolona zwrocArg2() const {return Arg2;};
    Operator zwrocOp() const {return Op;};
    bool PrzypiszZnak (char znak);
    bool wczytaj (std::istream &rStrmWe, char Arg);
};

std::istream & operator >> (std::istream &rStrmWe, WyrazenieZesp &WyrZ); // Przeciążenie operatora >> do wczytywania wyrażenia zespolonego
std::ostream & operator << (std::ostream &rStrmWy, WyrazenieZesp WyrZ); // Przeciążenie operatora << do wypisywania wyrażenia zespolonego

#endif
