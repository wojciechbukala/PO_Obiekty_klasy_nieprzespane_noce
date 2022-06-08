#ifndef OBIEKTGEOM_HH
#define OBIEKTGEOM_HH

#include <string>
#include <cmath>
#include <chrono>
#include <thread>
#include <list>
#include <memory>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include "Wektor3D.hh"
#include "Macierz3D.hh"
#include "ObrysXY.hh"
#include "TypKolizji.hh"

#define NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA    "pliki_do_rysowania"

class Lazik; // deklarujemy tutaj aby można było użyć wskaźnika

/*!
 *  \brief Klasa ObiektGeom
 *
 *  Modeluje pojęcie obiektu geometrycznego,
 * może być to przykładowo łazik. Działa na 
 * danych takich jak wierzchołki, położenie, 
 * skala i macierz rotacji.
 */
class ObiektGeom {
  protected: 
    std::string   _NazwaPliku_BrylaWzorcowa;
    std::string   _NazwaPliku_BrylaRysowana;
    std::string   _NazwaObiektu;
    int           _KolorID;
    /*!
 *  \brief Wektor przechowujący skale potrzebną w obliczeniach.
 */
    Wektor3D skala;
    /*!
 *  \brief Wektor przechowujący położenie danego przedmiotu.
 */
    Wektor3D polozenie;
    /*!
     *  \brief Macierz potrzeba do przeliczania obrotu.
    *    
    *  Działa na funkcjach trygonometrycznych i potrzebuje
    *  kąta orientacji do prawidołowego działania.
    */
    Macierz3D MacierzRotacji;
    /*!
     *  \brief Pole Obrys reprezentujące obiekt jako kontur 2D.
    */
  
  public:
  std::string DajNazweObiektu () {return _NazwaObiektu;}
  void WpiszPolozenie(Wektor3D nowe) {polozenie = nowe;}
     /*!
    * \brief Konstruktor parametryczny klasy ObiektGeom.
    *
    * Przypisuje wrtości początkowe i inicjuje niektóre pola klasy
    * \param[in] wczytana_skala - skala przeliczania punktow wpisuwana do pola klasy skala odziedziczonej z ObiektGeom.
    * \param[in] wczytane_polozenie - polożenie początkowe łazika wpisywane po pola polożenie odziedziczonego z ObiektGeom.
    */
    ObiektGeom(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID, Wektor3D wczytana_skala, Wektor3D wczytane_polozenie);
    /*!
      * \brief Zwraca kolor obiektu
      *
      * \return int _KolorID - kolor obiektu
      */
    int WezKolorID() const { return _KolorID; }
    /*!
      * \brief Zwraca nazwę obiektu geomtrycznego
      *
      * \return std::string _NazwaObiektu - nazwa obiektu
      */
    const std::string & WezNazweObiektu() const { return _NazwaObiektu; }
    /*!
      * \brief Zwraca nazwe pliku rysowanej bryły
      *
      * \return std::string _NazwaPliku_BrylaRysowowa
      */
    const std::string & WezNazwePliku_BrylaRysowana() const { return _NazwaPliku_BrylaRysowana; }
    /*!
      * \brief Przeciążnie funkcji przeliczania i zapisywania współrzendnych wierzchołków bez parametrów
      *
      *  Ważna metoda dla działania programu. Pozwala przliczyć
      *  gdzie powinien znajdować się obiekt.
      *
      * \return bool 1 - pomyślnie wykonano przliczanie, 0 - coś się nie powiodło 
      */
    bool Przelicz_i_Zapisz_Wierzcholki();
        /*!
      * \brief Przeciążnie funkcji przeliczania i zapisywania współrzendnych wierzchołków z parametrami
      *
      *  Ważna metoda dla działania programu. Pozwala przliczyć
      *  gdzie powinien znajdować się obiekt.
      * 
      *   \param[in] StrmWej - referencja strumienia wejściowego.
      *   \param[in] StrmWyj - referencja strumienia wyjściowego.
      *
      * \return bool 1 - pomyślnie wykonano przliczanie, 0 - coś się nie powiodło 
      */
    bool Przelicz_i_Zapisz_Wierzcholki(std::ostream &StrmWy, std::istream &StrmWe);
     /*!
      * \brief Motoda zmienia położenie obiektu
      * 
      *   \param [in] nowy - Wektor3D z nowym położeniem
      *
      * \return bool 1 - pomyślnie wykonano przliczanie, 0 - coś się nie powiodło 
      */
    void zmien_polozenie(Wektor3D nowy) {polozenie = nowy;};
     /*!
      * \brief Abstrakcyjna metoda wirtualna do sprawdzania typu obiektu klasy pochodnej
      * \return Zwraca nazwę obiektu klasy pochodnej
      */
    virtual std::string JakiObiekt () {return "JakisObiekt";} 
     /*!
      * \brief Destruktor wirtualny klasy ObiektGeom
      */
    virtual ~ObiektGeom() {};
    /*!
     *  \brief Pole Obrys reprezentujące obiekt jako kontur 2D.
    */
    ObrysXY Obrys;
    virtual TypKolizji CzyKolizja(std::shared_ptr<Lazik> l) = 0;
        void Obrysy(){
    std::cout << Obrys.bokX << std::endl;
    std::cout << Obrys.bokY << std::endl;
    } 
};


#endif
