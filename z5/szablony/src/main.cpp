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
// Specjalizacja szablonu

int main()
{ 

  fstream PlikUkladu; 
  PlikUkladu.open("uklad_double.txt", std::ios::in | std::ios::out); // otwieramy plik z transponowanym układem równań
   
  if (PlikUkladu.is_open() == false) {
    cout<< "Blad, nie mozna otworzyc pliku "<< "uklad_zesp.txt"<<endl;
    return 1;
  }

  SUkladRownanLiniowych<LZespolona,5> uklad_zesp;
  SUkladRownanLiniowych<double,5> uklad_double;
  char jaki_typ = ' ';
  PlikUkladu>> jaki_typ;



if(jaki_typ == 'r') {
  PlikUkladu >> uklad_double;  
    if(uklad_double.licz_wyznaczniki()) // Jesli wyznacznik macierzy nie jest równy zero
    {
        uklad_double.licz_wyniki(); // oblicz wynik układu
        cout << uklad_double;
        sleep(0.001);
        cout << std::endl <<"Rozwiazanie x = (x1, x2, x3, x4, x5):" << std::endl;
        cout << "(";
        cout<< uklad_double.wyniki;  // wyślietl wyniki ukladu
        cout << " )";
        cout << std::endl;     
    //uklad.licz_wektor_bledu();  // obliczanie wektora bledu
    //uklad.wyswietl_bledy(std::cout);  // wyswietlanie wektora błedu
    cout << std::endl;
    SWektor<double,2> wek;
    cout<< "Modyfikacja dla wektora, wypisywanie transponowane" <<endl;
    PlikUkladu >> wek;
    cout << wek;
    }
    else{
        cout << "Wyznacznik macierzy równy 0!"<< std::endl <<"Układ równań jest nieoznaczony lub sprzezczny" << std::endl << std::endl;
    }
} else if(jaki_typ == 'z') {
  PlikUkladu >> uklad_zesp;  
    if(uklad_zesp.licz_wyznaczniki()) // Jesli wyznacznik macierzy nie jest równy zero
    {
        uklad_zesp.licz_wyniki(); // oblicz wynik układu
        cout << uklad_zesp;
        sleep(0.001);
        cout << std::endl <<"Rozwiazanie x = (x1, x2, x3, x4, x5):" << std::endl;
        cout << "(";
        cout<< uklad_zesp.wyniki;  // wyślietl wyniki ukladu
        cout << " )";
        cout << std::endl;     
    //uklad.licz_wektor_bledu();  // obliczanie wektora bledu
    //uklad.wyswietl_bledy(std::cout);  // wyswietlanie wektora błedu
    cout << std::endl;
    SWektor<LZespolona,2> wek;
    cout<< "Modyfikacja dla wektora, wypisywanie transponowane" <<endl;
    PlikUkladu >> wek;
    cout << wek;
    }
    else{
        cout << "Wyznacznik macierzy równy 0!"<< std::endl <<"Układ równań jest nieoznaczony lub sprzezczny" << std::endl << std::endl;
    }
} else cout<< "Nie odczytano r lub z, z pliku." <<endl;


}
