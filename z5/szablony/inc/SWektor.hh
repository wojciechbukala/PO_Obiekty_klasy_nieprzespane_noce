#ifndef SWektor_HH
#define SWektor_HH

#include <iostream>
#include "LZespolona.hh"


/*
 * Klasa SWektora modelująca pojęcie SWektora
 * jako tablicy jednowymiarowej o<wymiarze
 * przechowywanym w stałej<wymiar
 */
template <typename typ, int wymiar>
class SWektor {
  
  typ tab[wymiar]; // SWektor jako tablica jednowymiarowa

  public:
    typ &operator[] (int indeks) {return tab[indeks];} // Przeciążenie indeksu SWektora;
    typ operator[] (int indeks) const {return tab[indeks];} // Przeciążenie indeksu SWektora;
    SWektor<typ,wymiar> operator + (SWektor<typ,wymiar> SWektor2); // Przeciążenie dodawania dla SWektorów
    SWektor<typ,wymiar>& operator - (SWektor<typ, wymiar> SWektor2); // Przęciążenie odejmowania dla SWektorów
    typ operator * (SWektor SWektor2); // Przeciążenie iloczynu sklarnego dla SWektora
    SWektor<typ,wymiar> operator * (typ skalar);  // Przeciążenie mnożenia SWektora przez skalar
    SWektor<typ,wymiar> operator / (SWektor<typ,wymiar> SWektor2); // Przeciążenie odejmowania dla SWektorów
    SWektor<typ,wymiar>& operator = (SWektor<typ,wymiar>& SWektor2); // Przeciążenie operatora przypisania dla SWektorów
    typ dlugosc(); // metoda wyliczająca długość SWektora
};


/* 
 * Przeciążenie operatora dodawania dla SWektorów
 * Argumenty:
 *  SWektor SWektor2 - składnik sumowania
 * Zwraca:
 *  SWektor T - wynik sumowania dwóch SWektorów
 */
 template <typename typ, int wymiar>
SWektor<typ, wymiar> SWektor<typ, wymiar>::operator + (SWektor<typ,wymiar> SWektor2)
{
    SWektor<typ,wymiar> T;
    for(int i=0; i<wymiar; ++i) T[i]= tab[i] + SWektor2[i];
    return T;
}

/* 
 * Przeciążenie operatora odejmowania dla SWektorów
 * Argumenty:
 *  SWektor SWektor2 - odjemna dla operacji różnicy dwóch SWektorów
 * Zwraca:
 *  SWektor &wynik - referencja wyniku różnicy dwóch SWektorów
 */
template <typename typ, int wymiar>
SWektor<typ, wymiar>& SWektor<typ, wymiar>::operator - (SWektor<typ,wymiar> SWektor2)
{
    SWektor<typ,wymiar> T;
    SWektor<typ,wymiar> &wynik = T;
    for(int i=0; i<wymiar; ++i) T[i] = tab[i] - SWektor2[i];
    return wynik;
}

/* 
 * Przeciążenie operatora mnożenia dla iloczynu sklarnego
 * Argumenty:
 *  SWektor SWektor2 - czynnik mnożenia
 * Zwraca:
 *  SWektor T - wynik iloczynu skalarnego dla dwóch SWektorów
 */
template <typename typ, int wymiar>
typ SWektor<typ,wymiar>::operator * (SWektor<typ,wymiar> SWektor2)
{
    typ T;
    for(int i=0; i<wymiar; ++i) T += tab[i]*SWektor2[i];
    return T;
} 

/* 
 * Przeciążenie operatora mnożenia przez skalar
 * Argumenty:
 *  double skalar - liczba zmiennoprzecinkowa do mnożenia elementów
 * Zwraca:
 *  SWektor T - wymnożony SWektor przez liczbe zmiennoprzecinkową (skalar)
 */
template <typename typ, int wymiar>
SWektor<typ,wymiar> SWektor<typ,wymiar>::operator * (typ skalar)
{
    SWektor<typ,wymiar> T;
    for(int i=0; i<wymiar; ++i) T[i] = tab[i] * skalar;
    return T;
} 

/* 
 * Przeciążenie operatora dzilenie dla SWektorów
 * posiada zabezpieczenie przed dzieleniem przez zero
 * Argumenty:
 *  SWektor SWektor2 - SWektor którego elemnty są dzielną w operacji
 * Zwraca:
 *  SWektor T - wynik dzielenia
 */
template <typename typ, int wymiar>
SWektor<typ,wymiar> SWektor<typ,wymiar>::operator / (SWektor<typ,wymiar> SWektor2)
{
    SWektor<typ,wymiar> T;
    for(int i=0; i<wymiar; ++i) 
        {
            if(SWektor2[i] == 0)
            {
                std::cerr << "Blad, nie mozna dzielic przez zero";
                break;
            }
            else {T[i] += tab[i]/SWektor2[i];}
        }
    return T;
}

/* 
 * Przeciążenie operatora przypisania dla SWektora
 * Argumenty:
 *  -SWektor &SWektor2 - SWektor, którego elementy przypisujemy do tab<wymiar]
 * Zwraca:
 *  *this - referencja SWektora, atrybut tab<wymiar], czyli miejsce przechowujące elementy SWektora
 */
template <typename typ, int wymiar>
SWektor<typ,wymiar>& SWektor<typ,wymiar>::operator = (SWektor<typ,wymiar> & SWektor2)
{
    for(int i=0; i<wymiar; ++i) this->tab[i] = SWektor2.tab[i];
    return *this;
}

/* 
 * Medota obliczająca długość SWektora
 * Argumenty:
 *  -brak
 * Zwraca:
 *  double mod - liczba zmiennoprzecinkowa, będąca długością SWektora
 */
template <typename typ, int wymiar>
typ SWektor<typ,wymiar>::dlugosc()
{
    typ mod=0;
    for(int i=0; i<wymiar; ++i) mod+= pow(tab[i],2);
    mod = sqrt(mod);
    return mod;
}

/* 
 * Przeciążenie wczytujące SWektor ze strumienia std::istream
 * Akceptowany format prametrów SWektora to liczby zmiennoprzicnkowe
 * Argumenty:
 *  SWektor &Wek - referencja SWektora do którego wpisujemy parametry
 *  std::istream &Strm - referencja sturmienia wejściowego
 * Zwraca:
 *  Wczytuje strumieniem std::istream SWektor
 */

template <typename typ, int wymiar>
std::istream& operator >> (std::istream &Strm, SWektor<typ,wymiar> &Wek)
{
    for(int i=0; i<wymiar; ++i)
    {
        Strm >>Wek[i];
        if(Strm.fail()) return Strm;
    }
    return Strm;
}

/* 
 * Przeciążenie wypisujące SWektor na strumień std::ostream
 * Argumenty:
 *  SWektor Wek - SWektor którego parametry wypisujemy 
 *  std::ostream &Strm - referencja sturmienia wyjściowego
 * Zwraca:
 *  Wypisuje na strumień std::ostream
 */
template <typename typ, int wymiar>
std::ostream& operator << (std::ostream &Strm, const SWektor<typ,wymiar> &Wek)
{
    
    for(int i=0; i<wymiar; ++i) Strm<< " " << Wek[i];
    
    return Strm;
}

#endif
