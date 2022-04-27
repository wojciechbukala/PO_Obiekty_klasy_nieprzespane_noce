#include "UkladRownanLiniowych.hh"


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
bool UkladRownanLiniowych::licz_wyznaczniki()
{
    MacWej.transponuj();
    wyznacznik_glowny = MacWej.wyznacznik_gauss();
    if(wyznacznik_glowny == 0) return 0;
    else {
        Macierz pom;
        for(int i=0; i<ROZMIAR; ++i) // liczenie wyznacznika w[i]
        {
            pom = MacWej;
            for(int a=0; a<ROZMIAR; ++a) pom[a][i] = WyrWolne[a];
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
void UkladRownanLiniowych::licz_wyniki()
{
    for(int i=0; i<ROZMIAR; ++i) wyniki[i] = wyznaczniki[i] / wyznacznik_glowny;
}

/*
 * Metoda wylicza wektor błedu rozwiązań układu równań
 * zmienia wartośc atrybutu WektorBlendu
 */
void UkladRownanLiniowych::licz_wektor_bledu()
{
    WektorBledu = (MacWej * wyniki) - WyrWolne;
} 

/*
 * Metoda wyświetla wektor błędu układu równań liniowych
 * Argumenty: 
 *  - std::ostream &Strm - referencja strumienia wyjściowego
 */
void UkladRownanLiniowych::wyswietl_bledy(std::ostream& Strm) 
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
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown)
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
std::ostream& operator << (std::ostream &Strm, UkladRownanLiniowych UklRown)
{
    for(int i=0; i<ROZMIAR; ++i)
    {
        Strm << "| ";
        for(int j=0; j<ROZMIAR; ++j)
        {
            Strm << UklRown.dajMacWej()[i][j];
            Strm << " ";
        }
        Strm << "||x_";
        Strm << i+1 ;
        if(i==ROZMIAR/2) Strm << "| = | ";
        else Strm << "|   | ";
        Strm << UklRown.dajWyrWolne()[i];
        Strm << " |";
        Strm << std::endl;
    }
    return Strm;
}