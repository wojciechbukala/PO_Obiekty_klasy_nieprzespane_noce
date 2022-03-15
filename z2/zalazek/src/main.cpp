// Wojciech Bukała, zadanie 2, Programowanie obiektowe, AiR 2021/22

#include <iostream>
#include <fstream>
#include "WyrazenieZesp.hh"
#include "LZespolona.hh"
#include "StatystykaTestu.hh"

using namespace std;


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

  WykonajTest(PlikTestu);

  PlikTestu.close();
  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
}
