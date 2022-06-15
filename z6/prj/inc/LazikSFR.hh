#ifndef LAZIK_SFR
#define LAZIK_SFR
#include "Lazik.hh"
#include "ProbkaRegolitu.hh"

/*!
 * \file
 *
 *  Ostatnia modyfikacja: 2022.06.15
 */

class LazikSFR : public Lazik
{
    /**
     * @brief lista probek LazikSFR
     * 
     */
    std::list<std::shared_ptr<ProbkaRegolitu>> ListaProbek;
    public:
    /**
     * @brief Konstruktor bezparametryczny
     * 
     */
    LazikSFR() ; 
    /**
     * @brief Konstruktor parametryczny, kopiujący klasy LazikSFR
     * 
     * @param sNazwaPliku_BrylaWzorcowa - nazwa pliku bryły wzorcowej
     * @param sNazwaObiektu - nazwa obiektu
     * @param KolorID - kolor obiektu (LazikaSFR)
     * @param wczytana_skala - skala do rysowania obiektu (LazikaSFR)
     * @param wczytane_polozenie - położenie obiektu (LazikaSFR)
     * @param kat - kąt orientacji dla obiektu klasy LazikSFR
     * @param szybkosc - szybkość poruszania się obiketu klasy LazikSFR
     */
    LazikSFR(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID, Wektor3D wczytana_skala, Wektor3D wczytane_polozenie, double kat, double szybkosc) 
        : Lazik(sNazwaPliku_BrylaWzorcowa, sNazwaObiektu, KolorID, wczytana_skala, wczytane_polozenie, kat, szybkosc) {KatOrientacji = kat; Szybkosc = szybkosc;}
    /**
     * @brief Destruktor wirtualny klasy LazikSFR
     * 
     */
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
    /**
     * @brief metoda dodająca do listy zebrane próbki
     * 
     * @param ProbRego - próbka do dodania
     */
    void DodajDoListyProbek (std::shared_ptr<ProbkaRegolitu> ProbRego);
    /**
     * @brief metoda wyświetlająca listę próbek zebranych przez SFR
     * 
     * @param StrmWy - strumień wyjściowy
     */
    void WyswietlListeProbek(std::ostream &StrmWy);
    /**
     * @brief przeciążenie metody wirtualnej do wyświetlania stanu łazika
     * 
     * @param StrmWy - strumień wyjściowy
     */
    void WyswietlStan(std::ostream &StrmWy) override;
};

#endif
