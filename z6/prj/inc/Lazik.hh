#ifndef LAZIK_HH
#define LAZIK_HH

#include <string>
#include <chrono>
#include <thread>
#include "ObiektGeom.hh"
#include "lacze_do_gnuplota.hh"


/*!
 *  \brief Klasa Lazik
 *
 *  Dziedziczy publicznie do klasie ObiektGeom.
 *  Modeluje pojęcie łazika będącego jednym z obiektów
 *  geometrycznych. Posiada metody odpowiedzialne za
 *  rotacje oraz jazde łazika.
 */
class Lazik : public ObiektGeom {
protected:
   /*!
    * \brief Kąt o który aktualnie jest odwrócony łazik.
    */
    double KatOrientacji;
   /*!
    * \brief Szybkość z jaką będzie poruszał się łazik.
    */
    double Szybkosc;
   /*!
    * \brief Odległość jaką ma przejechać łazik.
    */
    double OdlegloscDoPrzejechania;
  public:
     /*!
    * \brief Konstruktor bezparametryczny klasy Lazik.
    */
    Lazik() ; 

   /*!
    * \brief Konstruktor parametryczny klasy Lazik.
    *
    * Przypisuje wrtości początkowe i inicjuje niektóre pola klasy
    * \param[in] wczytana_skala - skala przeliczania punktow wpisuwana do pola klasy skala odziedziczonej z ObiektGeom.
    * \param[in] wczytane_polozenie - polożenie początkowe łazika wpisywane po pola polożenie odziedziczonego z ObiektGeom.
    * \param[in] kat - początkowy KatOrientacji wpisywany do tego pola klasy Lazik
    * \param[in] szybkosc - wartosc wpisywana do pola klasy Lazik, jest prędkością z jaką poruszał się bedzie łazik podczas jazdy
    */
    Lazik(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID, Wektor3D wczytana_skala, Wektor3D wczytane_polozenie, double kat, double szybkosc) 
    : ObiektGeom(sNazwaPliku_BrylaWzorcowa, sNazwaObiektu, KolorID, wczytana_skala, wczytane_polozenie) {KatOrientacji=kat; Szybkosc = szybkosc;}
    /*!
    * \brief Metoda odpowiadająca za zmienianie wartosci szybkosci.
    *
    * \param[in] nowa_szybkosc - wartosci na jaką należy zmienić pole Szybkosc
    */       
    void WpiszSzybkosc(double nowa_szybkosc) {Szybkosc = nowa_szybkosc;}
    /*!
    * \brief Metoda odpowiadająca za jazdę po prostej łazika.
    *
    * \param[in] Lacze - lacze do gnuplota
    * \param[in] StrmWej - referencja strumienia wejściowego.
    * \param[in] StrmWyj - referencja strumienia wyjściowego.
    */
    void jazda(PzG::LaczeDoGNUPlota  Lacze, std::istream& StrmWej, std::ostream& StrmWyj);

    /*!
    * \brief Metoda odpowiadająca za obrot łazika zgodnie z aktualną macierzą rotacji.
    *
    * \param[in] Lacze - lacze do gnuplota
    * \param[in] StrmWej - referencja strumienia wejściowego.
    * \param[in] StrmWyj - referencja strumienia wyjściowego.
    */    
    void obrot(PzG::LaczeDoGNUPlota  Lacze,std::ostream& StrmWyj, std::istream& StrmWej);

    /*!
    * \brief Metoda odpowiadająca za zmiane wartości elementów macierzy rotacji.
    *
    * \param[in] kat - kąt jaki ma zostać wpisany do macierzy rotacji
    */
    void Rotacja(double kat);

    /*!
      * \brief Zwraca aktualne Kat Orientacji
      *
      * \return Aktualna wartosc pola KatOrientacji
      */
    double DajKat() {return KatOrientacji;}

    /*!
      * \brief Zwraca aktualne polozenie
      *
      * \return Aktualna wartosc wektora polozenie
      */
    Wektor3D DajPolozenie() {return polozenie;};
    /*!
      * \brief Przeciążenie metody wirtualnej z klasy ObiektGeom do sprawdzania typu obiektu
      * \return Zwraca nazwę obiektu klasy Lazik
      */
    std::string JakiObiekt () override
    {
      return "Lazik";
    }
    //std::string CzyKolizja(ObiektGeom& DrugiLazik) override;
};


#endif