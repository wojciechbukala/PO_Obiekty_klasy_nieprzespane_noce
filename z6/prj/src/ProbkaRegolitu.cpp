#include "ProbkaRegolitu.hh"

TypKolizji ProbkaRegolitu::CzyKolizja(std::shared_ptr<Lazik> l)
{
    if(Obrys.NakladajaSie(l->Obrys)) {/*std::cout << "Kolizja" << std::endl; */return TK_Kolizja; }
    else {/* std::cout<< "brak kolizji" << std::endl; */return TK_BrakKolizji;}
}