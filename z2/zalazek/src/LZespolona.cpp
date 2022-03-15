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
  {  //Zabezpieczenie przed dzieleniem przez zero.
    std::cout<<"Blad nie mozna dzielic przez zero"<<std::endl;
  } else{
  Wynik.re = (Skl1.re*Skl2.re + Skl1.im*Skl2.im)/(pow(Skl2.re, 2) + pow(Skl2.im, 2));
  Wynik.im = (Skl1.re*Skl2.im*(-1) + Skl1.im*Skl2.re)/(pow(Skl2.re, 2) + pow(Skl2.im, 2));
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
bool  operator == (LZespolona  Skl1,  LZespolona  Skl2)
{
  //Liczby zespolone są równe wtedy, gdy ich części rzeczywiste oraz urojone są równe.
  return (Skl1.re == Skl2.re && Skl2.im == Skl2.im);
}

/*!
 * Realizuje wczytywanie liczby zespolonej
 Liczba zespolona powinna być wpisana w nawiasie i zawierać 'i' w części urojonej
 * Argumenty:
 *    &Zesp - liczba zespolona do wyświtlaenia przekazana przez referencje
 *    &rStrmWe zmienna strumienia wejsciowego wskazujaca na plik
 * Zwraca:
 *   1 gdy poprawnie odczytano
 *   0 gdy niepoprawnie odczytano
 */
bool WczytajZesp(LZespolona &Zesp, std::istream &rStrmWe)
{
  char pom1, pom2, pom3; // zmienne pomocnicze na przchowywanie '(' ')' 'i'
  double re, im;   // zmienne do wczytywania wartosci rzeczywistej i urojonej
  rStrmWe >> pom1;
  rStrmWe>> re;
  rStrmWe>> im;     // Wczytywanie
  rStrmWe>>pom2;
  rStrmWe>>pom3;
  while(pom1!='(' || pom2!='i' || pom3!=')' || rStrmWe.fail()) // Jeśli nie wpisano i() powadom użytkownika i wczytaj jeszcz raz
    {
    rStrmWe >> pom1;
    rStrmWe>> re;
    rStrmWe>> im;     // Wczytywanie
    rStrmWe>>pom2;
    rStrmWe>>pom3;
    if(pom1!='(' || pom2!='i' || pom3!=')' || rStrmWe.fail()) std::cout<<" Liczba zespolona powinna znajdowac sie w nawiasach i posiadac czesc urojona 'i' " << std::endl;
    if(pom1!='(' || pom2!='i' || pom3!=')' || rStrmWe.fail()) std::cout<<" Twoja odpowiedz: ";
    rStrmWe.clear(); // Czyszczenie strumienia wejściowego
    rStrmWe.ignore(100, '\n');
  }
  Zesp.re = re; // Jeśli poprawnie wpisano przypisz wartości do liczby zepolonej
  Zesp.im = im;
  return rStrmWe.fail() == false;
}

/*!_] Interrupt
laenia
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

/*
std::istream & operator >>(std::istream &rStrmWe, LZespolona Zesp)
{
    char pom1, pom2, pom3; // zmienne pomocnicze na przchowywanie '(' ')' 'i'
  double re, im;   // zmienne do wczytywania wartosci rzeczywistej i urojonej
  rStrmWe >> pom1;
  rStrmWe>> re;
  rStrmWe>> im;     // Wczytywanie
  rStrmWe>>pom2;
  rStrmWe>>pom3;
  while(pom1!='(' || pom2!='i' || pom3!=')' || rStrmWe.fail()) // Jeśli nie wpisano i() powadom użytkownika i wczytaj jeszcz raz
    {
    rStrmWe >> pom1;
    rStrmWe>> re;
    rStrmWe>> im;     // Wczytywanie
    rStrmWe>>pom2;
    rStrmWe>>pom3;
    if(pom1!='(' || pom2!='i' || pom3!=')' || rStrmWe.fail()) std::cout<<" Liczba zespolona powinna znajdowac sie w nawiasach i posiadac czesc urojona 'i' " << std::endl;
    if(pom1!='(' || pom2!='i' || pom3!=')' || rStrmWe.fail()) std::cout<<" Twoja odpowiedz: ";
    rStrmWe.clear(); // Czyszczenie strumienia wejściowego
    rStrmWe.ignore(1000, '\n');
  }
  Zesp.re = re; // Jeśli poprawnie wpisano przypisz wartości do liczby zepolonej
  Zesp.im = im;
  return rStrmWe;
} */