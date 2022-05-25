#ifndef PROBKAREGOLITU_HH
#define PROBKAREGOLITU_HH

#include <string>
#include <chrono>
#include <thread>
#include "ObiektGeom.hh"
#include "lacze_do_gnuplota.hh"


/*!
 *  \brief Klasa ProbkaRegolitu
 *
 *  Modeluje pojęcie problki regolitu
 *  czyli materiału zbieranego przez
 *  laziki z powierzchni marsa. Probka
 *  regolitu to obiekt geometryczny więc,
 *  klasa dziedziczy po ObiekGeom
 */
class ProbkaRegolitu : public ObiektGeom {
    protected:

  public:
    //std::string CzyKolizja(ObiektGeom& DrugiLazik) override;
};


#endif