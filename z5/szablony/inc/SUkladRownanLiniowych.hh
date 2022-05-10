#ifndef SUKLADROWNANLINIOWYCH_HH
#define SUKLADROWNANLINIOWYCH_HH

#include <iostream>
#include <SMacierz.hh>
#include <SWektor.hh>


/*
 * Szablon klasy modelującej pojęcie układu równań liniowych.
 * typ - typ zmennych składowych układu równań (np. double, int, LZespolona).
 * wymiar - rozmiar układu równań, liczba całkowita int.
 */
template<typename typ, int wymiar>
class SUkladRownanLiniowych {
 
  typ wyznacznik_glowny; 
  typ wyznaczniki[wymiar];
  SMacierz<typ,wymiar> MacWej; // Macierz współczynników
  SWektor<typ,wymiar> WyrWolne; // Wektor wyrazów wolnych
  SWektor<typ,wymiar> WektorBledu; // Opiekt klasy wektor do przechowywania wektora błedy

public:
  SWektor<typ,wymiar> wyniki; // tabela wyników 
  SMacierz<typ,wymiar> dajMacWej() const {return MacWej;}; // zwraca atrybut prywatny MacWej
  SWektor<typ,wymiar> dajWyrWolne() const {return WyrWolne;}; // zwraca atrybut prywatny WyrWolne 
  SMacierz<typ,wymiar>& ustawMacWej() {return MacWej;}; // zwraca referencje prywatnego atrybutu MacWej
  SWektor<typ,wymiar>& ustawWyrWolne() {return WyrWolne;}; // zwraca referencje prywatnego atrybutu WyrWolne
  bool licz_wyznaczniki();  // liczby wyznaczniki metodą crammera
  void licz_wyniki();
  void licz_wektor_bledu();
  SWektor<typ,wymiar> oblicz();
  void wyswietl_bledy(std::ostream& Strm);
}; 

/* 
 * Metoda dopasowuje wyznacznik tak, aby na digonali były luczby niezerowe
 * a pod nią same zera, jeśli jest ot wykonalne.
 * Argumenty:
 * -bool &parzystosc - referencja parametru wsazujacego na parzystosc zmaina kolumn
 *  jeśli jeden to mnożymy przez 1, jeśli 0 to mnożymy przez -1
 * Zwraca:
 *  bool - True (1), jeśli równanie jest oznaczone
 *         False (0), jeśli równanie jest nieoznaczone lub sprzeczne
 */
template<typename typ, int wymiar>
bool SUkladRownanLiniowych<typ,wymiar>::licz_wyznaczniki()
{
    MacWej.transponuj();
    wyznacznik_glowny = MacWej.wyznacznik_gauss();
    if(wyznacznik_glowny == 0) return 0;
    else {
        SMacierz<typ,wymiar>  pom;
        for(int i=0; i<wymiar; ++i) // liczenie wyznacznika w[i]
        {
            pom = MacWej;
            for(int a=0; a<wymiar; ++a) pom[a][i] = WyrWolne[a];
            wyznaczniki[i] = pom.wyznacznik_gauss();
        }
        return 1;
    }
} 

/*
 * Metoda wylicza wyniki układu równań
 * Argumenty: -brak
 * wylicza wyniki[i] przez metodę cramera
 */
template<typename typ, int wymiar> 
void SUkladRownanLiniowych<typ,wymiar>::licz_wyniki()
{
    for(int i=0; i<wymiar; ++i) wyniki[i] = wyznaczniki[i] / wyznacznik_glowny;
}

/*
 * Metoda wylicza wektor błedu rozwiązań układu równań
 * zmienia wartośc atrybutu WektorBlendu
 */
template<typename typ, int wymiar> 
void SUkladRownanLiniowych<typ,wymiar>::licz_wektor_bledu()
{
    WektorBledu = (MacWej * wyniki) - WyrWolne;
} 

/*
 * Metoda wyświetla wektor błędu układu równań liniowych
 * Argumenty: 
 *  - std::ostream &Strm - referencja strumienia wyjściowego
 */
template<typename typ, int wymiar> 
void SUkladRownanLiniowych<typ,wymiar>::wyswietl_bledy(std::ostream& Strm) 
{
    Strm<< std::endl << "         Wektor bledu:  Ax-b = (" << WektorBledu << " )"<< std::endl;
    Strm << "Dlugosc wektora bledu: |Ax-b| = " << WektorBledu.dlugosc() << std::endl;
}

/*
 * Przeciążenie operatora wczytywania (>>) 
 * Argumenty:
 *  - std::istream &Strm - referencja sturmienia wejściowego
 *  - UkladRownanLiniowych &UklRown - referencja układu równań linoiwych
 * Zwraca:
 *  - std::istream& - referencja strumienia wejściowego.
 */
template<typename typ, int wymiar> 
std::istream& operator >> (std::istream &Strm, SUkladRownanLiniowych<typ,wymiar> &UklRown)
{
    Strm >> UklRown.ustawMacWej();
    Strm >> UklRown.ustawWyrWolne();
    return Strm;
}

/*
 * Przeciążenie operatora wczytywania (<<)
 * Argumenty:
 *  - std::ostream &Strm - referencja strumienia wejściowego
 *  - UkladRownanLiniowych UklRown - układ równań liniowych do wyświtlania
 * Zwrac:
 *  - std::ostream& - referencja strumienia wyjściowehgo
 */
// UWAGA, OPERATOR NIE TRANSPONUJE MACIERZY
template<typename typ, int wymiar> 
std::ostream& operator << (std::ostream &Strm, SUkladRownanLiniowych<typ,wymiar> UklRown)
{
    for(int i=0; i<wymiar; ++i)
    {
        Strm << "| ";
        for(int j=0; j<wymiar; ++j)
        {
            Strm << UklRown.dajMacWej()[i][j];
            Strm << " ";
        }
        Strm << "||x_";
        Strm << i+1 ;
        if(i==wymiar/2) Strm << "| = | ";
        else Strm << "|   | ";
        Strm << UklRown.dajWyrWolne()[i];
        Strm << " |";
        Strm << std::endl;
    }
    return Strm;
}

#endif


