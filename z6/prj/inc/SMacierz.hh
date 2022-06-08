#ifndef SMACIERZ_HH
#define SMACIERZ_HH

#include "SWektor.hh"
#include <iostream>

/*!
 *  \brief Szblon klasy Macierz.
 *
 * Szablon klasy modelującej pojęcie macierzy.
 * typ - typ zmennych składowych macierzy (np. double, int, LZespolona).
 * wymiar - rozmiar macierzy kwadratowej, liczba całkowita int.
 * 
 * \param [in] typ - typ elementow macierzy (np int, double, Wektor).
 * \param [in] wymiar - wymiar macierzy kwadratowej.
 */
template<typename typ, int wymiar>
class SMacierz {
  /*!
   * \brief macierz to ROZMIAR-razy wektor.
   */
  SWektor<typ,wymiar> Tab[wymiar];
  /*!
   * \brief zerowanie macierzy
   * 
   * \param [in] parzystosc - referencja zmiennej która mnoży wyznacznik razy -1 lub 1
   * \return 1 - jeśli się wykona zerowanie
   */ 
  bool zeruj (int& parzystosc);
  /*!
   * \brief mnożenie elementów na diagonali
   * 
   * \return wymnożona diagonala (typ)
   */   
  typ mnozenie_diagonali () const; 
  /*!
   * \brief Inicjowanie kopi macierzy do wykoanywania obliczeń wyznacznika
   */
  void kopiuj();
  /*!
   * \brief macierz do kopiowania i wykonywania obliczeń 
   */
  SWektor<typ,wymiar> kopia[wymiar];
  

  public:
 /*!
   * \brief Mnożenie macierzy przez wektor
   * \param [in] SWektor - wektor przez który mnożymy macierz
   * \return SWektor - wynik mnożenia macierzy przez wektor
   */ 
  SWektor<typ,wymiar> operator * (const SWektor<typ,wymiar> Wektor2) const ;
 /*!
   * \brief Przeciążenie operatorea indeksowania macierza
   * \param [in] indeks - indeks elementu, który chcemy
   * \return SWektor - zwrócony wektor
   */
  SWektor<typ,wymiar>& operator [](int indeks)  {return Tab[indeks];}
/*!
   * \brief Przeciążenie transpononowania
   * \return SMacierz - transponowana macierz
   */
  SMacierz<typ,wymiar> operator ! ();
   /*!
   * \brief przeciązenie operatora funkcyjnego dla klasy macierz
   * \param [in] a - indeks wiersza
   * \param [in] b - indeks kolumny
   * \return typ - zwrócony element macierzy
   */
  typ operator () (int a, int b) {return Tab[a][b];} 
     /*!
   * \brief Przeciążenie operatora przypisania dla macierzy
   * \param [in] Macierz2 - macierz przypisywana do innej
   * \return przypisana macierz
   */
  SMacierz<typ,wymiar>& operator = (SMacierz<typ,wymiar>& Macierz2); 
  /*!
   * \brief Transponowanie orginalnej macierzy
   */
  void transponuj();
  /*!
   * \brief obliczanie wyznacznika metodą gaussa
   * \return typ - wyznacznik macierzy oblicznocy metodą gaussa
   */
  typ wyznacznik_gauss ();
}; 


/*!
 * \brief Przeciążenie wczytywania macierzy
 * Przeciążenie wczytujące Macierz ze strumienia std::istream
 * Akceptowany format prametrów macierzy to liczby zmiennoprzicnkowe
 * Argumenty:
 *  \param [in] Mac - referencja macierzy do któregej wpisujemy parametry
 *  \param [in] Strm - referencja sturmienia wejściowego
 * Zwraca:
 *  \return  Wczytuje strumieniem std::istream 
 */
template<typename typ, int wymiar>
std::istream& operator >> (std::istream &Strm, SMacierz<typ,wymiar> &Mac)
{
    for(int i=0; i<wymiar; ++i)
    {
        Strm >>Mac[i];
        if(Strm.fail()) return Strm;
    }
    return Strm;
}

/*!
 * \brief Przeciążenie wypisywania Macierzy
 * Za pomocą przeciążenie operatora przesunięcia
 * bitowego zdefiniowne jest wypisywanie macierzy
 * na stryumień wyjściowy.
 * \param [in] Strm - referencja strumienia wyjściowego
 * \param SMacierz -  Macierz do wyświetlenia
 * \return Strm - strumień wyjściowy
 */
template<typename typ, int wymiar>
std::ostream& operator << (std::ostream &Strm, SMacierz<typ,wymiar> Mac)
{
    Strm << "  " << std::endl;
    for(int i=0; i<wymiar; ++i) Strm<< " " << Mac[i] <<std::endl;
    return Strm;
}

template<typename typ, int wymiar>
SWektor<typ,wymiar> SMacierz<typ,wymiar>::operator * (const SWektor<typ,wymiar> Wektor2) const // Mnożenie macierza przez wektor 
{
    SWektor<typ,wymiar> Wynik;
    //for(int b=0; b<ROZMIAR; ++b) Wynik[b]=0;
    //SWektor<typ,wymiar> &w = Wynik;
    for(int i=0; i<wymiar; ++i)
    for(int j=0; j<wymiar; ++j)
    Wynik[i] += (Tab[i][j] * Wektor2[j]);
    return Wynik;
}

/* 
 * Medota przeciążająca operator przypisania dla macierzy
 * Argumenty:
 *  -Macierz& Macierz- referencja macierzy przypisywanej do innej
 * Zwraca:
 *  Macierz& *this - referencja macierzy po przekształceniu
 */
template<typename typ, int wymiar>
SMacierz<typ,wymiar>& SMacierz<typ,wymiar>::operator = (SMacierz<typ,wymiar> & Macierz2)
{
    for(int j=0; j<wymiar; ++j)
    for(int i=0; i<wymiar; ++i) this->Tab[j][i] = Macierz2.Tab[j][i];
    return *this;
}

/* 
 * Medota transponuje orginalną macierz
 * Argumenty:
 *  -brak
 * Zwraca:
 *  -brak
 */
template<typename typ, int wymiar>
void SMacierz<typ,wymiar>::transponuj () // transponowanie macierzy
{
    SMacierz<typ,wymiar> Transpozycja;
    for(int i=0; i<wymiar; ++i)
    for(int j=0; j<wymiar; ++j)
    Transpozycja[i][j] = Tab[j][i];
    
    for(int i=0; i<wymiar; ++i)
    for(int j=0; j<wymiar; ++j)
    Tab[i][j] = Transpozycja[i][j];
}

template<typename typ, int wymiar>
void SMacierz<typ,wymiar>::kopiuj()
{
    for(int i=0; i<wymiar; ++i)
    for(int j=0; j<wymiar; ++j)
    kopia[i][j] = Tab[i][j]; 
}

/* 
 * Metoda dopasowuje wyznacznik tak, aby na digonali były luczby niezerowe
 * a pod nią same zera, jeśli jest ot wykonalne.
 * Argumenty:
 * -bool &parzystosc - referencja parametru wsazujacego na parzystosc zmaina kolumn
 *  jeśli jeden to mnożymy przez 1, jeśli 0 to mnożymy przez -1
 * Zwraca:
 *  bool - True (1), jeśli wyznacznik != 0
 *         False (0), jeśli wyznacznik == 0 (przekształcenie macierzy jest niewykonalane)
 */
template<typename typ, int wymiar>
bool SMacierz<typ,wymiar>::zeruj(int &parzystosc)
{
    typ wspolczynnik;
    wspolczynnik = 0;
    

        int k = 1;
        while(k!= wymiar)
        {   if(kopia[k-1][k-1] == 0)
            {
                for(int i=k; i<wymiar; ++i)
                {
                    if(kopia[i][k-1]!=0) { // zamienianie wiersza
                        SWektor<typ,wymiar> pom = kopia[i];
                        kopia[i] = kopia[k-1];
                        kopia[k-1] = pom;
                        parzystosc*=(-1);
                        }
                    else if(i==wymiar-1) return 0;
                }
            }  
            for(int a=k; a<wymiar; ++a)
            {
                wspolczynnik = kopia[a][k-1] / kopia[k-1][k-1];
                for(int i=0; i<wymiar; ++i)
                kopia[a][i] = kopia[a][i] - (kopia[k-1][i] * wspolczynnik);
            }
            ++k;
        }
    return 1;
}


/* 
 * Metoda wylicza iloczyn elementów na diagonali
 * Argumenty:
 * -brak
 * Zwraca:
 *  double wynik- liczba zmiennoprzecinkowa będąca iloczynem wyrazów na diagonali
 */
template<typename typ, int wymiar>
typ SMacierz<typ,wymiar>::mnozenie_diagonali () const
{
    typ wynik;
    wynik = 1;
    for(int i=0; i<wymiar; ++i) wynik = wynik*kopia[i][i];
    return wynik;
} 
/* 
 * Metoda wyznacza wyznacznik gaussa wraz z wszystkimi warunkami
 * Argumenty:
 * -brak
 * Zwraca:
 *  double wyznacznik - liczba zmienno przecinkowa będąca wyznacznikiem
 */
template<typename typ, int wymiar>
typ SMacierz<typ,wymiar>::wyznacznik_gauss ()
{
    typ wyznacznik;
    int parzystosc = 1;
    kopiuj();
    if(zeruj(parzystosc))
    wyznacznik=mnozenie_diagonali() * parzystosc;
    else wyznacznik = 0;
    return wyznacznik;
}

template<typename typ, int wymiar>
SMacierz<typ,wymiar> SMacierz<typ,wymiar>::operator ! ()
{
    SMacierz<typ,wymiar> Transpozycja;
    for(int i=0; i<wymiar; ++i)
    for(int j=0; j<wymiar; ++j)
    Transpozycja[i][j] = Tab[j][i];
    return Transpozycja;
}



#endif
