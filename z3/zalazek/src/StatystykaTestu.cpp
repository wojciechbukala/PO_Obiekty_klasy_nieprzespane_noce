#include "StatystykaTestu.hh"
#include <iostream>
#include <cmath>
#include <fstream>

void StatystykaTestu::inicjuj_stat() //Inicjuje statystykę poprawne=0 i bledne=0
{
  poprawne=0;
  bledne=0;
}

void StatystykaTestu::poprawna_odp() //Dodaje poprawną odpowiedź
{
  ++poprawne;
}

void StatystykaTestu::bledna_odp() //Dodaje błędnoą odpowiedź
{
  ++bledne;
}

void StatystykaTestu::Wyswietl() //Wyświetla statystykę
{
  std::cout << "Ilosc dobrych odpowiedzi: " << poprawne << std::endl;
  std::cout << "Ilosc blednych odpowiedzi: " << bledne << std::endl;
  std::cout << "Wynik procentowy poprawnych odpowiedzi:   ";
  std::cout << (double)poprawne/(poprawne + bledne) * 100;
  std::cout << "%" << std::endl;
}

