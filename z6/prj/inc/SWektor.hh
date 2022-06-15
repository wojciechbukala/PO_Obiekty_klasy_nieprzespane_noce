#ifndef SWektor_HH
#define SWektor_HH

#include <iostream>
#include <cmath>

/*!
 * \file
 *
 *  Ostatnia modyfikacja: 2022.06.15
 */

/*!
 * \brief  Szablon klasy modelującej pojęcie wektora.
 * Klasa ta jest szablonem i może stworzyć wektory dowolnie dużej 
 * wielkości i zawierający elementy różych typów
 * \param [in] typ - typ zmennych składowych wektora (np. double, int, LZespolona).
 * \param [in] wymiar - rozmiar wektora, liczba całkowita int.
 */
template <typename typ, int wymiar>
class SWektor {
  /*!
   * \brief  SWektor jako tablica jednowymiarowa
   */
  typ tab[wymiar];
  /*!
   * \brief zmienna statyczna do zliczania wszytkich stworzonych wektorów 
   */
  static int ilosc_wektorow;
  /*!
   * \brief zmienna statyczna do zliczania wszystkich aktywnych wektorów
   */
  static int ilosc_aktywnych_wektorow;

  public:
  /*!
   * \brief Przeciążenie indeksu SWektora
   * \param [in] indeks - indeks elementu wektora
   * \return typ - zwraca element wektora
   */
    typ &operator[] (int indeks) {return tab[indeks];} 
  /*!
   * \brief Przeciążenie indeksu SWektora
   * \param [in] indeks - indeks elementu wektora
   * \return typ - zwraca element wektora
   */
    typ operator[] (int indeks) const {return tab[indeks];}

    // dokumentacja do poniższych metod w dalszej części pliku //
    SWektor<typ,wymiar> operator + (SWektor<typ,wymiar> SWektor2); // Przeciążenie dodawania dla SWektorów
    SWektor<typ,wymiar>& operator - (SWektor<typ, wymiar> SWektor2); // Przęciążenie odejmowania dla SWektorów
    typ operator * (SWektor SWektor2); // Przeciążenie iloczynu sklarnego dla SWektora
    SWektor<typ,wymiar> operator * (double skalar);  // Przeciążenie mnożenia SWektora przez skalar
    SWektor<typ,wymiar> operator / (SWektor<typ,wymiar> SWektor2); // Przeciążenie odejmowania dla SWektorów
    bool operator == (SWektor<typ,wymiar> SWektor2); // Przeciążenie operatora porównania
    //SWektor<typ,wymiar>& operator = (SWektor<typ,wymiar>& SWektor2); // Przeciążenie operatora przypisania dla SWektorów
    typ dlugosc(); // metoda wyliczająca długość SWektora
    SWektor(); // konstruktor bezprametryczny
    SWektor(typ jeden, typ dwa, typ trzy); // konstruktor dla wektora 3 wyrazowego
    SWektor(typ jeden, typ dwa); // konstruktor dla wektora 2 wyrazowego
    ~SWektor(); // destruktor
    SWektor operator & (SWektor const Wektor2); // metoda do mnożenie poszczególnych elementów macierzy
    static void wyswietl_ile_wek(std::ostream& StrmWy) {StrmWy << ilosc_wektorow << std::endl ;}; //metoda statyczna do wyświetlania ilości elementow
    static void wyswietl_ile_akt_wek(std::ostream& StrmWy) {StrmWy << ilosc_aktywnych_wektorow << std::endl;}; //metoda statyczna do wyświetlania ilości elementow
    /*
    SWektor<typ,wymiar>:SWektor() 
    {
        for(int i=0; i<wymiar; ++i) tab[i]=0; 
        ++ilosc_wektorow; 
        ++ilosc_aktywnych_wektorow;
    } */


};

/*
template <typename typ, int wymiar>
int SWektor<typ,wymiar>::ilosc_wektorow = 0;  // przypisujemy wartosc zero do zmiennej statycznej
int SWektor<typ,wymiar>::ilosc_aktywnych_wektorow =0; */

/*!
 * \brief Konstruktor bezparametryczny
 * wykonuje inkrementację ilosc_wektorow
 * i ilosc_aktywnych_wektorow
 */
template<typename typ, int wymiar>
SWektor<typ,wymiar>::SWektor() 
{
    for(int i=0; i<wymiar; ++i) tab[i]=0; 
    ++ilosc_wektorow; 
    ++ilosc_aktywnych_wektorow;
}


/*
template<typename typ, int wymiar>
SWektor<typ,wymiar>::SWektor<typ,wymiar>:SWektor(typ jeden, typ dwa, typ trzy) // konstruktor dla wektora 3 wyrazowego
{
    tab[0] = jeden; 
    tab[1] = dwa; 
    tab[2] = trzy; 
    ++ilosc_wektorow; 
    ++ilosc_aktywnych_wektorow;
} */

/*!
 * \brief Konstruktor parametryczny dla wektora 3D
 * wykonuje inkrementację ilosc_wektorw
 * i ilosc_aktywnych_wektorow
 * \param [in] jeden - pierwszy element wektora
 * \param [in] dwa - drugi element wektora
 * \param [in] trzy - trzeci element wektora
 */
template<typename typ, int wymiar>
SWektor<typ,wymiar>::SWektor(typ jeden, typ dwa, typ trzy) // konstruktor dla wektora 3 wyrazowego
{
    tab[0] = jeden; 
    tab[1] = dwa; 
    tab[2] = trzy; 
    ++ilosc_wektorow; 
    ++ilosc_aktywnych_wektorow;
}

/*!
 * \brief Konstruktor parametryczny dla wektora 2D
 * wykonuje inkrementację ilosc_wektorw
 * i ilosc_aktywnych_wektorow
 * \param [in] jeden - pierwszy element wektora
 * \param [in] dwa - drugi element wektora
 */
template<typename typ, int wymiar>
SWektor<typ,wymiar>::SWektor(typ jeden, typ dwa) // konstruktor dla wektora 2 wyrazowego
{
    tab[0] = jeden; 
    tab[1] = dwa; 
    ++ilosc_wektorow; 
    ++ilosc_aktywnych_wektorow;
}

/*!
 * \brief destruktor wektora
 * wykonuje dekrementację pola
 * ilosc_aktywnych_wektorow
 */
template<typename typ, int wymiar>
SWektor<typ,wymiar>::~SWektor()
{
    --ilosc_aktywnych_wektorow;
}

/*! 
 * \brief Przeciążenie operatora & mnożenie dla elementów SWektorów
 * 
 *  \param [in] const SWektor2 - drugi z elementów mnożenia
 *
 * \return SWektor wynik - macież gdzie elementy są wynikami mnożenia kolejnych elementów dwóch macierzy
 */
template <typename typ, int wymiar>
SWektor<typ,wymiar> SWektor<typ, wymiar>:: operator & (SWektor const Wektor2)
{
    SWektor wynik;
    for(int i=0; i<wymiar; ++i) wynik[i] = tab[i] * Wektor2[i];
    return wynik;
}

/*! 
 * \brief Przeciążenie operatora dodawania dla SWektorów
 *
 *  \param [in] SWektor SWektor2 - składnik sumowania
 * 
 *  \return SWektor T - wynik sumowania dwóch SWektorów
 */
 template <typename typ, int wymiar>
SWektor<typ, wymiar> SWektor<typ, wymiar>::operator + (SWektor<typ,wymiar> SWektor2)
{
    SWektor<typ,wymiar> T;
    for(int i=0; i<wymiar; ++i) T[i]= tab[i] + SWektor2[i];
    return T;
}

/*!
 * \brief Przeciążenie operatora odejmowania dla SWektorów
 *
 *  \param [in] SWektor2 - odjemna dla operacji różnicy dwóch SWektorów
 *
 *  \return &wynik - referencja wyniku różnicy dwóch SWektorów
 */
template <typename typ, int wymiar>
SWektor<typ, wymiar>& SWektor<typ, wymiar>::operator - (SWektor<typ,wymiar> SWektor2)
{
    SWektor<typ,wymiar> T;
    SWektor<typ,wymiar> &wynik = T;
    for(int i=0; i<wymiar; ++i) T[i] = tab[i] - SWektor2[i];
    return wynik;
}

/*! 
 * \brief Przeciążenie operatora mnożenia dla iloczynu sklarnego
 *
 *  \param [in] SWektor2 - czynnik mnożenia
 * 
 *  \return SWektor T - wynik iloczynu skalarnego dla dwóch SWektorów
 */

template <typename typ, int wymiar>
typ SWektor<typ,wymiar>::operator * (SWektor<typ,wymiar> SWektor2)
{
    typ T;
    for(int i=0; i<wymiar; ++i) T += tab[i]*SWektor2[i];
    return T;
} 

/*! 
 * \brief Przeciążenie operatora mnożenia przez skalar
 *
 *  \param [in] skalar - liczba zmiennoprzecinkowa do mnożenia elementów
 *
 *  \return SWektor T - wymnożony SWektor przez liczbe zmiennoprzecinkową (skalar)
 */
template <typename typ, int wymiar>
SWektor<typ,wymiar> SWektor<typ,wymiar>::operator * (double skalar)
{
    SWektor<typ,wymiar> T;
    for(int i=0; i<wymiar; ++i) T[i] = tab[i] * skalar;
    return T;
} 

/*! 
 * \brief Przeciążenie operatora dzilenie dla SWektorów
 * posiada zabezpieczenie przed dzieleniem przez zero
 *
 *  \param [in] SWektor2 - SWektor którego elemnty są dzielną w operacji
 * 
 * \return SWektor T - wynik dzielenia
 */
template <typename typ, int wymiar>
SWektor<typ,wymiar> SWektor<typ,wymiar>::operator / (SWektor<typ,wymiar> SWektor2)
{
    SWektor<typ,wymiar> T;
    for(int i=0; i<wymiar; ++i) 
        {
            if(SWektor2[i] == 0)
            {
                std::cerr << "Blad, nie mozna dzielic przez zero";
                break;
            }
            else {T[i] += tab[i]/SWektor2[i];}
        }
    return T;
}

/* 
 * \brief Przeciążenie operatora przypisania dla SWektora
 *
 *  \param [in] &SWektor2 - SWektor, którego elementy przypisujemy do tab<wymiar]
 *  \return *this - referencja SWektora, atrybut tab<wymiar], czyli miejsce przechowujące elementy SWektora
 */  /*
template <typename typ, int wymiar>
SWektor<typ,wymiar>& SWektor<typ,wymiar>::operator = (SWektor<typ,wymiar> & SWektor2)
{
    for(int i=0; i<wymiar; ++i) this->tab[i] = SWektor2.tab[i];
    return *this;
} */

template <typename typ, int wymiar>
bool SWektor<typ,wymiar>::operator == (SWektor<typ,wymiar> SWektor2) // Przeciążenie operatora porównania
{
    for(int i=0; i<wymiar; ++i) if(this->tab[i] != SWektor2.tab[i]) return false;
    return true;
} 
/*! 
 * \brief Medota obliczająca długość SWektora
 *
 *\return  double mod - liczba zmiennoprzecinkowa, będąca długością SWektora
 */
template <typename typ, int wymiar>
typ SWektor<typ,wymiar>::dlugosc()
{
    typ mod=0;
    for(int i=0; i<wymiar; ++i) mod+= pow(tab[i],2);
    mod = sqrt(mod);
    return mod;
}

/*! 
 * \brief Przeciążenie wczytujące SWektor ze strumienia std::istream
 * Akceptowany format prametrów SWektora to liczby zmiennoprzicnkowe
 *  \param [in] Wek - referencja SWektora do którego wpisujemy parametry
 *  \param [in] Strm - referencja sturmienia wejściowego
 * 
 * \return Wczytuje strumieniem std::istream SWektor
 */

template <typename typ, int wymiar>
std::istream& operator >> (std::istream &Strm, SWektor<typ,wymiar> &Wek)
{
    for(int i=0; i<wymiar; ++i)
    {
        Strm >>Wek[i];
        if(Strm.fail()) return Strm;
    }
    return Strm;
}

/*! 
 * \brief Przeciążenie wypisujące SWektor na strumień std::ostream
 *
 *  \param [in] Wek - SWektor którego parametry wypisujemy 
 *  \param [in] Strm - referencja sturmienia wyjściowego
 *
 * \return  Wypisuje na strumień std::ostream
 */
template <typename typ, int wymiar>
std::ostream& operator << (std::ostream &Strm, const SWektor<typ,wymiar> &Wek)
{
    
    for(int i=0; i<wymiar; ++i) Strm<< " " << Wek[i];
    
    return Strm;
}


#endif