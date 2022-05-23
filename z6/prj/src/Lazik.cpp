#include <iostream>
#include <fstream>
#include "Lazik.hh"

using namespace std;

void Lazik::Rotacja(double kat) // zmiana macierzy rotacji
{
      MacierzRotacji[0][0] = cos(kat*3.14/180);
      MacierzRotacji[0][1] = -1*sin(kat*3.14/180);
      MacierzRotacji[0][2] = 0;
      MacierzRotacji[1][0] = sin(kat*3.14/180);
      MacierzRotacji[1][1] = cos(kat*3.14/180);
      MacierzRotacji[1][2] = 0;
      MacierzRotacji[2][0] = 0;
      MacierzRotacji[2][1] = 0;
      MacierzRotacji[2][2] = 1;
} 

void Lazik::jazda(PzG::LaczeDoGNUPlota  Lacze, std::istream& StrmWej, std::ostream& StrmWyj)
{
    StrmWyj << "Podaj odleglosc do przejechania:";
    StrmWej >> OdlegloscDoPrzejechania;
    Wektor3D nowe_polozenie = polozenie;  // wektor do obliczeń, po wykonaniu animacji ma nowe współżędne
    double x_kierunek = cos(KatOrientacji*3.14/180); // przesuniecie o x , double x = OdlegloscDoPrzejechania * cos(KatOrientacji)
    double y_kierunek = sin(KatOrientacji*3.14/180); // przesuniecie o y , double y = OdlegloscDoPrzejechania * sin(KatOrientacji)
    std::cout << "Kat: " << KatOrientacji << std::endl;
    for(double i = 0 ; i < OdlegloscDoPrzejechania; ++i)  // dzielimy przejście na OdlegloscDoPrzejechania*100 małych kroczkow
      {
      nowe_polozenie[0] += x_kierunek;
      nowe_polozenie[1] += y_kierunek;  
      zmien_polozenie(nowe_polozenie);
      if(Przelicz_i_Zapisz_Wierzcholki()) std::this_thread::sleep_for(std::chrono::milliseconds(200/int(Szybkosc))); // odstęp czasowy zależny od szybkości
      Lacze.Rysuj();
      }
      polozenie = nowe_polozenie; // zmieniamy położenie łazika na stałe
} 

void Lazik::obrot(PzG::LaczeDoGNUPlota  Lacze, std::ostream& StrmWyj, std::istream& StrmWej)
{
    StrmWyj << "Podaj kat obrotu: ";
    double nowy_kat;
    StrmWej >> nowy_kat;
    for(double i = KatOrientacji; i<nowy_kat + KatOrientacji; ++i)
    {
        Rotacja(i);
        Przelicz_i_Zapisz_Wierzcholki();
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
        Lacze.Rysuj();
    }
    KatOrientacji += nowy_kat;
}