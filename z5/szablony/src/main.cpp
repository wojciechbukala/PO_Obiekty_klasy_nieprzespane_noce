#include <iostream>
#include <fstream>
#include "SWektor.hh"
#include "LZespolona.hh"
#include "SMacierz.hh"



using namespace std;

// .uklad_rownan < rownanie_liniowe.dat
// Funkcja wykonująca obliczanie układu liniowego znajduje się w module Wykonaj.cpp

int main()
{ 
  fstream PlikUkladu; 
  PlikUkladu.open("uklad.txt", std::ios::in | std::ios::out); // otwieramy plik z transponowanym układem równań
   
  if (PlikUkladu.is_open() == false) {
    cout<< "Blad, nie mozna otworzyc pliku "<< "uklad.txt"<<endl;
    return 1;
  }

  cout<< "Program" <<endl;

  SMacierz<double,3> M;
  cout<< "Wyswietlanie macierzy" <<endl;
  PlikUkladu>>M;
  cout<<M<<endl;

/*
  cout<<"Wyswietlenie wektora"<<endl;
  SWektor<LZespolona,3> W, W_wynik;
  PlikUkladu>>W;
  cout<<W<<endl;
  
  cout<<"Wektor*2"<<endl;
  cout<<W*2<<endl;
  cout<<"W=W-W*0.5"<<endl;
  W_wynik = W-W*0.5;
  cout<<W_wynik<<endl; 
  */
}
