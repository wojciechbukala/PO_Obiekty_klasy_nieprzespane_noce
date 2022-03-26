#ifndef STATYSTYKATESTU_HH
#define STATYSTYKATESTU_HH
#include <iostream>

/* Klasa przechowująca      *
 * liczbe poprawnych i błędnych  *
 * odpowiedzi potrzebne do       *
 * statystyki testu              */
class StatystykaTestu {
   
      int poprawne;  // zmienna przechowująca ilość poprawnych odpowiedzi
      int bledne;     // zmienna przechowująca ilość błędnych odpowiedzi

   public:
      void inicjuj_stat(); //Inicjuje statystykę poprawne=0 i bledne=0
      void poprawna_odp(); //Dodaje poprawną odpowiedź
      void bledna_odp(); //Dodaje błędnoą odpowiedź
      void Wyswietl(); //Wyświetla statystykę
};

#endif

