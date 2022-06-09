#ifndef LAZIK_SFR
#define LAZIK_SFR
#include "Lazik.hh"
#include "ProbkaRegolitu.hh"


class LazikSFR : public Lazik
{
    /**
     * @brief lista probek LazikSFR
     * 
     */
    std::list<std::shared_ptr<ProbkaRegolitu>> ListaProbek;
    public:
    LazikSFR() ; 
    LazikSFR(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID, Wektor3D wczytana_skala, Wektor3D wczytane_polozenie, double kat, double szybkosc) 
        : Lazik(sNazwaPliku_BrylaWzorcowa, sNazwaObiektu, KolorID, wczytana_skala, wczytane_polozenie, kat, szybkosc) {KatOrientacji = kat; Szybkosc = szybkosc;}

    virtual ~LazikSFR() {}
    /**
     * @brief Przeciążenie metody wirtualnej sprawdzającej czy nastąpiła kolizja
     * 
     * @param l inteligentny wskaźnik na Lazik
     * @return TypKolizji - typ kolizji która wystąpiła
     */
    TypKolizji CzyKolizja(std::shared_ptr<Lazik> l) override;
    /**
     * @brief Przeciążenie metody wirtualnej zwracającej typ obiektu
     * 
     * @return std::string - typ obiektu czyli "LazikSFR"
     */
    std::string JakiObiekt() override 
    {return "LazikSFR";}
    void DodajDoListyProbek (std::shared_ptr<ProbkaRegolitu> ProbRego);
};

#endif
