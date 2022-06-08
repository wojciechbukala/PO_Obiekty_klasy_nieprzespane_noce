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


TypKolizji Lazik::CzyKolizja(std::shared_ptr<Lazik> l)
{
    if(Obrys.NakladajaSie(l->Obrys)) {/*std::cout << "Kolizja" << std::endl; */return TK_Kolizja; }
    else {/* std::cout<< "brak kolizji" << std::endl; */return TK_BrakKolizji;}
}

