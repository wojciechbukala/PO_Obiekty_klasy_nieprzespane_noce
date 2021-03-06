// Wojciech Bukała, zadanie 2, Programowanie obiektowe, AiR 2021/22

#include <iostream>
#include <fstream>
#include "WykonajTest.hh"

using namespace std;

/* funkcja main
 * otwiera plik oraz uruchamia funkcje wykonaj test
 */
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

  WykonajTest(PlikTestu);  // wykonujemy test z modulu WykonajTest

  PlikTestu.close();
  
  return 0;
}
