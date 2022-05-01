#include <iostream>
#include <fstream>
#include "SWektor.hh"
#include "LZespolona.hh"



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

  cout<< "Program" <<endl;

  // Testowanie szablonu wektora dla rzeczywistych  
  
  /*
  LZespolona zesp;
  cin>>zesp;
  cout<<zesp;
  */

  cout<<"Wyswietlenie wektora"<<endl;
  SWektor<LZespolona,3> W, W_wynik;
  PlikUkladu>>W;
  cout<<W<<endl;
  
  cout<<"Wektor*2"<<endl;
  cout<<W*2<<endl;
  cout<<"W=W-W*0.5"<<endl;
  W_wynik = W-W*0.5;
  cout<<W_wynik<<endl; 
  
}
