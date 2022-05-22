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

void Scena::WyborDrona(int dron)
{
    int ktory_dron = 0;
    std::list<std::shared_ptr<Lazik>>::iterator iter = ObiektySceny.begin();
    do
    {
        AktualnyLazik = *iter;
        ktory_dron++;
    } while(ktory_dron != dron);
}

