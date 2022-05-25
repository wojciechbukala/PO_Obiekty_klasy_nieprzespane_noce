#ifndef OBRYSXY_HH
#define OBRYSXY_HH

#include "Wektor2D.hh"

/*!
 *  \brief Klasa ObrysXY
 *
 *  Modeluje pojęcie lazika jako 
 *  prostokąta o współrzędnych w 
 *  postaci osi OX i OY, jest to 
 *  potrzebne przy zderzeniach.
 */
class ObrysXY {
  protected: 
    /*!
     *  \brief Wektor przechowujący bok prsotokąta o kierunku zgodnym z płaszczyzną X.
     */
    Wektor2D bokX;
    /*!
     *  \brief Wektor przechowujący bok prsotokąta o kierunku zgodnym z płaszczyzną Y.
     */
    Wektor2D bokY;

  
  public:
    /*!
     * \brief konstruktor bezparametryczny
     */
    ObrysXY() {};
    /*!
     *  \brief Konstruktor parametryczny klasy ObrysXY
     * \param [in] X - bok współrzędna x.
     * \param [in] Y - bok współrzędna y.
     */
    ObrysXY (Wektor2D X, Wektor2D Y) {bokX= X; bokY=Y;}
    /*!
     *  \brief Metoda umożliwiająca aktualizacje wartosci atrybutu bokX.
     */
    void WpiszBokX (Wektor2D wektor) {bokX = wektor;}
    /*!
     *  \brief Metoda umożliwiająca aktualizacje wartosci atrybutu bokY.
     */
    void WpiszBokY (Wektor2D wektor) {bokY = wektor;}
    /*!
     *  \brief Metoda umożliwiająca aktualizacje wartosci atrybutu bokY.
     *  \param [in] DrugiLazik - Lazik dla którego sprawdzamy czy nie nachodzi na obecny.
     *  \return 1 -  nie nakładają się, 0 - nakładają się.
     */
    bool NakladajaSie (ObrysXY DrugiLazik);
};


#endif