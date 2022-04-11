#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <iostream>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Macierz {
  Wektor Tab[ROZMIAR]; // maciezrz to ROZMIAR-razy wektor
  bool zeruj (int& parzystosc); //zerowanie macierzy
  double mnozenie_diagonali () const; // mnożenie elementów na diagonali
  Wektor kopia[ROZMIAR]; // macierz do kopiowania i wykonywania obliczeń 
  void kopiuj(); // Inicjowanie kopi macierzy do wykoanywania obliczeń wyznacznika
  

  public:
  Wektor& operator * (const Wektor Wektor2) const ; // Mnożenie macierzy przez wektor 
  Wektor& operator [](int indeks)  {return Tab[indeks];} // Przeciążenie operatorea indeksowania macierza
  double operator () (int a, int b) {return Tab[a][b];} // przeciązenie operatora funkcyjnego dla klasy macierz
  Macierz& operator = (Macierz & Macierz2); // pPrzeciążenie operatora przypisania dla macierzy
  void transponuj(); // transponowanie macierzy 
  double wyznacznik_gauss (); // obliczanie wyznacznika metodą gaussa
};


/* 
 * Przeciążenie wczytujące Macierz ze strumienia std::istream
 * Akceptowany format prametrów macierzy to liczby zmiennoprzicnkowe
 * Argumenty:
 *  Macierz &Mac - referencja macierzy do któregej wpisujemy parametry
 *  std::istream &Strm - referencja sturmienia wejściowego
 * Zwraca:
 *  Wczytuje strumieniem std::istream 
 */
std::istream& operator >> (std::istream &Strm, Macierz &Mac);

/* 
 * Przeciążenie wypisujące Macierz na strumień std::ostream
 * Argumenty:
 *  Macierz - macierz której parametry wypisujemy
 *  std::ostream &Strm - referencja sturmienia wyjściowego
 * Zwraca:
 *  Wypisuje na strumień std::ostream
 */
std::ostream& operator << (std::ostream &Strm,  Macierz Mac);



#endif
