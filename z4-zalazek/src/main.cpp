#include <iostream>
#include <fstream>
//#include <unistd.h>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"



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

  Wektor y, z;
  Macierz x;
  PlikUkladu>>x;
  PlikUkladu>>y>>z;
 
  
  x.transponuj();
  cout << "Transpozycja:";
  cout<<x<<endl;
  
  cout<<endl<< "wynik:" <<endl;
  cout<<x*y;

  cout<<endl<<y+z<<endl<<y-z<<endl<<" "<<y*z<<y*2.0<<endl;

  
  //cout << endl << " Start programu " << endl << endl;

  //sleep(0.001);
}
