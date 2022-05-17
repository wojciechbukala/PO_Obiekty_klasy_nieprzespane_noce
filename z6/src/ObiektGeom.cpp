#include <iostream>
#include <fstream>
#include "ObiektGeom.hh"
#include "Wektor3D.h"



using namespace std;

ObiektGeom::ObiektGeom( const char*  sNazwaPliku_BrylaWzorcowa, const char*  sNazwaObiektu, int KolorID, Wektor3D wczytana_skala, Wektor3D wczytane_polozenie):
  _NazwaPliku_BrylaWzorcowa(sNazwaPliku_BrylaWzorcowa), _KolorID(KolorID)
{
  _NazwaObiektu = sNazwaObiektu;
  _NazwaPliku_BrylaRysowana = NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA;
  _NazwaPliku_BrylaRysowana += "/";
  _NazwaPliku_BrylaRysowana += sNazwaObiektu;
  _NazwaPliku_BrylaRysowana += ".dat";
  skala = wczytana_skala;
  polozenie = wczytane_polozenie;
}


bool ObiektGeom::Przelicz_i_Zapisz_Wierzcholki()
{
  ifstream  StrmWe(_NazwaPliku_BrylaWzorcowa);
  ofstream  StrmWy(_NazwaPliku_BrylaRysowana);

  if (!(StrmWe.is_open() && StrmWy.is_open())) {
    cerr << endl << "Nie mozna otworzyc jednego z plikow:" << endl
	 << "    " << _NazwaPliku_BrylaWzorcowa << endl
	 << "    " << _NazwaPliku_BrylaRysowana << endl
	 << endl;
    return false;
  }

  Wektor3D wsp;
  int Indeks_Wiersza = 0;
  
  StrmWe >> wsp;

  if (StrmWe.fail())return false;
  
  do {
    wsp = (wsp & skala) + polozenie; 


    StrmWy << wsp << endl;
    ++Indeks_Wiersza;
    
    if (Indeks_Wiersza >= 4) {
      StrmWy << endl;
      Indeks_Wiersza = 0;
    }
    
    StrmWe >> wsp;
    
  } while (!StrmWe.fail());

  if (!StrmWe.eof()) return false;
  
  return Indeks_Wiersza == 0 && !StrmWy.fail();
}

bool ObiektGeom::Przelicz_i_Zapisz_Wierzcholki(std::ostream &StrmWy, std::istream &StrmWe)
{
  Wektor3D wsp;
  int Indeks_Wiersza = 0;
  
  StrmWe >> wsp;

  if (StrmWe.fail())return false;
  
  do {
    wsp = (wsp & skala) + polozenie; 


    StrmWy << wsp << endl;
    ++Indeks_Wiersza;
    
    if (Indeks_Wiersza >= 4) {
      StrmWy << endl;
      Indeks_Wiersza = 0;
    }
    
    StrmWe >> wsp;
    
  } while (!StrmWe.fail());

  if (!StrmWe.eof()) return false;
  
  return Indeks_Wiersza == 0 && !StrmWy.fail();
}