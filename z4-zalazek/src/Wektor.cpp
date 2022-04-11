#include "Wektor.hh"
#include "cmath"


/* 
 * Przeciążenie operatora dodawania dla wektorów
 * Argumenty:
 *  Wektor Wektor2 - składnik sumowania
 * Zwraca:
 *  Wektor T - wynik sumowania dwóch wektorów
 */
Wektor Wektor::operator + (Wektor Wektor2)
{
    Wektor T;
    for(int i=0; i<ROZMIAR; ++i) T[i]= tab[i] + Wektor2[i];
    return T;
}

/* 
 * Przeciążenie operatora odejmowania dla wektorów
 * Argumenty:
 *  Wektor Wektor2 - odjemna dla operacji różnicy dwóch wektorów
 * Zwraca:
 *  Wektor &wynik - referencja wyniku różnicy dwóch wektorów
 */
Wektor& Wektor::operator - (Wektor Wektor2)
{
    Wektor T;
    Wektor &wynik = T;
    for(int i=0; i<ROZMIAR; ++i) T[i] = tab[i] - Wektor2[i];
    return wynik;
}
/*
// Przeciążenie iloczynu wektorowego dla wektorów
// Obecnie działa jedynie dla wektora o rozmiarze R
Wektor Wektor::operator * (Wektor Wektor2)
{
    Wektor T;
    T[1] = (tab[2]*Wektor2[2]) - (tab[3]*Wektor2[2]);
    T[2] = (-1) * ((tab[1]*Wektor2[3]) - (tab[3]*Wektor2[1]));
    T[3] = (tab[1]*Wektor2[2]) - (tab[2]*Wektor2[1]);
    return T;
} */

/* 
 * Przeciążenie operatora mnożenia dla iloczynu sklarnego
 * Argumenty:
 *  Wektor Wektor2 - czynnik mnożenia
 * Zwraca:
 *  Wektor T - wynik iloczynu skalarnego dla dwóch wektorów
 */
double Wektor::operator * (Wektor Wektor2)
{
    double T;
    for(int i=0; i<ROZMIAR; ++i) T += tab[i]*Wektor2[i];
    return T;
} 

/* 
 * Przeciążenie operatora mnożenia przez skalar
 * Argumenty:
 *  double skalar - liczba zmiennoprzecinkowa do mnożenia elementów
 * Zwraca:
 *  Wektor T - wymnożony wektor przez liczbe zmiennoprzecinkową (skalar)
 */
Wektor Wektor::operator * (double skalar)
{
    Wektor T;
    for(int i=0; i<ROZMIAR; ++i) T[i] = tab[i] * skalar;
    return T;
} 

/* 
 * Przeciążenie operatora dzilenie dla wektorów
 * posiada zabezpieczenie przed dzieleniem przez zero
 * Argumenty:
 *  Wektor Wektor2 - wektor którego elemnty są dzielną w operacji
 * Zwraca:
 *  Wektor T - wynik dzielenia
 */
Wektor Wektor::operator / (Wektor Wektor2)
{
    Wektor T;
    for(int i=0; i<ROZMIAR; ++i) 
        {
            if(Wektor2[i] == 0)
            {
                std::cerr << "Blad, nie mozna dzielic przez zero";
                break;
            }
            else {T[i] += tab[i]/Wektor2[i];}
        }
    return T;
}

/* 
 * Przeciążenie operatora przypisania dla wektora
 * Argumenty:
 *  -Wektor &Wektor2 - wektor, którego elementy przypisujemy do tab[ROZMIAR]
 * Zwraca:
 *  *this - referencja Wektora, atrybut tab[ROZMIAR], czyli miejsce przechowujące elementy wektora
 */
Wektor& Wektor::operator = (Wektor & Wektor2)
{
    for(int i=0; i<ROZMIAR; ++i) this->tab[i] = Wektor2.tab[i];
    return *this;
}

/* 
 * Medota obliczająca długość wektora
 * Argumenty:
 *  -brak
 * Zwraca:
 *  double mod - liczba zmiennoprzecinkowa, będąca długością wektora
 */
double Wektor::dlugosc()
{
    double mod=0;
    for(int i=0; i<ROZMIAR; ++i) mod+= pow(tab[i],2);
    mod = sqrt(mod);
    return mod;
}

/* 
 * Przeciążenie wczytujące Wektor ze strumienia std::istream
 * Akceptowany format prametrów wektora to liczby zmiennoprzicnkowe
 * Argumenty:
 *  Wektor &Wek - referencja wektora do którego wpisujemy parametry
 *  std::istream &Strm - referencja sturmienia wejściowego
 * Zwraca:
 *  Wczytuje strumieniem std::istream Wektor
 */
std::istream& operator >> (std::istream &Strm, Wektor &Wek)
{
    for(int i=0; i<ROZMIAR; ++i)
    {
        Strm >>Wek[i];
        if(Strm.fail()) return Strm;
    }
    return Strm;
}

/* 
 * Przeciążenie wypisujące Wektor na strumień std::ostream
 * Argumenty:
 *  Wektor Wek - wektor którego parametry wypisujemy 
 *  std::ostream &Strm - referencja sturmienia wyjściowego
 * Zwraca:
 *  Wypisuje na strumień std::ostream
 */
std::ostream& operator << (std::ostream &Strm, const Wektor &Wek)
{
    Strm << "  (" ;
    for(int i=0; i<ROZMIAR; ++i) Strm<< " " << Wek[i];
    Strm <<" )";
    return Strm;
}
 



