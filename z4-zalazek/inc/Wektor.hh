#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>


/*
 * Klasa wektora modelująca pojęcie wektora
 * jako tablicy jednowymiarowej o rozmiarze
 * przechowywanym w stałej ROZMIAR
 */
class Wektor {
  
  double tab[ROZMIAR]; // Wektor jako tablica jednowymiarowa

  public:
    double &operator[] (int indeks) {return tab[indeks];} // Przeciążenie indeksu wektora;
    double operator[] (int indeks) const {return tab[indeks];} // Przeciążenie indeksu wektora;
    Wektor operator + (Wektor Wektor2); // Przeciążenie dodawania dla wektorów
    Wektor& operator - (Wektor Wektor2); // Przęciążenie odejmowania dla wektorów
    //Wektor operator * (Wektor Wektor2); // Przeciążenie iloczynu wektorowego dla wektorów
    double operator * (Wektor Wektor2); // Przeciążenie iloczynu sklarnego dla wektora
    Wektor operator * (double skalar);  // Przeciążenie mnożenia wektora przez skalar
    Wektor operator / (Wektor Wektor2); // Przeciążenie odejmowania dla wektorów
    Wektor& operator = (Wektor & Wektor2); // Przeciążenie operatora przypisania dla Wektorów
    double dlugosc(); // metoda wyliczająca długość wektora
};


/* 
 * Przeciążenie wczytujące Wektor ze strumienia std::istream
 * Akceptowany format prametrów wektora to liczby zmiennoprzicnkowe
 * Argumenty:
 *  Wektor &Wek - referencja wektora do którego wpisujemy parametry
 *  std::istream &Strm - referencja sturmienia wejściowego
 * Zwraca:
 *  Wczytuje strumieniem std::istream 
 */
std::istream& operator >> (std::istream &Strm, Wektor &Wek);

/* 
 * Przeciążenie wypisujące Wektor na strumień std::ostream
 * Argumenty:
 *  Wektor Wek - wektor którego parametry wypisujemy 
 *  std::ostream &Strm - referencja sturmienia wyjściowego
 * Zwraca:
 *  Wypisuje na strumień std::ostream
 */
std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);



#endif
