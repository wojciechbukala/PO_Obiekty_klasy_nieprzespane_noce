#include <iostream>
#include <fstream>
#include "lacze_do_gnuplota.hh"
#include "PowierzchniaMarsa.hh"
#include "Lazik.hh"
#include "Kolory.hh"
#include "Scena.hh"

using namespace std;


void ZmienLazika(std::ostream &StrmWy, std::istream &StrmWe, Lazik Lazik1, Lazik Lazik2, Lazik Lazik3, Scena scena)
{
    int numer_drona; // zmienna przechowująca numer drona
    /* Interfejs wyświetlania wszystkich trzech możliwośi wyboru drona. */
    StrmWy << "1. ---------- Nazwa: Sample_Fetch_Rover" << std::endl;
    StrmWy << "          Polozenie: " << Lazik1.DajPolozenie() << std::endl;
    StrmWy << "    Orientacja [st]: " << Lazik1.DajKat() << std::endl;
    StrmWy << std::endl;
    StrmWy << "2. ---------- Nazwa: Perseverance" << std::endl;
    StrmWy << "          Polozenie: " << Lazik2.DajPolozenie() << std::endl;
    StrmWy << "    Orientacja [st]: " << Lazik2.DajKat() << std::endl;
    StrmWy << std::endl;
    StrmWy << "2. ---------- Nazwa: Curiosity" << std::endl;
    StrmWy << "          Polozenie: " << Lazik3.DajPolozenie() << std::endl;
    StrmWy << "    Orientacja [st]: " << Lazik3.DajKat() << std::endl;
    StrmWy << std::endl;
    StrmWy << "Podaj numer lazik >";
    StrmWe >> numer_drona;
    scena.WyborDrona(numer_drona);
}

template<>
  int Wektor3D::ilosc_wektorow = 0;
template<>
  int Wektor3D::ilosc_aktywnych_wektorow = 0;

int main()
{ 
  Scena s;
  s.jedziemy(cin, cout);
  s.krecimy(cin, cout);

  /*
  Wektor3D wek1(20,20,10), wek2, wek3(60,60,10), wek4(-20,70,20), wek5(20,0,0), wek6(40,0,0);


  PzG::LaczeDoGNUPlota  Lacze;

  Inicjalizuj_Lacze(Lacze);
  if (!Inicjalizuj_PowierzchnieMarsa(Lacze)) return 1;

  Lazik  Ob1("bryly_wzorcowe/szescian3.dat","FSR",Kolor_JasnoNiebieski, wek1, wek2,0, 10);
  Lazik  Ob2("bryly_wzorcowe/szescian3.dat","Perseverance",Kolor_Czerwony, wek1, wek3, 0, 10);
  Lazik  Ob3("bryly_wzorcowe/szescian3.dat","Curiosity",Kolor_Czerwony, wek1, wek4, 0, 10);  

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

  Ob1.obrot(Lacze,cout,cin);
  Ob1.jazda(Lacze, cin, cout); */

/*
  Ob1.zmien_polozenie(wek6);
  Ob1.Przelicz_i_Zapisz_Wierzcholki();
  Lacze.Rysuj(); */
  
  /*
  cout << "Nacisnij klawisz ENTER, aby zakonczyc." << endl;
  cin.ignore(100,'\n');
  Wektor3D::wyswietl_ile_wek(std::cout); */
}
