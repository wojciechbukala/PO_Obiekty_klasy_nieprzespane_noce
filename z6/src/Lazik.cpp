#include <iostream>
#include <fstream>
#include "Lazik.hh"

using namespace std;

void Lazik::jazda(PzG::LaczeDoGNUPlota  Lacze, std::istream& StrmWej, std::ostream& StrmWyj)
{
    StrmWyj << "Podaj odleglosc do przejechania:";
    StrmWej >> OdlegloscDoPrzejechania;
    Wektor3D nowe_polozenie = polozenie;  // wektor do obliczeń, po wykonaniu animacji ma nowe współżędne
    Szybkosc = 30; // tymczasowo do testowania
    double x_kierunek = cos(KatOrientacji)/100; // przesuniecie o x , double x = OdlegloscDoPrzejechania * cos(KatOrientacji)
    double y_kierunek = sin(KatOrientacji)/100; // przesuniecie o y , double y = OdlegloscDoPrzejechania * sin(KatOrientacji)
    for(double i = 0 ; i <= OdlegloscDoPrzejechania*100; ++i)  // dzielimy przejście na OdlegloscDoPrzejechania*100 małych kroczkow
      {
      nowe_polozenie[0] += x_kierunek;
      nowe_polozenie[1] += y_kierunek;  
      zmien_polozenie(nowe_polozenie);
      if(Przelicz_i_Zapisz_Wierzcholki())  Lacze.Rysuj();;
     // Lacze.Rysuj();
      std::this_thread::sleep_for(std::chrono::milliseconds(20/int(Szybkosc))); // odstęp czasowy zależny od szybkości
      }
      polozenie = nowe_polozenie; // zmieniamy położenie łazika na stałe
} 

void Lazik::rotacja()
{
/* Przypisujemy macierzy rotacji jej pola w podany sposób */
    macierz_rotacji[0][0] = cos(KatOrientacji);
    macierz_rotacji[0][1] = sin(KatOrientacji);
    macierz_rotacji[0][2] = 0;
    macierz_rotacji[1][0] = -1*sin(KatOrientacji);
    macierz_rotacji[1][1] = cos(KatOrientacji);
    macierz_rotacji[1][2] = 0;
    macierz_rotacji[2][0] = 0;
    macierz_rotacji[2][1] = 0;
    macierz_rotacji[2][2] = 1;
    std::cout<< macierz_rotacji << std::endl;
} 

void Lazik::obrot(std::ostream& StrmWyj, std::istream& StrmWej)
{
    Wektor3D nowe_polozenie; // wektor określający nowe polożenie 
    StrmWyj << "Podaj kat obrotu: ";
    StrmWej >> KatOrientacji;
    rotacja();
    nowe_polozenie = macierz_rotacji * polozenie;
    std::cout << polozenie << std::endl;
    polozenie = nowe_polozenie;
    std::cout << polozenie << std::endl;
}