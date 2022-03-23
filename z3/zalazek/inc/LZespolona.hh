#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>
#include <fstream>

/*!
 *  Plik zawiera definicje klasy LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na obiekcie tejklasy
 *  i funkcję wyświtlającą liczbę zespoloną..
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
class  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */

 public:
  // Zapowiedzi definicji przeciążeń operatrów
  LZespolona operator + (LZespolona Skl2);
  LZespolona operator - (LZespolona Skl2);
  LZespolona operator * (LZespolona Skl2);
  LZespolona operator / (LZespolona Skl2);
  bool operator == (LZespolona Skl2);
  double zwrocRe() const {return re;};
  double zwrosIm() const (return im:};
  LZesp () {re=0 ; im=0;};
};



// Zapowiedzi definicji przeciazen operatorow
//LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
//LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
//LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);
//LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);
std::istream & operator >> (std::istream &rStrmWe, LZespolona &Zesp);
std::ostream & operator << (std::ostream &rStrmWy, LZespolona Zesp);
bool  operator == (LZespolona  Skl1,  LZespolona  Skl2);

void WczytajTenZnak(std::istream &StrmWej, char Znak);


#endif
