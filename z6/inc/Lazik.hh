#ifndef LAZIK_HH
#define LAZIK_HH

#include <string>
#include <cmath>
#include "ObiektGeom.hh"
#include "lacze_do_gnuplota.hh"


class Lazik : public ObiektGeom {
    double KatOrientacji;
    double Szybkosc;
    double OdlegloscDoPrzejechania;
  public:
    Lazik(); // konstrunktor bezparametryczny
    Lazik(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID, Wektor3D wczytana_skala, Wektor3D wczytane_polozenie) : ObiektGeom(sNazwaPliku_BrylaWzorcowa, sNazwaObiektu, KolorID, wczytana_skala, wczytane_polozenie) {} // konstruktor parametryczny
    /*void jazda(PzG::LaczeDoGNUPlota  Lacze, std::istream StrmWej)
    {
    StrmWej >> OdlegloscDoPrzejechania;
    Wektor3D nowe_polozenie = polozenie;
    nowe_polozenie[0] += OdlegloscDoPrzejechania * cos(KatOrientacji);
    nowe_polozenie[1] += OdlegloscDoPrzejechania * sin(KatOrientacji);
    for(double i = 0 ; i <= OdlegloscDoPrzejechania; ++i)  // ++i zmienić coś z szybkością
    zmien_polozenie();
    Przelicz_i_Zapisz_Wierzcholki();
    Lacze.Rysuj();
    } */
};


#endif