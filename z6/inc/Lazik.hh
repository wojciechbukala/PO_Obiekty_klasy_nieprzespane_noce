#ifndef LAZIK_HH
#define LAZIK_HH

#include <string>
#include <cmath>
#include <chrono>
#include <thread>
#include "ObiektGeom.hh"
#include "lacze_do_gnuplota.hh"


class Lazik : public ObiektGeom {
protected:
    double KatOrientacji;
    double Szybkosc;
    double OdlegloscDoPrzejechania;
  public:
    Lazik() ;//{rotacja();}; // konstrunktor bezparametryczny
    Lazik(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID, Wektor3D wczytana_skala, Wektor3D wczytane_polozenie, double kat, double szybkosc) 
    : ObiektGeom(sNazwaPliku_BrylaWzorcowa, sNazwaObiektu, KolorID, wczytana_skala, wczytane_polozenie) {KatOrientacji=kat; Szybkosc = szybkosc;} // konstruktor parametryczny
    void jazda(PzG::LaczeDoGNUPlota  Lacze, std::istream& StrmWej, std::ostream& StrmWyj);
    void obrot(PzG::LaczeDoGNUPlota  Lacze,std::ostream& StrmWyj, std::istream& StrmWej);  //  obracanie lazika
    void Rotacja(double kat); // zmiana macierzy rotacji
    double DajKat() {return KatOrientacji;}
    Wektor3D DajPolozenie() {return polozenie;};
};


#endif