#include "Macierz.hh"

Wektor& Macierz::operator * (const Wektor Wektor2) const // Mnożenie macierza przez wektor 
{
    Wektor Wynik;
    //for(int b=0; b<ROZMIAR; ++b) Wynik[b]=0;
    Wektor &w = Wynik;
    for(int i=0; i<ROZMIAR; ++i)
    for(int j=0; j<ROZMIAR; ++j)
    Wynik[i] += (Tab[i][j] * Wektor2[j]);
    return w;
}

/* 
 * Medota przeciążająca operator przypisania dla macierzy
 * Argumenty:
 *  -Macierz& Macierz- referencja macierzy przypisywanej do innej
 * Zwraca:
 *  Macierz& *this - referencja macierzy po przekształceniu
 */
Macierz& Macierz::operator = (Macierz & Macierz2)
{
    for(int j=0; j<ROZMIAR; ++j)
    for(int i=0; i<ROZMIAR; ++i) this->Tab[j][i] = Macierz2.Tab[j][i];
    return *this;
}

/* 
 * Medota transponuje orginalną macierz
 * Argumenty:
 *  -brak
 * Zwraca:
 *  -brak
 */
void Macierz::transponuj () // transponowanie macierzy
{
    Macierz Transpozycja;
    for(int i=0; i<ROZMIAR; ++i)
    for(int j=0; j<ROZMIAR; ++j)
    Transpozycja[i][j] = Tab[j][i];
    
    for(int i=0; i<ROZMIAR; ++i)
    for(int j=0; j<ROZMIAR; ++j)
    Tab[i][j] = Transpozycja[i][j];
}
void Macierz::kopiuj()
{
    for(int i=0; i<ROZMIAR; ++i)
    for(int j=0; j<ROZMIAR; ++j)
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
bool Macierz::zeruj(int &parzystosc)
{
    double wspolczynnik = 0;
    

        int k = 1;
        while(k!= ROZMIAR)
        {   if(kopia[k-1][k-1] == 0)
            {
                for(int i=k; i<ROZMIAR; ++i)
                {
                    if(kopia[i][k-1]!=0) {
                        Wektor pom = kopia[i];
                        kopia[i] = kopia[k-1];
                        kopia[k-1] = pom;
                        parzystosc*=(-1);
                        }
                    else if(i==ROZMIAR-1) return 0;
                }
            }  
            for(int a=k; a<ROZMIAR; ++a)
            {
                wspolczynnik = kopia[a][k-1] / kopia[k-1][k-1];
                for(int i=0; i<ROZMIAR; ++i)
                kopia[a][i] = kopia[a][i] - (kopia[k-1][i] * wspolczynnik);
            }
            ++k;
        }
    return 1;
}

/* 
 * Metoda dopasowuje wyznacznik tak, aby na digonali nie było zer
 * Argumenty:
 * -bool &parzystosc - referencja parametru wsazujacego na parzystosc zmaina kolumn
 *  jeśli jeden to mnożymy przez 1, jeśli 0 to mnożymy przez -1
 * Zwraca:
 *  bool - True (1), jeśli wyznacznik != 0
 *         False (0), jeśli wyznacznik == 0
 */
/*
void Macierz::zamien_wiersz(Macierz& mac, Wektor wek1, Wektor wek2)
{
     Wektor pom = wek1;
     wek1 = wek2;
     wek2 = pom;
} */

/* 
 * Metoda wylicza iloczyn elementów na diagonali
 * Argumenty:
 * -brak
 * Zwraca:
 *  double wynik- liczba zmiennoprzecinkowa będąca iloczynem wyrazów na diagonali
 */
double Macierz::mnozenie_diagonali () const
{
    double wynik=1;
    for(int i=0; i<ROZMIAR; ++i) wynik *= kopia[i][i];
    return wynik;
} 
/* 
 * Metoda wyznacza wyznacznik gaussa wraz z wszystkimi warunkami
 * Argumenty:
 * -brak
 * Zwraca:
 *  double wyznacznik - liczba zmienno przecinkowa będąca wyznacznikiem
 */
double Macierz::wyznacznik_gauss ()
{
    double wyznacznik;
    int parzystosc = 1;
    kopiuj();
    if(zeruj(parzystosc))
    wyznacznik=mnozenie_diagonali() * parzystosc;
    else wyznacznik = 0;
    return wyznacznik;
}

/* 
 * Przeciążenie wczytujące Macierz ze strumienia std::istream
 * Akceptowany format prametrów macierzy to liczby zmiennoprzicnkowe
 * Argumenty:
 *  Macierz &Mac - referencja macierzy do któregej wpisujemy parametry
 *  std::istream &Strm - referencja sturmienia wejściowego
 * Zwraca:
 *  Wczytuje strumieniem std::istream 
 */
std::istream& operator >> (std::istream &Strm, Macierz &Mac)
{
    for(int i=0; i<ROZMIAR; ++i)
    {
        Strm >>Mac[i];
        if(Strm.fail()) return Strm;
    }
    return Strm;
}

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &Strm, Macierz Mac)
{
    Strm << "  " << std::endl;
    for(int i=0; i<ROZMIAR; ++i) Strm<< " " << Mac[i] <<std::endl;
    return Strm;
}
