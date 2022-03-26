#include <iostream>
#include "WyrazenieZesp.hh"

/*!
 * Realizuje obliczanie wyrażenia liczb zespolonych
 * Zwraca:
 *    wynik - liczba zespolona będąca wynikiem operacji
 */
LZespolona WyrazenieZesp::Oblicz()
{
  LZespolona wynik; // zmienna przechowująca wynik
  switch(Op)
      {
        case Op_Dodaj: wynik = Arg1 + Arg2; break;

        case Op_Odejmij: wynik = Arg1 - Arg2; break;

        case Op_Mnoz: wynik = Arg1 * Arg2; break;

        case Op_Dziel: wynik =  Arg1 / Arg2; break;
      }
  return wynik;
}


bool WyrazenieZesp::wczytaj (std::istream &rStrmWe, char Arg)
 {
   if (Arg=='1')rStrmWe>> Arg1; 
   else if (Arg=='2')rStrmWe>> Arg2;
   else rStrmWe.setstate(std::ios::failbit);
   return rStrmWe.fail() == false;
 }

bool WyrazenieZesp::PrzypiszZnak (char znak)
{
  switch(znak)
      {
        case '+' : Op = Op_Dodaj; break;

        case '-' : Op = Op_Odejmij; break;

        case '*' : Op = Op_Mnoz; break;

        case '/' : Op = Op_Dziel; break;

        default: return false;
      }
  return 1;
}

/*!
 * Realizuje przeciążenie operatora przesunięcia bitowego wczytującego wyrażenie zespolone
 * Liczba zespolona powinna być wpisana w nawiasie i zawierać 'i' w części urojonej, dozwolone znaki to + - * /
 * Argumenty:
 *    &WyrZ - wyrażenie zespolone do wczytania przekazane przez referencje
 *    &rStrmWe zmienna strumienia wejsciowego wskazujaca na plik
 * Zwraca:
 *   -referencje strumienia wejściowego z wczytanym wyrażeniem lub błędem
 */ 
std::istream & operator >> (std::istream &rStrmWe, WyrazenieZesp &WyrZ)
{
  char Znak;

  // Wczytujemy pierwszą liczbę zespoloną 
  WyrZ.wczytaj(rStrmWe, '1');

  // Wczytujemy znak, jeden z dozwolonych + - * /
  rStrmWe >>Znak;
  if(rStrmWe.fail()) return rStrmWe;

  if(!WyrZ.PrzypiszZnak(Znak))
  {
    rStrmWe.setstate(std::ios::failbit);
    return rStrmWe; }


  //Wczytujemy drugą liczbę zespoloną
  WyrZ.wczytaj(rStrmWe, '2');

  //Zwracamy strumień wejściowy
  return rStrmWe;
}

/*!
 * Realizuje przeciążenie operatora przesunięcia bitowego wypisującego wyrażenie zespolone
 * Argumenty:
 *    &Zesp - wyrażenie zespolone do wyświetlenia przekazane przez referencje
 *    &rStrmWy zmienna strumienia wyjsciowego wskazujaca
 * Zwraca:
 *   referencje strumienia wyjściowego z wyrażeniem zespolonym
 */
std::ostream & operator << (std::ostream &rStrmWy, WyrazenieZesp WyrZ)
{
  // Wyświetlamy pierwszą liczbę zespoloną
  rStrmWy << WyrZ.zwrocArg1();
  
  // Wyświetlamy znak
  switch(WyrZ.zwrocOp())
      {
        case Op_Dodaj: rStrmWy << " + "; break;

        case Op_Odejmij: rStrmWy << " - "; break;

        case Op_Mnoz: rStrmWy << " * "; break;

        case Op_Dziel: rStrmWy << " / "; break;
      }

  //Wyświetlamy drugą liczbę zespoloną
  rStrmWy << WyrZ.zwrocArg2();

  return rStrmWy; // Zwracamy strumień wyjściowy
} 
