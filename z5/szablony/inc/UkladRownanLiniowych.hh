#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include <Macierz.hh>
#include <Wektor.hh>


/*
 *  Klasa modelująca pojęcię Układu Równań Liniwych.
 *  Może działać dla dowlonie dużego układu równań, jeśli
 *  ilość równań jest równa ilość szukanych rozwiązań
 */
/*
class UkladRownanLiniowych {
 
  double wyznacznik_glowny; 
  double wyznaczniki[ROZMIAR];
  Macierz MacWej; // Macierz współczynników
  Wektor WyrWolne; // Wektor wyrazów wolnych
  Wektor WektorBledu; // Opiekt klasy wektor do przechowywania wektora błedy

public:
  Wektor wyniki; // tabela wyników 
  Macierz dajMacWej() const {return MacWej;}; // zwraca atrybut prywatny MacWej
  Wektor dajWyrWolne() const {return WyrWolne;}; // zwraca atrybut prywatny WyrWolne 
  Macierz& ustawMacWej() {return MacWej;}; // zwraca referencje prywatnego atrybutu MacWej
  Wektor& ustawWyrWolne() {return WyrWolne;}; // zwraca referencje prywatnego atrybutu WyrWolne
  bool licz_wyznaczniki();  // liczby wyznaczniki metodą crammera
  void licz_wyniki();
  void licz_wektor_bledu();
  Wektor oblicz();
  void wyswietl_bledy(std::ostream& Strm);
}; */


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
//std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
//std::ostream& operator << (std::ostream &Strm, UkladRownanLiniowych UklRown);

#endif
