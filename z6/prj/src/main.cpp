#include <iostream>
#include <fstream>
#include "lacze_do_gnuplota.hh"
#include "PowierzchniaMarsa.hh"
#include "Lazik.hh"
#include "Kolory.hh"
#include "Scena.hh"

using namespace std;

template<>
  int Wektor3D::ilosc_wektorow = 0;
template<>
  int Wektor3D::ilosc_aktywnych_wektorow = 0;

void wyswietl_wektory(std::ostream &StrmWy)
{
    StrmWy << "Aktualna ilosc obiektow Wektor3D: ";
    Wektor3D::wyswietl_ile_akt_wek(StrmWy);
    StrmWy << "  Laczna ilosc obiektow Wektor3D: ";
    Wektor3D::wyswietl_ile_wek(StrmWy);
    StrmWy << std::endl << std::endl;
}

int main()
{ 
  
  Scena s;
  char wczytany_znak = ' ';

  do
  {
    cout<<endl<<endl;
    s.WyswietlAktywny(std::cout); // wyświetlamy informacje o aktywnm laziku (położenie, kąt)
    wyswietl_wektory(std::cout); /// wyświetlamy zmienne statyczne wektora zliczające ilośc elementów klasy
  
    cout << "j-jazda na wprost" << endl;
    cout << "o-zmien orientacje" << endl;
    cout << "w-wybor lazika" << endl;
    cout << "m-wyswietl menu" << endl << endl;
    cout << "k-koniec" << endl;
    cin >> wczytany_znak;

    switch(wczytany_znak)
    {
      case 'j':
      s.jedziemy(std::cin, std::cout); break;

      case 'o':
      s.krecimy(std::cin, std::cout); break;

      case 'w':
      s.ZmienDrona(std::cin, std::cout); break;

      case 'm' : break;

      case 'k' : break;

      default:
      cerr << "Blad! Podaj jedna z opcji."; break;
    }
  } while (wczytany_znak != 'k');
  
  cout << "Koniec dzialania programu." << endl;

}
