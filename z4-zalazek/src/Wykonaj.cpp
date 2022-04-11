#include "Wykonaj.hh"
#include <unistd.h>

void wykonaj(std::istream &istr, std::ostream &ostr, UkladRownanLiniowych& uklad)
{
    istr >> uklad;
    if(uklad.licz_wyznaczniki())
    {
        uklad.licz_wyniki();
        ostr << uklad;
        sleep(0.001);
        ostr << std::endl <<"Rozwiazanie x = (x1, x2, x3):" << std::endl;
        ostr<< uklad.wyniki;
    }
    else{
        ostr << "Wyznacznik macierzy równy 0!"<< std::endl <<"Układ równań jest nieoznaczony lub sprzezczny";
    }
    ostr << std::endl;
    uklad.licz_wektor_bledu();
    uklad.wyswietl_bledy(ostr);
    ostr << std::endl;
}
