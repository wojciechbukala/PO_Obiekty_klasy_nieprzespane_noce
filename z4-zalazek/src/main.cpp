#include <iostream>
#include <fstream>
//#include <unistd.h>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"

void przypisz (Macierz x, Macierz &z)
{
  for(int i=0; i<ROZMIAR; ++i)
  for(int j=0; j<ROZMIAR; ++j)
  z[i][j] = x[i][j];
}


using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{
  //UkladRownanLiniowych   UklRown;   // To tylko przykladowe definicje zmiennej
  
  fstream PlikUkladu;
  PlikUkladu.open("uklad.txt", std::ios::in | std::ios::out);
   
  if (PlikUkladu.is_open() == false) {
    cout<< "Blad, nie mozna otworzyc pliku "<< "uklad.txt"<<endl;
    return 1;
  }

  Wektor a, b;
  Macierz x, z;
  PlikUkladu>>x;
  PlikUkladu>>a;
  
  double wyznacznik;

  wyznacznik = x.wyznacznik_gauss();
  cout<< wyznacznik <<endl;
 
  //przypisz(x.zeruj(),z);
  
  //cout<<z;

  
  //cout << endl << " Start programu " << endl << endl;

  //sleep(0.001);
}
