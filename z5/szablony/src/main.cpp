#include <iostream>
#include <fstream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"
#include "Wykonaj.hh"


using namespace std;

// Funkcja wykonująca obliczanie układu liniowego znajduje się w module Wykonaj.cpp

int main()
{ 
  fstream PlikUkladu; 
  PlikUkladu.open("uklad.txt", std::ios::in | std::ios::out); // otwieramy plik z transponowanym układem równań
   
  if (PlikUkladu.is_open() == false) {
    cout<< "Blad, nie mozna otworzyc pliku "<< "uklad.txt"<<endl;
    return 1;
  }

  // Testowanie szablonu wektora dla rzeczywistych  
  
}
