#ifndef LAZIK_HH
#define LAZIK_HH

#include <string>
#include <cmath>
#include <chrono>
#include <thread>
#include "ObiektGeom.hh"
#include "lacze_do_gnuplota.hh"


class Lazik : public ObiektGeom {
    double KatOrientacji;
    double Szybkosc;
    double OdlegloscDoPrzejechania;
    Macierz3D macierz_rotacji;
  public:
    Lazik(); //{rotacja();}; // konstrunktor bezparametryczny
    Lazik(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID, Wektor3D wczytana_skala, Wektor3D wczytane_polozenie, double kat) 
    : ObiektGeom(sNazwaPliku_BrylaWzorcowa, sNazwaObiektu, KolorID, wczytana_skala, wczytane_polozenie) {rotacja(); KatOrientacji=kat;} // konstruktor parametryczny
    void jazda(PzG::LaczeDoGNUPlota  Lacze, std::istream& StrmWej, std::ostream& StrmWyj);
    void rotacja(); // inicjowanie macierzy rotacji i przekształcanie później
    void obrot(std::ostream& StrmWyj, std::istream& StrmWej);  //  obracanie lazika
};


#endif