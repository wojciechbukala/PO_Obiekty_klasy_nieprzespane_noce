#ifndef SCENA_HH
#define SCENA_HH
#include "Lazik.hh"
#include "LazikSFR.hh"
#include "Kolory.hh"
#include "lacze_do_gnuplota.hh"
#include "PowierzchniaMarsa.hh"
#include "ProbkaRegolitu.hh"

/*!
 * \file
 *
 *  Ostatnia modyfikacja: 2022.06.15
 */

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
     * przechowuje aktulanie poruszający się łazik
     */
    std::shared_ptr<Lazik> AktualnyLazik;
    /**
     * @brief Inteligentny wskaźnik tworzący obiket klasy Probka Regolitu
     * przechowuje próbkę którą aktualnie potencjalnie można podjąć
     * 
     */
    std::shared_ptr<ProbkaRegolitu> AktualnaProbka;
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
    bool CzyMoznaZebrac;
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
        {jazda(Lacze, StrmWe, StrmWy);}
    /*!
     *  \brief Metoda pozwalająca wywoływać obrót łazika o zadanyc kąt
     *
     *  Wykorzystuje metodę obrot z klasy lazik dla
     *  atulanego lazika aby wywołać jego obrot o zadany kąt.
     * \param[in] StrmWej - referencja strumienia wejściowego.
     * \param[in] StrmWyj - referencja strumienia wyjściowego.
     */
    void krecimy(std::istream& StrmWe, std::ostream& StrmWy)
        {obrot(Lacze, StrmWy, StrmWe);}
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
    /**
     * @brief Metoda do zmiany szybkości jazdy łazika
     * 
     * @param StrmWe - strumień wejściowy
     * @param StrmWy - strumień wyjściowy
     */
    void zmien_szybkosc(std::istream &StrmWe, std::ostream &StrmWy);
    /**
     * @brief Metoda wykonująca funkcjonalność i animację jazdy łazika
     * 
     * @param Lacze - łącze do gnuplota
     * @param StrmWej - strumień wejściowy
     * @param StrmWyj - strumień wyjściowy
     */
    void jazda(PzG::LaczeDoGNUPlota  Lacze, std::istream& StrmWej, std::ostream& StrmWyj);
    /**
     * @brief Metoda wykonująca funkcjonalność i animację obrotu łazika o zadany kąt
     * 
     * @param Lacze - łącze do gnuplota
     * @param StrmWyj - strumień wyjściowy
     * @param StrmWej - strumień wejściowy
     */
    void obrot(PzG::LaczeDoGNUPlota  Lacze, std::ostream& StrmWyj, std::istream& StrmWej);
    /**
     * @brief Metoda sprawdzająca kolizję aktulanego łazika
     * 
     * @return TypKolizji 
     */
    TypKolizji CzyAktywnyLazikKoliduje();
    /**
     * @brief metoda wyświetlająca próbki regolitu na scenie
     * 
     * @param StrmWy - strumień wyjściowy
     */
    void WyswietlProbki (std::ostream &StrmWy);
    /**
     * @brief metoda zbierania próbek przez SFR
     * 
     * @param Probka - próbka z którą koliduje Łazik
     */
    void ZbierzProbke (std::shared_ptr<ObiektGeom>  Probka);
    /**
     * @brief metoda wyświtlająca próbki lazika SFR w klasie scena
     * 
     * @param StrmWyj - strumień wyjściowy
     */
    void WyswietlProbkiSFR (std::ostream &StrmWyj);
    /**
     * @brief Metoda obsługująca podjęcie próbki
     *  jest używana w main dla obiektu scena i
     *  korzysta z metody ZbierzProbke
     * 
     * @param StrmWy - strumień wyjściowy
     */
    void PodejmijProbke(std::ostream& StrmWy);
    /**
     * @brief metoda do wyświetlania stanu aktualnego lazika.
     *  Korzysta z metody wirtualnej StanLazika()
     * 
     * @param StrmWy - strumień wyjściowy
     */
    void StanAktualnegoLazika (std::ostream& StrmWy);
};
#endif