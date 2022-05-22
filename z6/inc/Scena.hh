#ifndef SCENA_HH
#define SCENA_HH
#include "Lazik.hh"
#include "Kolory.hh"
#include "lacze_do_gnuplota.hh"
#include "PowierzchniaMarsa.hh"
#include <list>
#include <memory>
#include <unistd.h>
#include <iostream>
#include <fstream>

class Scena 
{
    std::shared_ptr<Lazik> AktualnyLazik;
    std::list<std::shared_ptr<Lazik>> ObiektySceny;
    PzG::LaczeDoGNUPlota Lacze;
    void Inicjalizuj_Lacze();
  public:
    Scena();
    void DodajDoListyRysowania();
    void jedziemy(std::istream& StrmWe, std::ostream& StrmWy) 
        {AktualnyLazik->jazda(Lacze, StrmWe, StrmWy);}
    void krecimy(std::istream& StrmWe, std::ostream& StrmWy)
        {AktualnyLazik->obrot(Lacze, StrmWy, StrmWe);}
    void WyborDrona(int dron);
};

#endif