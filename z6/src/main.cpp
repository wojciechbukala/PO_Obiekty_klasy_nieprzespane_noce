#include <iostream>
#include <fstream>
#include "lacze_do_gnuplota.hh"
#include "PowierzchniaMarsa.hh"
#include "ObiektGeom.hh"
#include "Lazik.hh"
#include "Kolory.hh"
#include "Wektor3D.h"


using namespace std;




/*!
 *  \brief Inicjalizuje połączenie z programem gnuplot oraz rozmiar świata.
 *
 *  Inicjalizuje podstawowe parametry "swiata", tzn. jego wymiary,
 *  które będą widoczne jako obszar objęty układem współrzędnych.
 *  Następnie w tle uruchamiany jest program gnuplot.
 *  \param[in] rLacze - nieaktywne łącze do gnuplota.
 */
void Inicjalizuj_Lacze(PzG::LaczeDoGNUPlota  &rLacze)
{
  rLacze.ZmienTrybRys(PzG::TR_3D);
  rLacze.UstawZakresX(-ROMIAR_POWIERZCHNI_X/2, ROMIAR_POWIERZCHNI_X/2);
  rLacze.UstawZakresY(-ROMIAR_POWIERZCHNI_Y/2, ROMIAR_POWIERZCHNI_Y/2);
  rLacze.UstawZakresZ(-0, 90);  
  rLacze.UstawRotacjeXZ(40,60); // Tutaj ustawiany jest widok

  rLacze.Inicjalizuj();  // Tutaj startuje gnuplot.
}



void DodajDoListyRysowania(PzG::LaczeDoGNUPlota &rLacze, const ObiektGeom  &rOb)
{
  PzG::InfoPlikuDoRysowania *wInfoPliku;
  
  wInfoPliku = &rLacze.DodajNazwePliku(rOb.WezNazwePliku_BrylaRysowana());
  wInfoPliku->ZmienKolor(rOb.WezKolorID());
}

template<>
  int Wektor3D::ilosc_wektorow = 0;
template<>
  int Wektor3D::ilosc_aktywnych_wektorow = 0;

int main()
{
  Wektor3D wek1(20,20,10), wek2, wek3(60,60,10), wek4(-20,70,20), wek5(20,0,0), wek6(40,0,0);


  PzG::LaczeDoGNUPlota  Lacze;

  Inicjalizuj_Lacze(Lacze);
  if (!Inicjalizuj_PowierzchnieMarsa(Lacze)) return 1;

  Lazik  Ob1("bryly_wzorcowe/szescian3.dat","FSR",Kolor_JasnoNiebieski, wek1, wek2);
  Lazik  Ob2("bryly_wzorcowe/szescian3.dat","Perseverance",Kolor_Czerwony, wek1, wek3);
  Lazik  Ob3("bryly_wzorcowe/szescian3.dat","Curiosity",Kolor_Czerwony, wek1, wek4);  

  DodajDoListyRysowania(Lacze,Ob1);
  DodajDoListyRysowania(Lacze,Ob2);
  DodajDoListyRysowania(Lacze,Ob3);

  Ob1.Przelicz_i_Zapisz_Wierzcholki();
  Ob2.Przelicz_i_Zapisz_Wierzcholki();
  Ob3.Przelicz_i_Zapisz_Wierzcholki();  
  
  cout << endl << "Start programu gnuplot" << endl << endl;
  Lacze.Rysuj();

  cout << "Nacisnij klawisz ENTER, aby FSR wykonal przesuniecie." << endl;
  cin.ignore(100,'\n');

/*
  Ob1.zmien_polozenie(wek5);
  Ob1.Przelicz_i_Zapisz_Wierzcholki();
  Lacze.Rysuj(); */

  //Ob1.jazda(Lacze, wek5);

  cout << "Nacisnij klawisz ENTER, aby FSR wykonal przesuniecie." << endl;
  cin.ignore(100,'\n');

  Ob1.zmien_polozenie(wek6);
  Ob1.Przelicz_i_Zapisz_Wierzcholki();
  Lacze.Rysuj();
  
  cout << "Nacisnij klawisz ENTER, aby zakonczyc." << endl;
  cin.ignore(100,'\n');
  Wektor3D::wyswietl_ile_wek(std::cout);
}
