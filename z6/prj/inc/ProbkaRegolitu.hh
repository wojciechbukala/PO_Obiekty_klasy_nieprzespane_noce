#ifndef PROBKAREGOLITU_HH
#define PROBKAREGOLITU_HH

#include "ObiektGeom.hh"
#include "Lazik.hh"


/*!
 *  \brief Klasa ProbkaRegolitu
 *
 *  Modeluje pojęcie problki regolitu
 *  czyli materiału zbieranego przez
 *  laziki z powierzchni marsa. Probka
 *  regolitu to obiekt geometryczny więc,
 *  klasa dziedziczy po ObiekGeom
 */
class ProbkaRegolitu: public ObiektGeom {
    public:
      ProbkaRegolitu();
      ProbkaRegolitu(const char *sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, unsigned int KolorID, Wektor3D wczytana_skala, Wektor3D wczytane_polozenie):
       ObiektGeom(sNazwaPliku_BrylaWzorcowa, sNazwaObiektu, KolorID, wczytana_skala, wczytane_polozenie) {}
      TypKolizji CzyKolizja(const std::shared_ptr<Lazik> l) override;
      std::string JakiObiekt () override
        {
          return "ProbkaRegolitu";
        }
};


#endif