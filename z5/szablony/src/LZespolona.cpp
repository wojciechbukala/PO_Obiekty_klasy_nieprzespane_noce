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

  Wynik.re = this->re + Skl2.re;
  Wynik.im = this->im + Skl2.im;
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
  if(zwrocRe()==0 && Skl2.im==0) 
  {  //Zabezpieczenie przed dzieleniem przez zero.
    std::cerr<<"Blad nie mozna dzielic przez zero"<<std::endl;
  } else{
  Wynik.re = (re*Skl2.re + im*Skl2.im)/Skl2.kwadrat_modulu();
  Wynik.im = (re*Skl2.sprzezenie().im + im*Skl2.re)/Skl2.kwadrat_modulu();
  }
  return Wynik;
}

LZespolona LZespolona::operator / (double liczbaZP)
{
  LZespolona Wynik;
  if(liczbaZP==0) std::cerr<<"Blad nie mozna dzielic przez zero"<<std::endl;
  else {
    Wynik.re = re / liczbaZP;
    Wynik.im = im / liczbaZP;
  }
  return Wynik;
}

/* Metoda realizuje i zwraca sprzężenie liczby zespolonej */
LZespolona LZespolona::sprzezenie()
{
  LZespolona Wynik;
  Wynik.im= (-1)*im;
  return Wynik;
}

/* Metoda realizuje i zwraca kwadrat modułu liczby zespolonej */
double LZespolona::kwadrat_modulu()
{
  return pow(re,2)+pow(im,2);
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
bool LZespolona::operator == (LZespolona Skl2)
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
  rStrmWy << std::fixed << "(" << Zesp.zwrocRe() << std::showpos << Zesp.zwrocIm() << std::noshowpos << "i)";
  return rStrmWy;
   /* 
  std::cout.precision(2) - określia dokładność wypisywanych liczb zmiennoprzecinkowych.
  std::fixed - notacja zwykła (nie naukowa)
  std::showpos - pokazuje + przed liczbami dodatnimi
  std::noshowpos - znosi showpos
  */
}


/* Funkcja przypisuje wartość do zmiennych prywatnych re i im
 * Argumenty:
 *   rStrmWe - strumień wejściowy
 *   liczba - część rzeczywista lub urojona do przypisania 
 *   reim - jeśli 1 to wpisujemy do re, jeśli 0 to do im
 * Zwraca:
 *   wpisuje do re lub im wartość
 */
 bool LZespolona::wpisz (std::istream &rStrmWe, bool reim)
 {
   if (reim==1)rStrmWe>> re; 
   if (reim==0)rStrmWe>> im;
   return rStrmWe.fail() == false;
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
  Zesp.wpisz(rStrmWe, 1);

  // Wczytywanie części urojonej
  Zesp.wpisz(rStrmWe, 0);

  // Wczytywanie zanku 'i'
  WczytajTenZnak(rStrmWe, 'i');

  // Wczytywanie drugiego nawiasu ')'
  WczytajTenZnak(rStrmWe, ')');
  return rStrmWe;
} 
