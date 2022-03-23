#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>
#include <fstream>

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze i funkcję wyświtlającą liczbę zespoloną..
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};



// Zapowiedzi definicji przeciazen operatorow
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);
std::istream & operator >> (std::istream &rStrmWe, LZespolona &Zesp);
std::ostream & operator << (std::ostream &rStrmWy, LZespolona &Zesp);
bool  operator == (LZespolona  Skl1,  LZespolona  Skl2);

void WczytajTenZnak(std::istream &StrmWej, char Znak);

// zapowiedż funkcji wczytującej liczbę zepoloną
bool WczytajZesp(LZespolona &Zesp, std::istream &rStrmWe);

// Zapowiedź funkcji wyświtalającej liczbę zespoloną 
void WyswietlZesp(LZespolona LZesp);


#endif
