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
  PlikUkladu.open("uklad.txt", std::ios::in | std::ios::out);
   
  if (PlikUkladu.is_open() == false) {
    cout<< "Blad, nie mozna otworzyc pliku "<< "uklad.txt"<<endl;
    return 1;
  }
  Wektor a, c;
  Macierz b;

  UkladRownanLiniowych u;
  
  cout << endl << " Start programu " << endl << endl;

  wykonaj(PlikUkladu, cout, u);
  /*
  PlikUkladu >>b;
  PlikUkladu >>a;
  c= b*a;
  cout << c <<endl; */
}
