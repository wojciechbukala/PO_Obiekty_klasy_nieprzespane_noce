#include <iostream>
#include <fstream>
#include "Lazik.hh"

using namespace std;

/*!
 * \file
 *
 *  Ostatnia modyfikacja: 2022.06.15
 */


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


TypKolizji Lazik::CzyKolizja(std::shared_ptr<Lazik> l)
{
    if(Obrys.NakladajaSie(l->Obrys)) {/*std::cout << "Kolizja" << std::endl; */return TK_Kolizja; }
    else {/* std::cout<< "brak kolizji" << std::endl; */return TK_BrakKolizji;}
}

void Lazik::WyswietlStan(std::ostream &StrmWy)
{
    if(WezNazweObiektu()=="Perseverance") StrmWy << "2. ---------- Nazwa: Perserverance" << std::endl;
    if(WezNazweObiektu()=="Curiosity") StrmWy << "3. ---------- Nazwa: Curiosity" << std::endl;
    StrmWy << "          Polozenie: " << DajPolozenie() << std::endl;
    StrmWy << "    Orientacja [st]: " << DajKat() << std::endl;
    StrmWy << std::endl;
}
/*
void Lazik::WyswietlAktywny(std::ostream &StrmWy)
{
    if(AktualnyLazik->WezNazweObiektu()=="FSR") StrmWy << "1. ---------- Nazwa: Sample_Fetch_Rover" << std::endl;
    if(AktualnyLazik->WezNazweObiektu()=="Perseverance") StrmWy << "2. ---------- Nazwa: Perserverance" << std::endl;
    if(AktualnyLazik->WezNazweObiektu()=="Curiosity") StrmWy << "3. ---------- Nazwa: Curiosity" << std::endl;
    StrmWy << "          Polozenie: " << AktualnyLazik->DajPolozenie() << std::endl;
    StrmWy << "    Orientacja [st]: " << AktualnyLazik->DajKat() << std::endl;
    StrmWy << std::endl;
} */