#include "LazikSFR.hh"



TypKolizji LazikSFR::CzyKolizja(std::shared_ptr<Lazik> l)
{
    if(Obrys.NakladajaSie(l->Obrys)) {return TK_Kolizja; }
    else {return TK_BrakKolizji;}
}


void LazikSFR::DodajDoListyProbek (std::shared_ptr<ProbkaRegolitu> ProbRego)
{
    ListaProbek.push_back(ProbRego); // dodajemy do listy próbek łazika SFR zadaną próbkę
}