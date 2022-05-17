#ifndef OBIEKTGEOM_HH
#define OBIEKTGEOM_HH

#include <string>
#include "Wektor3D.h"

#define NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA    "pliki_do_rysowania"

class ObiektGeom {
    std::string   _NazwaPliku_BrylaWzorcowa;
    std::string   _NazwaPliku_BrylaRysowana;
    std::string   _NazwaObiektu;
    int           _KolorID;
    //Wektor3D skala;
    Wektor3D polozenie;
  
  public:
  Wektor3D skala;
    ObiektGeom(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID, Wektor3D wczytana_skala, Wektor3D wczytane_polozenie);
    int WezKolorID() const { return _KolorID; }
    const std::string & WezNazweObiektu() const { return _NazwaObiektu; }
    const std::string & WezNazwePliku_BrylaRysowana() const { return _NazwaPliku_BrylaRysowana; }
    /*   Przeciążenia funkcji Przelicz_i_Zapisz_Wierzchołki   */
    bool Przelicz_i_Zapisz_Wierzcholki(); // funkcja z strumieniami branymi z pól klasy
    bool Przelicz_i_Zapisz_Wierzcholki(std::ostream &StrmWy, std::istream &StrmWe); // zdekomponowana funkcja z możliwością zmiany strumienia wejściowego i wyjściowego
    void zmien_polozenie(Wektor3D nowy) {polozenie = nowy;};   
};


#endif
