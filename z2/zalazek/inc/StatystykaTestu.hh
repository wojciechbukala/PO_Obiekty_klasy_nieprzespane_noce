#ifndef STATYSTYKATESTU_HH
#define STATYSTYKATESTU_HH
#include <iostream>

/* Strruktura przechowująca      *
 * liczbe poprawnych i błędnych  *
 * odpowiedzi potrzebne do       *
 * statystyki testu              */
struct StatystykaTestu {
   int poporawne;
   int bledne;
};

void inicjuj_stat(StatystykaTestu &statystyka); //Inicjuje statystykę poprawne=0 i bledne=0
void poprawne( StatystykaTestu &statystyka); //Dodaje poprawną odpowiedź
void bledne(StatystykaTestu &statystyka); //Dodaje błędnoą odpowiedź
void Wyswietl( StatystykaTestu  statystyka ); //Wyświetla statystykę
#endif

