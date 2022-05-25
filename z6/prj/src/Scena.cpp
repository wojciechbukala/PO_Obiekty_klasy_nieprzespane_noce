#include "Scena.hh"

void Scena::Inicjalizuj_Lacze()
{
  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.UstawZakresX(-ROMIAR_POWIERZCHNI_X/2, ROMIAR_POWIERZCHNI_X/2);
  Lacze.UstawZakresY(-ROMIAR_POWIERZCHNI_Y/2, ROMIAR_POWIERZCHNI_Y/2);
  Lacze.UstawZakresZ(-0, 90);  
  Lacze.UstawRotacjeXZ(40,60); // Tutaj ustawiany jest widok

  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.
}

void Scena::DodajDoListyRysowania()
{
  PzG::InfoPlikuDoRysowania *wInfoPliku;
  
  for(std::list<std::shared_ptr<Lazik>>::iterator iter = ObiektySceny.begin(); iter != ObiektySceny.end(); ++iter) 
    {    
    wInfoPliku = &Lacze.DodajNazwePliku((*iter)->WezNazwePliku_BrylaRysowana());
    wInfoPliku->ZmienKolor((*iter)->WezKolorID());
    }
}


Scena::Scena()
{
    Wektor3D wek1(20,20,10), wek2, wek3(60,60,10), wek4(-20,70,20), wek5(20,0,0), wek6(40,0,0);

    Inicjalizuj_Lacze();
    if (!Inicjalizuj_PowierzchnieMarsa(Lacze)) std::cerr << "Blad 1";

    std::shared_ptr<Lazik> Lazik1 = std::make_shared<Lazik>("bryly_wzorcowe/szescian3.dat","FSR",Kolor_JasnoNiebieski, wek1, wek2,0, 10);
    ObiektySceny.push_back(Lazik1);  // tworzymy pierwszy łazik

    std::shared_ptr<Lazik> Lazik2 = std::make_shared<Lazik>("bryly_wzorcowe/szescian3.dat","Perseverance",Kolor_Czerwony, wek1, wek3, 0, 10);
    ObiektySceny.push_back(Lazik2);  // tworzymy drugi łazik

    std::shared_ptr<Lazik> Lazik3 = std::make_shared<Lazik>("bryly_wzorcowe/szescian3.dat","Curiosity",Kolor_Czerwony, wek1, wek4, 0, 10);
    ObiektySceny.push_back(Lazik3);  // tworzymy trzeci łazik

    AktualnyLazik = Lazik1;
    (Lazik1)->Przelicz_i_Zapisz_Wierzcholki();
    (Lazik2)->Przelicz_i_Zapisz_Wierzcholki();
    (Lazik3)->Przelicz_i_Zapisz_Wierzcholki();
    
    
    DodajDoListyRysowania();
    Lacze.Rysuj();
}

void Scena::WyborLazika(int lazik)
{
    std::list<std::shared_ptr<Lazik>>::iterator iter = ObiektySceny.begin();
    for (int i=0; i < lazik; i++)
    {
        AktualnyLazik = *iter;
        ++iter;
    }
}

void Scena::ZmienLazika(std::istream &StrmWe, std::ostream &StrmWy)
{
    std::list<std::shared_ptr<Lazik>>::iterator iter = ObiektySceny.begin();
    int numer_lazika; // zmienna przechowująca numer drona
    /* Interfejs wyświetlania wszystkich trzech możliwośi wyboru drona. */
    StrmWy << "1. ---------- Nazwa: Sample_Fetch_Rover" << std::endl;
    StrmWy << "          Polozenie: " << (*iter)->DajPolozenie() << std::endl;
    StrmWy << "    Orientacja [st]: " << (*iter)->DajKat() << std::endl;
    StrmWy << std::endl;
    iter++;
    StrmWy << "2. ---------- Nazwa: Perseverance" << std::endl;
    StrmWy << "          Polozenie: " << (*iter)->DajPolozenie() << std::endl;
    StrmWy << "    Orientacja [st]: " << (*iter)->DajKat() << std::endl;
    StrmWy << std::endl;
    iter++;
    StrmWy << "3. ---------- Nazwa: Curiosity" << std::endl;
    StrmWy << "          Polozenie: " << (*iter)->DajPolozenie() << std::endl;
    StrmWy << "    Orientacja [st]: " << (*iter)->DajKat() << std::endl;
    StrmWy << std::endl;
    StrmWy << "Podaj numer lazik >";
    StrmWe >> numer_lazika;
    WyborLazika(numer_lazika);   
}

void Scena::WyswietlAktywny(std::ostream &StrmWy)
{
    if(AktualnyLazik->WezNazweObiektu()=="FSR") StrmWy << "1. ---------- Nazwa: Sample_Fetch_Rover" << std::endl;
    if(AktualnyLazik->WezNazweObiektu()=="Perseverance") StrmWy << "2. ---------- Nazwa: Perserverance" << std::endl;
    if(AktualnyLazik->WezNazweObiektu()=="Curiosity") StrmWy << "3. ---------- Nazwa: Curiosity" << std::endl;
    StrmWy << "          Polozenie: " << AktualnyLazik->DajPolozenie() << std::endl;
    StrmWy << "    Orientacja [st]: " << AktualnyLazik->DajKat() << std::endl;
    StrmWy << std::endl;
}

void Scena::zmien_szybkosc(std::istream &StrmWe, std::ostream &StrmWy)
{
    double nowa_szybkosc;
    StrmWy << "Podaj nowa szybkosc lazika: ";
    StrmWe >> nowa_szybkosc;
    AktualnyLazik->WpiszSzybkosc(nowa_szybkosc);
}