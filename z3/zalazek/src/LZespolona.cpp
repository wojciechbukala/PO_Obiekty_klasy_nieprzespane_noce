#include "LZespolona.hh"
#include <iostream>
#include <cmath>


/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator + (LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = re + Skl2.re;
  Wynik.im = im + Skl2.im;
  return Wynik;
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Różnice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator - (LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = re - Skl2.re;
  Wynik.im = im - Skl2.im;
  return Wynik;
}

/*!
 * Realizuje mnożenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnożenia,
 *    Skl2 - drugi skladnik mnożenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator * (LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = re*Skl2.re - im*Skl2.im;
  Wynik.im = re*Skl2.im + im*Skl2.re;
  return Wynik;
}

/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielenie,
 *    Skl2 - drugi skladnik dzielenie.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator / (LZespolona  Skl2)
{
  LZespolona  Wynik;
  if(ZwrocRe==0 && Skl2.im==0) 
  {  //Zabezpieczenie przed dzieleniem przez zero.
    std::cout<<"Blad nie mozna dzielic przez zero"<<std::endl;
  } else{
  Wynik.re = (re*Skl2.re + im*Skl2.im)/(pow(Skl2.re, 2) + pow(Skl2.im, 2));
  Wynik.im = (re*Skl2.im*(-1) + im*Skl2.re)/(pow(Skl2.re, 2) + pow(Skl2.im, 2));
  }
  return Wynik;
}

/*!
 * Realizuje porównanie dwóch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik porównania,
 *    Skl2 - drugi skladnik porównania.
 * Zwraca:
 *    true- jeśli liczby zespolone są równe.
 *    false- jeśli liczby zepolone nie są równe.
 */
bool LZespola::operator == (LZespoloana Skl2)
{
  //Liczby zespolone są równe wtedy, gdy ich części rzeczywiste oraz urojone są równe.
  return (re == Skl2.re && im == Skl2.im); // tu było Skl2.im==Skl2.im błąd!
}


/*!
 * Realizuje przeciążenie operatora przesunięcia bitowego wypisującego
 * Argumenty:
 *    &Zesp - liczba zespolona do wyświtlaenia przekazana przez referencje
 *    &rStrmWy zmienna strumienia wyjsciowego wskazujaca
 * Zwraca:
 *   wyświetla liczbę zespoloną
 */
std::ostream & operator << (std::ostream &rStrmWy, LZespolona  Zesp)
{
  rStrmWy.precision(2);
  rSrmWy << std::fixed << "(" << Zesp.zwrocRe() << std::showpos << Zesp.zwrocIm() << std::noshowpos << "i)";
  return rStrmWy;
   /* 
  std::cout.precision(2) - określia dokładność wypisywanych liczb zmiennoprzecinkowych.
  std::fixed - notacja zwykła (nie naukowa)
  std::showpos - pokazuje + przed liczbami dodatnimi
  std::noshowpos - znosi showpos
  */
}

/*!
 * Realizuje wczytywanie znaków. Używane do ()i w przeciążeniu >>
 * Argumenty:
 *    Znak- znak który chcemy wczytać
 *    &rStrmWej zmienna strumienia wejsciowego wskazujaca
 */
void WczytajTenZnak(std::istream &StrmWej, char Znak){
  char CzytanyZnak = ' ';
  StrmWej >> CzytanyZnak;
  if (CzytanyZnak != Znak)
    StrmWej.setstate(std::ios::failbit);
  /*
    Jesli wczytany znak bedzie niezgodny ze znakiem zadanym, to strumien znajdzie sie w stanie fail. Wowczas zadna operacja czytania z tego strumienia nie zostanie wykonana. 
   */
}
/*!
 * Realizuje przeciążenie operatora przesunięcia bitowego wczytującego
 Liczba zespolona powinna być wpisana w nawiasie i zawierać 'i' w części urojonej
 * Argumenty:
 *    &Zesp - liczba zespolona do wczytania przekazana przez referencje
 *    &rStrmWe zmienna strumienia wejsciowego wskazujaca na plik
 * Zwraca:
 *   -liczbe zespoloną 
 *   -błąd w przypadku nie otwarcia pliku lub złego zapisu liczby
 */ 
std::istream & operator >>(std::istream &rStrmWe, LZespolona &Zesp)
{ 
  // Wczytywanie pierwszego nawiasu '('
  WczytajTenZnak(rStrmWe, '(');

  // Wczytywanie części rzeczywistej
  rStrmWe>> Zesp.re;
  if(rStrmWe.fail()) return rStrmWe; 

  // Wczytywanie części urojonej
  rStrmWe>> Zesp.im; 
  if(rStrmWe.fail()) return rStrmWe;

  // Wczytywanie zanku 'i'
  WczytajTenZnak(rStrmWe, 'i');

  // Wczytywanie drugiego nawiasu ')'
  WczytajTenZnak(rStrmWe, ')');
  return rStrmWe;
} 
