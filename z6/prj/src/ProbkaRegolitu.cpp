#include "ProbkaRegolitu.hh"

/*!
 * \file
 *
 *  Ostatnia modyfikacja: 2022.06.15
 */

TypKolizji ProbkaRegolitu::CzyKolizja(std::shared_ptr<Lazik> l)
{
    if(Obrys.NakladajaSie(l->Obrys)) {/*std::cout << "Kolizja" << std::endl; */return TK_Kolizja; }
    else {/* std::cout<< "brak kolizji" << std::endl; */return TK_BrakKolizji;}
}