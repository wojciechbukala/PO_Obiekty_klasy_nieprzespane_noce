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
  LZespolona () {re=0 ; im=0;};
  LZespolona(float r, float i) {re=r ; im=i;}
  // Zapowiedzi definicji przeciążeń operatrów
  LZespolona operator + (LZespolona Skl2);
  LZespolona operator - (LZespolona Skl2);
  LZespolona operator * (LZespolona Skl2);
  LZespolona operator * (double zmiennoprzecinkowa);
  LZespolona operator / (LZespolona Skl2);
  LZespolona operator / (double liczbaZP); 
  void operator = (double liczbaZP);
  bool operator == (double liczbaZP);
  bool operator != (double liczbaZP);
  LZespolona sprzezenie(); // metoda obliczająca sprzężenie liczby zespolonej
  double kwadrat_modulu(); // medota obliczająca kwadrat modulu liczby zespolonej
  bool operator == (LZespolona Skl2);
  bool wpisz (std::istream &rStrmWe, bool reim); // jeśli reim==1 to wpisz do re, jeśli reim==0 to wpisz do im
  double zwrocRe() const {return re;};
  double zwrocIm() const {return im;};
};


std::istream & operator >> (std::istream &rStrmWe, LZespolona &Zesp);
std::ostream & operator << (std::ostream &rStrmWy, LZespolona Zesp);

void WczytajTenZnak(std::istream &StrmWej, char Znak);


#endif