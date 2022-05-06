#include <iostream>
#include <fstream>
#include <unistd.h>
#include "SWektor.hh"
#include "LZespolona.hh"
#include "SMacierz.hh"
#include "SUkladRownanLiniowych.hh"
//#include "Wykonaj.hh"


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

  char jaki_typ = ' ';
  PlikUkladu>> jaki_typ;
  /*
  typename rz;
  if(jaki_typ == 'r') rz = double;
  if(jaki_typ == 'z') rz = LZespolona; */
  SUkladRownanLiniowych<LZespolona,5> uklad;


  PlikUkladu >> uklad;  
    if(uklad.licz_wyznaczniki()) // Jesli wyznacznik macierzy nie jest równy zero
    {
        uklad.licz_wyniki(); // oblicz wynik układu
        cout << uklad;
        sleep(0.001);
        cout << std::endl <<"Rozwiazanie x = (x1, x2, x3):" << std::endl;
        cout << "(";
        cout<< uklad.wyniki;  // wyślietl wyniki ukladu
        cout << " )";
        cout << std::endl;     
    //uklad.licz_wektor_bledu();  // obliczanie wektora bledu
    //uklad.wyswietl_bledy(std::cout);  // wyswietlanie wektora błedu
    cout << std::endl;
    }
    else{
        cout << "Wyznacznik macierzy równy 0!"<< std::endl <<"Układ równań jest nieoznaczony lub sprzezczny" << std::endl << std::endl;
    }

}
