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
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
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
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
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
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re*Skl2.re - Skl1.im*Skl2.im;
  Wynik.im = Skl1.re*Skl2.im + Skl1.im*Skl2.re;
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
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;
  if(Skl2.re==0 && Skl2.im==0) 
  {
    std::cout<<"Blad nie mozna dzielic przez zero"<<std::endl;
  } else{
  Wynik.re = (Skl1.re*Skl2.re + Skl1.im*Skl2.im)/(pow(Skl2.re, 2) + pow(Skl2.im, 2));
  Wynik.im = (Skl1.re*Skl2.im*(-1) + Skl1.im*Skl2.re)/(pow(Skl2.re, 2) + pow(Skl2.im, 2));
  }
  return Wynik;
}

/*!
 * Realizuje wczytywanie liczby zespolonej
 * Argumenty:
 *    &Zesp - liczba zespolona do wyświtlaenia przekazana przez referencje
 *    &rStrmWe zmienna strumienia wejsciowego wskazujaca na plik
 * Zwraca:
 *   1 gdy poprawnie odczytano
 *   0 gdy niepoprawnie odczytano
 */
bool WczytajZesp(LZespolona &Zesp, std::istream &rStrmWe)
{
  char temp;
  rStrmWe >> temp;
  if(temp=='(') {rStrmWe >> Zesp.re >> Zesp.im;}
  else {std::cout<<"Liczba zespolona powinna znajdowac sie w napiasach okraglych ()."<<std::endl;}
  return rStrmWe.fail() == false;
}

/*!
 * Realizuje wyświtlanie liczby zespolonej
 * Argumenty:
 *    LZesp - liczba zespolona do wyświtlaenia
 * Zwraca:
 *   Wypisuje na standardowym wyjściu liczbe zespoloną.
 */
void WyswietlZesp(LZespolona LZesp)
{
  std::cout.precision(2);
  std::cout << std::fixed << "(" << LZesp.re << std::showpos << LZesp.im<<std::noshowpos << "i)";
  /* 
  std::cout.precision(2) - określia dokładność wypisywanych liczb zmiennoprzecinkowych.
  std::fixed - notacja zwykła (nie naukowa)
  std::showpos - pokazuje + przed liczbami dodatnimi
  std::noshowpos - znosi showpos
  */
}