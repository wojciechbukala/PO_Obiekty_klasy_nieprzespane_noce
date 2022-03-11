#include <iostream>
#include <fstream>
#include "WyrazenieZesp.hh"

using namespace std;




void WykonajTest(istream &rStrmWej)
{
  WyrazenieZesp   WyrZ_PytanieTestowe;
   
  while (WczytajWyrazenieZesp(WyrZ_PytanieTestowe, rStrmWej)) {
    cout << " Czesc rzeczywista pierwszego argumentu: ";
    cout << WyrZ_PytanieTestowe.Arg1.re << endl;
  }
}





int main(int argc, char **argv)
{

  if (argc < 2) {
    cerr << endl;
    cerr << " Brak nazwy pliku z zawartoscia testu." << endl;
    cerr << endl;
    return 1;
  }

  ifstream  PlikTestu(argv[1]);

  if (PlikTestu.is_open() == false) {
    cout<< "Blad, nie mozna otworzyc pliku "<< argv[1]<<endl;
    return 1;
  }

  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;
  /**/
  LZespolona zespolona;
  WczytajZesp(zespolona, PlikTestu);
    cout <<"re= " <<zespolona.re << endl;
    cout <<"im= " <<zespolona.im <<endl;
  
  //WykonajTest(PlikTestu);
  
  PlikTestu.close();
  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
}
