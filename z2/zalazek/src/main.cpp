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
void WykonajTest(std::istream &rStrmWej)
{
    WyrazenieZesp WyrZ; // zmienna przechowująca wyrażenie zespolone
    LZespolona Zesp, Wynik; // Zesp- liczba zespolona wczytana od użytkownika, Wynik- rezultat funkcji Oblicz()

    do
    {
        rStrmWej >> WyrZ;  // Wczytywanie wyrażenia zespolonego z pliku
        while(rStrmWej.fail()) //Sprawdzanie poprawności wczytywania z pliku
        {
          std::cerr << "Napotkano bledne wyrazenie. Zostalo ono pominiete." << std::endl;
          rStrmWej.clear();
          rStrmWej.ignore(1000, '\n');
          rStrmWej >> WyrZ;   // Wczytywanie wyrażenia zespolonego z pliku
        }

        std::cout<< std::endl<<":? Podaj wynik operacji: ";
        std::cout << WyrZ;
        Wynik= Oblicz(WyrZ);

        for(int i=0; i<3; ++i) // Trzy próby wpisania poprawnej odpowiedzi
        {
        std::cout<< std::endl << " Twoja odpowiedz: ";
        std::cin >> Zesp;   // Wczytywanie odpowiedzi użytkownika
        while(std::cin.fail())
        {
          std::cerr << "Blad wczytywania liczby zespolonej. Wpisz poprawna liczbe!" << std::endl;
          std::cin.clear();
          std::cin.ignore(1000, '\n');
          std::cout<< std::endl << " Twoja odpowiedz: ";
        std::cin >> Zesp;   // Wczytywanie odpowiedzi użytkownika
        }
          if(Zesp==Wynik) 
          {
            std::cout<<":) Odpowiedz poprawna" << std::endl;
            break;
          }
          else if(i==0 || i==1)
          {
            std::cout<< std::endl << "Blad, sprobuj jeszcze raz\n";
          }
          else if(i==2)
          { void WykonajTest(std::istream &rStrmWej);
            {
              std::cout<< ":( Blad. Prawidlowym wynikiem jest: ";
              std::cout<< Wynik;
              std::cout<< "\nWykorzystano wszystkie szanse." << std::endl;
            }
          }
        }
          std::cout << std::endl;
          rStrmWej.clear();
          rStrmWej.ignore(1000, '\n');
    } while (!rStrmWej.eof() && rStrmWej.good());
       
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

  WykonajTest(PlikTestu);
 
  /*
  WyrazenieZesp wyr;
  cin >> wyr;
  cout << wyr; */

  

  PlikTestu.close();
  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
}
