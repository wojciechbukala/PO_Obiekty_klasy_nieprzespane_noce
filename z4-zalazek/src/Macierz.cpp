#include "Macierz.hh"

Wektor Macierz::operator * (const Wektor Wektor2) const // Mnożenie macierza przez wektor 
{
    Wektor Wynik;
    for(int i=0; i<ROZMIAR; ++i)
    for(int j=0; j<ROZMIAR; ++j)
    Wynik[i] += Tab[i][j] * Wektor2[j];
    return Wynik;
}

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
    std::cout << "  " << std::endl;
    for(int i=0; i<ROZMIAR; ++i) Strm<< " " << Mac[i];
    return Strm;
}
