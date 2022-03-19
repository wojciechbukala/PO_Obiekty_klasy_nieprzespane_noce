// Wojciech Bukała, zadanie 2, Programowanie obiektowe, AiR 2021/22

#include <iostream>
#include <fstream>
#include "StatystykaTestu.hh"
#include "WyrazenieZesp.hh"

using namespace std;


/*!
 * Realizuje działanie testu liczb zespolonych
 * Argumenty:
 *    &rStrmWe - referencja strumienia wejsciowego
 */
/*void WykonajTest(std::istream &rStrmWej)
{
    WyrazenieZesp WyrZ; // zmienna przechowująca wyrażenie zespolone
    LZespolona Zesp, Wynik; // Zesp- liczba zespolona wczytana od użytkownika, Wynik- rezultat funkcji Oblicz()
    do
    {
        rStrmWej << WyrZ;
        std::cout<< std::endl<<": ? Podaj wynik operacji: ";
        cout << WyrZ;
        std::cout<< std::endl << " Twoja odpowiedz: ";
        cin >> Zesp;   // Wczytywanie odpowiedzi użytkownika
        Wynik= Oblicz(WyrZ);
        if(Zesp==Wynik) std::cout<<":) Odpowiedz poprawna" << std::endl;
        else 
        {
            std::cout<< ":( Blad. Prawidlowym wynikiem jest: ";
            WyswietlZesp(Wynik);
        }
        std::cout << std::endl;
    } while (rStrmWej.good()); 
       
} */


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

  //WykonajTest(PlikTestu);

  WyrazenieZesp wyr;
  cin >> wyr;

  

  PlikTestu.close();
  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
}
