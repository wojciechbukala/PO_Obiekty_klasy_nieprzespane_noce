// Wojciech Bukała, AiR, 2021/22, zadanie 6.
#include <iostream>
#include <fstream>
#include "lacze_do_gnuplota.hh"
#include "PowierzchniaMarsa.hh"
#include "Lazik.hh"
#include "Kolory.hh"
#include "Scena.hh"

using namespace std;

/*!
 * \brief inicjowanie zmiennej statycznej ilosc_wektorow
 */
template<>
  int Wektor3D::ilosc_wektorow = 0;
/*!
 * \brief inicjowanie zmiennej statycznej ilosc_aktywnych_wektorow
 */
template<>
  int Wektor3D::ilosc_aktywnych_wektorow = 0;

/*!
 * \brief inicjowanie zmiennej statycznej ilosc_wektorow
 */
template<>
  int Wektor2D::ilosc_wektorow = 0;
/*!
 * \brief inicjowanie zmiennej statycznej ilosc_aktywnych_wektorow
 */
template<>
  int Wektor2D::ilosc_aktywnych_wektorow = 0;

/*!
 * \brief funkcja wyświetla zmienne statyczne klasy SWektor zliczające liczbę jej obiektów
 * \param [in] StrmWy - referencja strumienia wyjściowego
 */
void wyswietl_wektory(std::ostream &StrmWy)
{
    StrmWy << "Aktualna ilosc obiektow Wektor3D: ";
    Wektor3D::wyswietl_ile_akt_wek(StrmWy);
    StrmWy << "  Laczna ilosc obiektow Wektor3D: ";
    Wektor3D::wyswietl_ile_wek(StrmWy);
    StrmWy << std::endl << std::endl;
}

/*!
 * \brief Funkcja main.
 * Tworzy obiekt klasy scena.
 * Wykonuje funkcjonalność menu wyboru opcji (j, o, w, m, k).
 */
int main()
{ 

  Scena s;  // tworzymy obiekt klasy scena
  char wczytany_znak = ' '; // zmienna przechowująca wczytany znak w menu wynboru opcji

  do
  {
    cout<<endl<<endl;
    s.StanAktualnegoLazika(std::cout); // wyświetlamy informacje o aktywnm laziku (położenie, kąt)
    wyswietl_wektory(std::cout); /// wyświetlamy zmienne statyczne wektora zliczające ilośc elementów klasy
  
    // menu wyboru opcji
    cout << "j-jazda na wprost" << endl;
    cout << "s-zmien szybkosc lazika" <<endl;
    cout << "o-zmien orientacje" << endl;
    cout << "p-podejmij probke (tylko dla SFR)" << endl;
    cout << "w-wybor lazika" << endl;
    cout << "l-lista probek na scenie" << endl;
    cout << "m-wyswietl menu" << endl << endl;
    cout << "k-koniec" << endl;
    cout << endl << "Twoj wybor, m - menu> ";
    cin >> wczytany_znak;

    switch(wczytany_znak)
    {
      case 'j':  // opcja jazda po prostej
      s.jedziemy(std::cin, std::cout); break;

      case 's':  // opcja zmiany szybkosci
      s.zmien_szybkosc(std::cin, std::cout); break;

      case 'o':  // opcja rotacji
      s.krecimy(std::cin, std::cout); break;

      case 'p':  // opcja podjecia próbki
      s.PodejmijProbke(std::cout); break; 

      case 'w':  // opcja wyboru łazika
      s.ZmienLazika(std::cin, std::cout); break;

      case 'l':  // opcja wyswietlania probek na scenie
      s.WyswietlProbki(std::cout); break;

      case 'm' : break;  // opcja menu

      case 'k' : break;  // opcja koniec

      default:
      cerr << "Blad! Podaj jedna z opcji."; break;
    }
  } while (wczytany_znak != 'k');
  

  cout << "Koniec dzialania programu." << endl; 

}
