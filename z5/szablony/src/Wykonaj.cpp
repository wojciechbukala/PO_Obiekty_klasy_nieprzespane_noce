#include "Wykonaj.hh"
#include <unistd.h>

/* 
 * Funkcja wykonuje funkcjonalność rozwiązywania układów równań
 * Argumenty:
 * - std::istream &istream - referencja strumienia wejściowego
 * - std::ostream &ostr - refernacja strumienia wyjściowego
 * - UkladRownanLiniowych &uklad - uklad rownan liniowych do obliczenia i wyświtlaenia wyników
 * Zwraca:
 *  - brak :(
 */

void wykonaj(std::istream &istr, std::ostream &ostr, SUkladRownanLiniowych<typ,wymiar>& uklad)
{
    istr >> uklad;  
    if(uklad.licz_wyznaczniki()) // Jesli wyznacznik macierzy nie jest równy zero
    {
        uklad.licz_wyniki(); // oblicz wynik układu
        ostr << uklad;
        sleep(0.001);
        ostr << std::endl <<"Rozwiazanie x = (x1, x2, x3):" << std::endl;
        ostr << "(";
        ostr<< uklad.wyniki;  // wyślietl wyniki ukladu
        ostr << " )";
        ostr << std::endl;     
    uklad.licz_wektor_bledu();  // obliczanie wektora bledu
    uklad.wyswietl_bledy(ostr);  // wyswietlanie wektora błedu
    ostr << std::endl;
    }
    else{
        ostr << "Wyznacznik macierzy równy 0!"<< std::endl <<"Układ równań jest nieoznaczony lub sprzezczny" << std::endl << std::endl;
    }
    
}