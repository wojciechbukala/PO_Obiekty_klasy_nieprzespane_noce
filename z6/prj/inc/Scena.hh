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

/*!
 *  \brief Klasa Scena
 *
 *  Modeluje pojęcie sceny, czyli miejsca
 *  gdzie inicjalizowane są obiekty geometryczne
 *  oraz występują interakcje związane z nimi.
 */
class Scena 
{
    /*!
     *  \brief Inteligentny wskaźnika tworzący obiekt klasy Lazik
     */
    std::shared_ptr<Lazik> AktualnyLazik;
    /*!
     *  \brief Lista wszystkich obiektów klasy łazik
     */
    std::list<std::shared_ptr<ObiektGeom>> ObiektySceny;
    /*!
     *  \brief Lacze do gnuplota
     */
    PzG::LaczeDoGNUPlota Lacze;
    /*!
     *  \brief Metoda inicjalizująca łącze z gnuplotem
     */
    void Inicjalizuj_Lacze();
  public:
    /*!
     *  \brief Konstruktor bezparametryczny
     */
    Scena();
    /*!
     *  \brief Metoda dodaje elementy do listy rysowania
     */
    void DodajDoListyRysowania();
    /*!
     *  \brief Metoda pozwalająca wywoływać jazde łazika
     *
     *  Wykorzystuje metodę jazda z klasy lazik dla
     *  atulanego lazika aby wywołać jego ruch
     * \param[in] StrmWej - referencja strumienia wejściowego.
     * \param[in] StrmWyj - referencja strumienia wyjściowego.
     */
    void jedziemy(std::istream& StrmWe, std::ostream& StrmWy) 
        {AktualnyLazik->jazda(Lacze, StrmWe, StrmWy);}
    /*!
     *  \brief Metoda pozwalająca wywoływać obrót łazika o zadanyc kąt
     *
     *  Wykorzystuje metodę obrot z klasy lazik dla
     *  atulanego lazika aby wywołać jego obrot o zadany kąt.
     * \param[in] StrmWej - referencja strumienia wejściowego.
     * \param[in] StrmWyj - referencja strumienia wyjściowego.
     */
    void krecimy(std::istream& StrmWe, std::ostream& StrmWy)
        {AktualnyLazik->obrot(Lacze, StrmWy, StrmWe);}
    /*!
     *  \brief Metoda pozwalająca wywoływać obrót łazika o zadanyc kąt
     *
     *  Wykorzystuje metodę obrot z klasy lazik dla
     *  atulanego lazika aby wywołać jego obrot o zadany kąt.
     * \param[in] lazik - numer lazika, który chcemy wybrać
     */    
    void WyborLazika(int lazik);
        /*!
     *  \brief Metoda pozwalająca zamienić drona, ktorym chemy sterować
     *
     *  Wykorzystuje metodę WyborDrona, dodając do
     *  niej interfejs wyboru obiektu
     * \param[in] StrmWe - referencja strumienia wejściowego.
     * \param[in] StrmWy - referencja strumienia wyjściowego.
     */
    void ZmienLazika(std::istream &StrmWe, std::ostream &StrmWy);
    /*!
     *  \brief Metoda wyświetla paramtry aktywnego łazika
     *
     * \param[in] StrmWy - referencja strumienia wyjściowego.
     */
    void WyswietlAktywny(std::ostream &StrmWy);
    void zmien_szybkosc(std::istream &StrmWe, std::ostream &StrmWy);
};

#endif