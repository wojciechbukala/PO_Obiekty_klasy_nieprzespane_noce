#include "Wektor.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

// Przeciążenie dodawania dla wektorów
Wektor Wektor::operator + (Wektor Wektor2)
{
    Wektor T;
    for(int i=0; i<ROZMIAR; ++i) T[i]= tab[i] + Wektor2[i];
    return T;
}

// Przęciążenie odejmowania dla wektorów
Wektor Wektor::operator - (Wektor Wektor2)
{
    Wektor T;
    for(int i=0; i<ROZMIAR; ++i) T[i] = tab[i] - Wektor2[i];
    return T;
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

// Przeciążenie iloczynu sklarnego dla wektora
double Wektor::operator * (Wektor Wektor2)
{
    double T;
    for(int i=0; i<ROZMIAR; ++i) T += tab[i]*Wektor2[i];
    return T;
} 

// Przeciążenie mnożenia wektora przez skalar
Wektor Wektor::operator * (double skalar)
{
    Wektor T;
    for(int i=0; i<ROZMIAR; ++i) T[i] = tab[i] * skalar;
    return T;
} 

Wektor& Wektor::operator = (Wektor & Wektor2)
{
    for(int i=0; i<ROZMIAR; ++i) this->tab[i] = Wektor2.tab[i];
    return *this;
}

//Wektor Wektor::operator / (Wektor Wektor2); // Przeciążenie odejmowania dla wektorów

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
    std::cout << "  " << std::endl;
    for(int i=0; i<ROZMIAR; ++i) Strm<< " " << Wek[i];
    return Strm;
}




