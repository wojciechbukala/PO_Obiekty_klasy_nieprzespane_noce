#ifndef PROBKAREGOLITU_HH
#define PROBKAREGOLITU_HH

#include "ObiektGeom.hh"
#include "Lazik.hh"

/*!
 * \file
 *
 *  Ostatnia modyfikacja: 2022.06.15
 */

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
    /**
     * @brief Konstruktor bezprametryczny klasy ProbkaRegolitu
     * 
     */
      ProbkaRegolitu();
      /**
       * @brief Konstruktor parametryczny, kopiujący klasy ProbkaRegolitu
       * 
       * @param sNazwaPliku_BrylaWzorcowa - Nazwa bryły wzorcowej
       * @param sNazwaObiektu - Nazwa Obiektu (próbki)
       * @param KolorID - Kolor Obiektu (próbki)
       * @param wczytana_skala - Skala rysowania
       * @param wczytane_polozenie - Położenie Obiektu (próbki)
       */
      ProbkaRegolitu(const char *sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, unsigned int KolorID, Wektor3D wczytana_skala, Wektor3D wczytane_polozenie):
       ObiektGeom(sNazwaPliku_BrylaWzorcowa, sNazwaObiektu, KolorID, wczytana_skala, wczytane_polozenie) {}
       /**
        * @brief przeciążenie metody wirtualnej sprawdzającej kolizję
        * 
        * @param l - inteligentny wskaźnika na Łazik
        * @return TypKolizji - jaki typ kolizji?
        */
      TypKolizji CzyKolizja(const std::shared_ptr<Lazik> l) override;
      /**
       * @brief przeciążenie metody wirtulanej zwracającej typ obiektu
       * 
       * @return std::string - "Probkaregolitu"
       */
      std::string JakiObiekt () override
        {
          return "ProbkaRegolitu";
        }
};


#endif