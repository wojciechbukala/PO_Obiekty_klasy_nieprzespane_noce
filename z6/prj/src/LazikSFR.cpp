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

void LazikSFR::WyswietlListeProbek(std::ostream &StrmWy)
{
    int i=1;
    if(ListaProbek.empty()) {StrmWy << "                         (brak probek na liscie)" << std::endl; }
    else{
    for(const std::shared_ptr<ProbkaRegolitu> & Pr : ListaProbek)
    {
            
            StrmWy<<"                         "<<i<<". ";
            StrmWy << Pr->DajNazweObiektu() << std::endl;
        ++i;
    }
    }
}

void LazikSFR::WyswietlStan(std::ostream &StrmWy)
{
    StrmWy << "1. ---------- Nazwa: Sample_Fetch_Rover" << std::endl;
    StrmWy << "              Polozenie: " << DajPolozenie() << std::endl;
    StrmWy << "        Orientacja [st]: " << DajKat() << std::endl;
    StrmWy << " Lista zebranych probek: " << std::endl;
    WyswietlListeProbek(StrmWy);
    StrmWy << std::endl;
}