#include <iostream>
#include <fstream>
#include "Lazik.hh"

using namespace std;

void Lazik::jazda(PzG::LaczeDoGNUPlota  Lacze, Wektor3D nowe_polozenie)
{
    zmien_polozenie(nowe_polozenie);
    Przelicz_i_Zapisz_Wierzcholki();
    Lacze.Rysuj();
}