#include <iostream>
#include "WyrazenieZesp.hh"


/*!
 * Realizuje wczytywanie wyrazenia zespolonego
 * Argumenty:
 *    &rWyrZ - referencja wyrażenia zespolonego
 *    &rStrmWe - referencja strumienia wejsciowego
 * Zwraca:
 *    return rStrmWe.fail() == false
 */
bool WczytajWyrazenieZesp(WyrazenieZesp &rWyrZ, std::istream &rStrmWe)
{
  char temp; // zmienna pomocnicza do przechowywania wczytanego znaku
  for(int i=0; i<3; i++){ // pętla wczytująca wykanowyana 3 krotnie ( wczytuje dwie liczby zespolone i znak)
    rStrmWe >> temp;
    if(temp==' ' || temp==')' || temp=='i') --i; // Pomijamy spację, ')' oraz 'i'
    else
    {
      switch(temp)
      {
        case '(' :  // Jeśli wczytano '(' to odczytujemy liczbę zespoloną
        if(i==0) rStrmWe >> rWyrZ.Arg1.re >> rWyrZ.Arg1.im; // pierwsza liczba gdy i=0
        if(i==2) rStrmWe >> rWyrZ.Arg2.re >> rWyrZ.Arg2.im; // druga liczba gdy i=2
        break;
      
        case '+' : rWyrZ.Op = Op_Dodaj; break;

        case '-' : rWyrZ.Op = Op_Odejmij; break;

        case '*' : rWyrZ.Op = Op_Mnoz; break;

        case '/' : rWyrZ.Op= Op_Dziel; break;

        default: std::cout<< "Nie rozpoznano liczby zespolnej ani znaku dzialania"<<std::endl;
      }
    }
    
  }
  return rStrmWe.fail() == false;
}

void WyswietlWyrazenie(WyrazenieZesp  WyrZ)
{
  std::cout.precision(2);
  std::cout << std::fixed << "(" << WyrZ.Arg1.re << std::showpos << WyrZ.Arg1.im<<std::noshowpos << "i)";
  switch(WyrZ.Op)
      {
        case Op_Dodaj: std::cout << " + "; break;

        case Op_Odejmij: std::cout << " - "; break;

        case Op_Mnoz: std::cout << " * "; break;

        case Op_Dziel: std::cout << " / "; break;
      }
  std::cout << std::fixed << "(" << WyrZ.Arg2.re << std::showpos << WyrZ.Arg2.im<<std::noshowpos << "i)";
}

/*!
 * Realizuje obliczanie wyrażenia liczb zespolonych
 * Argumenty:
 *   WyrZ - wyrażenie zespolone do obliczenia
 * Zwraca:
 *    wynik - liczba zespolona będąca wynikiem operacji
 */
LZespolona Oblicz(WyrazenieZesp  WyrZ)
{
  LZespolona wynik{}; // zmienna przechowująca wynik
  switch(WyrZ.Op)
      {
        case Op_Dodaj: wynik = WyrZ.Arg1 + WyrZ.Arg2; break;

        case Op_Odejmij: wynik = WyrZ.Arg1 - WyrZ.Arg2; break;

        case Op_Mnoz: wynik = WyrZ.Arg1 * WyrZ.Arg2; break;

        case Op_Dziel: wynik =  WyrZ.Arg1 / WyrZ.Arg2; break;
      }
  return wynik;
}

