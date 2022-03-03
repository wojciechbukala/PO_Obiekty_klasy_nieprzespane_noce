#include <iostream>
#include <cmath>

using namespace std;

/*
 * Typ wyliczeniowy dla okreslenia ilosc otrzymanych
 * pierwiastkow. Lepiej jest stosowac typ wyliczeniowy
 * niz zwykle wartosci calkowite.
 * Pozwala to uniknac przypadkowych bledow.
 */
enum T_IloscPierwiastkow { IP_brak, IP_jeden, IP_dwa };


struct TrojmianKw {
  double  a;
  double  b;
  double  c;
};




void WprowadzWspTrojmianu( TrojmianKw *wTKw )
{
  cout << "Podaj wspolczynnik a:\n";
  cin >> wTKw->a;
  cout << "Podaj wspolczynnik b:\n";
  cin >> wTKw->b;
  cout << "Podaj wspolczynnik c:\n";
  cin >> wTKw->c;
 
}


void WyswietlTrojmian( TrojmianKw TKw )
{
  cout<<"Trojmian: " << TKw.a<<"*x^2 + " << TKw.b << "*x + " << TKw.c << "\n"; // Uzupełniono
}


/*!
 * Oblicza delte oraz wartosci pierwiastkow. Wartosci wyliczonych
 * pierwiastkow podstawiane sa do zmiennych odstepnych poprzez
 * wskazniki wX1 oraz wX2.
 * Interpretacja wynikow zalezy od zwroconej wartosci calkowitej
 * i jest ona nastepujaca:
 *  IP_dwa   - wyznaczono dwa pierwiastki rzeczywiste, kolejne pierwiastki
 *             wpisane sa do zmiennych dostenych poprzez wskazniki wX1 i wX2.
 *  IP_jeden - rownanie ma tylko jeden pierwiastek rzeczywisty, wynik 
 *             zostaje wpisany do zmiennej przekazanej poprzez wskaznik wX1.
 *  IP_brak  - brak rozwiazan w zbirze liczb rzeczywistych.
 */
T_IloscPierwiastkow WyliczPierwiastki(TrojmianKw   TKw, double *wX1, double *wX2)
{
  double   Delta, Delta_2;

  Delta_2  = (TKw.b*TKw.b) - (4.0*TKw.a*TKw.c);

  if (Delta_2 > 0) {

      Delta = sqrt( Delta_2 );
      *wX1 = (-TKw.b - Delta) / (2*TKw.a); 
      *wX2 = (-TKw.b + Delta) / (2*TKw.a); //Uzupełniono
      return IP_dwa;

  } else if  (Delta_2 == 0) {

      *wX1 = -TKw.b/(2*TKw.a);
      return IP_jeden;

  }
  /* czyli d < 0 */
  return IP_brak;
}




int main() {
  TrojmianKw   TKw;
  double       X1, X2;
  

  cout << "Program wylicza rozwiazania trojmianu kwadratowego.\n";  

  WprowadzWspTrojmianu(&TKw);

  if (TKw.a == 0) {
    cout<<"Nie jest to trojmian kwadratowy\n"; // Uzupełniono
    return 1;
  }

  WyswietlTrojmian(TKw);
  
  switch (WyliczPierwiastki(TKw,&X1,&X2)) {
    case IP_dwa:
      cout << "Istnieja dwa rozwiazania rzeczywiste:\n";
      cout << "  x1 = " << X1 << endl;
      cout << "  x1 = " << X2 << endl; // Uzupełniono
      break;

    case IP_jeden:
    cout << "Istnieje jedno rozwiazanie rzeczywiste:\n x0 = "<< X1 <<endl; // Uzupełniono
      break;

    case IP_brak:
    cout<< "Brak pierwiastkow rzeczywistych rownania"<< endl; // Uzupełniono
      break;
  }

  return 0;
}

