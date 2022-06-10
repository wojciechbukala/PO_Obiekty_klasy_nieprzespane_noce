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
  
  for(std::list<std::shared_ptr<ObiektGeom>>::iterator iter = ObiektySceny.begin(); iter != ObiektySceny.end(); ++iter) 
    {    
    wInfoPliku = &Lacze.DodajNazwePliku((*iter)->WezNazwePliku_BrylaRysowana());
    wInfoPliku->ZmienKolor((*iter)->WezKolorID());
    }
}


Scena::Scena()
{
    Wektor3D laziki_skala(20,20,10), lazik1_polozenie, lazik2_polozenie(50,40,10), lazik3_polozenie(-20,70,20);
    Wektor3D regolit_skala(2,6,2), regolit1_polozenie(0,90,0), regolit2_polozenie(0,85,0), regolit3_polozenie(10,80,0),
    regolit4_polozenie(70,60,0), regolit5_polozenie(70,50,0), regolit6_polozenie(-70,55,0), regolit7_polozenie(-80,65,0),
    regolit8_polozenie(-60,50,0), regolit9_polozenie(50,-60,0);

    Inicjalizuj_Lacze();
    if (!Inicjalizuj_PowierzchnieMarsa(Lacze)) std::cerr << "Blad 1";

    std::shared_ptr<LazikSFR> Lazik1 = std::make_shared<LazikSFR>("bryly_wzorcowe/szescian3.dat","FSR",Kolor_JasnoNiebieski, laziki_skala, lazik1_polozenie,0, 10);
    ObiektySceny.push_back(Lazik1);  // tworzymy pierwszy łazik

    std::shared_ptr<Lazik> Lazik2 = std::make_shared<Lazik>("bryly_wzorcowe/szescian3.dat","Perseverance",Kolor_Czerwony, laziki_skala, lazik2_polozenie, 0, 10);
    ObiektySceny.push_back(Lazik2);  // tworzymy drugi łazik

    std::shared_ptr<Lazik> Lazik3 = std::make_shared<Lazik>("bryly_wzorcowe/szescian3.dat","Curiosity",Kolor_Czerwony, laziki_skala, lazik3_polozenie, 0, 10);
    ObiektySceny.push_back(Lazik3);  // tworzymy trzeci łazik

    std::shared_ptr<ProbkaRegolitu> Rego1 = std::make_shared<ProbkaRegolitu>("bryly_wzorcowe/szescian2.dat","Coulettes",Kolor_Czerwony, regolit_skala, regolit1_polozenie);
    ObiektySceny.push_back(Rego1);  // wrzucamy próbkę regolitu na listę obiektów

    std::shared_ptr<ProbkaRegolitu> Rego2 = std::make_shared<ProbkaRegolitu>("bryly_wzorcowe/szescian2.dat","Salette",Kolor_Czerwony, regolit_skala, regolit2_polozenie);
    ObiektySceny.push_back(Rego2);  // wrzucamy próbkę regolitu na listę obiektów
        
    std::shared_ptr<ProbkaRegolitu> Rego3 = std::make_shared<ProbkaRegolitu>("bryly_wzorcowe/szescian2.dat","Dourbes",Kolor_Czerwony, regolit_skala, regolit3_polozenie);
    ObiektySceny.push_back(Rego3);  // wrzucamy próbkę regolitu na listę obiektów

    std::shared_ptr<ProbkaRegolitu> Rego4 = std::make_shared<ProbkaRegolitu>("bryly_wzorcowe/szescian2.dat","Robine",Kolor_Czerwony, regolit_skala, regolit4_polozenie);
    ObiektySceny.push_back(Rego4);  // wrzucamy próbkę regolitu na listę obiektów

    std::shared_ptr<ProbkaRegolitu> Rego5 = std::make_shared<ProbkaRegolitu>("bryly_wzorcowe/szescian2.dat","Quatier",Kolor_Czerwony, regolit_skala, regolit5_polozenie);
    ObiektySceny.push_back(Rego5);  // wrzucamy próbkę regolitu na listę obiektów
        
    std::shared_ptr<ProbkaRegolitu> Rego6 = std::make_shared<ProbkaRegolitu>("bryly_wzorcowe/szescian2.dat","Bellegarde",Kolor_Czerwony, regolit_skala, regolit6_polozenie);
    ObiektySceny.push_back(Rego6);  // wrzucamy próbkę regolitu na listę obiektów

    std::shared_ptr<ProbkaRegolitu> Rego7 = std::make_shared<ProbkaRegolitu>("bryly_wzorcowe/szescian2.dat","Montdenier",Kolor_Czerwony, regolit_skala, regolit7_polozenie);
    ObiektySceny.push_back(Rego7);  // wrzucamy próbkę regolitu na listę obiektów

    std::shared_ptr<ProbkaRegolitu> Rego8 = std::make_shared<ProbkaRegolitu>("bryly_wzorcowe/szescian2.dat","Montagnac",Kolor_Czerwony, regolit_skala, regolit8_polozenie);
    ObiektySceny.push_back(Rego8);  // wrzucamy próbkę regolitu na listę obiektów
        
    std::shared_ptr<ProbkaRegolitu> Rego9 = std::make_shared<ProbkaRegolitu>("bryly_wzorcowe/szescian2.dat","Roubion",Kolor_Czerwony, regolit_skala, regolit9_polozenie);
    ObiektySceny.push_back(Rego9);  // wrzucamy próbkę regolitu na listę obiektów

    AktualnyLazik = Lazik1; 
    (Lazik1)->Przelicz_i_Zapisz_Wierzcholki();
    (Lazik2)->Przelicz_i_Zapisz_Wierzcholki();
    (Lazik3)->Przelicz_i_Zapisz_Wierzcholki();
    (Rego1)->Przelicz_i_Zapisz_Wierzcholki();
    (Rego2)->Przelicz_i_Zapisz_Wierzcholki();
    (Rego3)->Przelicz_i_Zapisz_Wierzcholki();
    (Rego4)->Przelicz_i_Zapisz_Wierzcholki();
    (Rego5)->Przelicz_i_Zapisz_Wierzcholki();
    (Rego6)->Przelicz_i_Zapisz_Wierzcholki();
    (Rego7)->Przelicz_i_Zapisz_Wierzcholki();
    (Rego8)->Przelicz_i_Zapisz_Wierzcholki();
    (Rego9)->Przelicz_i_Zapisz_Wierzcholki(); 

    DodajDoListyRysowania();
    Lacze.Rysuj();

    CzyMoznaZebrac = false;
}

void Scena::obrot(PzG::LaczeDoGNUPlota  Lacze, std::ostream& StrmWyj, std::istream& StrmWej)
{
    StrmWyj << "Podaj kat obrotu: ";
    double nowy_kat;
    StrmWej >> nowy_kat;
    if(nowy_kat > 0)
    {
        for(double i = AktualnyLazik->DajKatOrientacji(); i<nowy_kat + AktualnyLazik->DajKatOrientacji(); ++i)
        {
            AktualnyLazik->Rotacja(i);
            AktualnyLazik->Przelicz_i_Zapisz_Wierzcholki();
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
            Lacze.Rysuj();
        }
    } else {
        for(double i = AktualnyLazik->DajKatOrientacji(); i>nowy_kat + AktualnyLazik->DajKatOrientacji(); --i)
        {
            AktualnyLazik->Rotacja(i);
            AktualnyLazik->Przelicz_i_Zapisz_Wierzcholki();
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
            Lacze.Rysuj();
        }
    }
    AktualnyLazik->WpiszKatOrientacji(AktualnyLazik->DajKatOrientacji()+nowy_kat);
    //AktualnyLazik->WpiszKatOrientacji += nowy_kat;
} 

void Scena::jazda(PzG::LaczeDoGNUPlota  Lacze, std::istream& StrmWej, std::ostream& StrmWyj)
{
    StrmWyj << "Podaj odleglosc do przejechania:";
    double WpiszOdlegolosc;
    StrmWej >> WpiszOdlegolosc;
    AktualnyLazik->WpiszOdlegloscDoPrzejechania(WpiszOdlegolosc);
    Wektor3D nowe_polozenie = AktualnyLazik->DajPolozenie();  // wektor do obliczeń, po wykonaniu animacji ma nowe współżędne
    double kat_roboczy;
    if(AktualnyLazik->DajOdlegloscDoPrzejechania()<0) kat_roboczy = AktualnyLazik->DajKatOrientacji() + 180; // jeśli mamy jechać do tyłu to zmieniamy orientację o 180 stopni
    else kat_roboczy = AktualnyLazik->DajKatOrientacji(); // przypadek kiedy jedziemy do przodu
    double x_kierunek = cos(kat_roboczy*3.14/180); // przesuniecie o x , double x = OdlegloscDoPrzejechania * cos(KatOrientacji)
    double y_kierunek = sin(kat_roboczy*3.14/180); // przesuniecie o y , double y = OdlegloscDoPrzejechania * sin(KatOrientacji)


    for(double i = 0 ; i < abs(AktualnyLazik->DajOdlegloscDoPrzejechania()); ++i)  // dzielimy przejście na OdlegloscDoPrzejechania*100 małych kroczkow
      {
      nowe_polozenie[0] += x_kierunek;
      nowe_polozenie[1] += y_kierunek;  
      AktualnyLazik->zmien_polozenie(nowe_polozenie);
      if(AktualnyLazik->Przelicz_i_Zapisz_Wierzcholki()) std::this_thread::sleep_for(std::chrono::milliseconds(200/int(AktualnyLazik->DajSzybkosc()))); // odstęp czasowy zależny od szybkości
      Lacze.Rysuj();
      if(CzyAktywnyLazikKoliduje() == TK_Kolizja) {std::cout<<"KOLIZJA"; break;}
      }
      AktualnyLazik->WpiszPolozenie(nowe_polozenie); // zmieniamy położenie łazika na stałe
}

void Scena::WyborLazika(int lazik)
{
    std::list<std::shared_ptr<ObiektGeom>>::iterator iter = ObiektySceny.begin();
    for (int i=0; i < lazik; i++)
    {
        AktualnyLazik = std::static_pointer_cast<Lazik>(*iter);
        ++iter;
    }
}

void Scena::ZmienLazika(std::istream &StrmWe, std::ostream &StrmWy)
{
    std::list<std::shared_ptr<ObiektGeom>>::iterator iter = ObiektySceny.begin();
    int numer_lazika; // zmienna przechowująca numer drona
    /* Interfejs wyświetlania wszystkich trzech możliwośi wyboru drona. */
    StrmWy << "1. ---------- Nazwa: Sample_Fetch_Rover" << std::endl;
    StrmWy << "          Polozenie: " << std::static_pointer_cast<Lazik>(*iter)->DajPolozenie() << std::endl;
    StrmWy << "    Orientacja [st]: " << std::static_pointer_cast<Lazik>(*iter)->DajKat() << std::endl;
    StrmWy << std::endl;
    iter++;
    StrmWy << "2. ---------- Nazwa: Perseverance" << std::endl;
    StrmWy << "          Polozenie: " << std::static_pointer_cast<Lazik>(*iter)->DajPolozenie() << std::endl;
    StrmWy << "    Orientacja [st]: " << std::static_pointer_cast<Lazik>(*iter)->DajKat() << std::endl;
    StrmWy << std::endl;
    iter++;
    StrmWy << "3. ---------- Nazwa: Curiosity" << std::endl;
    StrmWy << "          Polozenie: " << std::static_pointer_cast<Lazik>(*iter)->DajPolozenie() << std::endl;
    StrmWy << "    Orientacja [st]: " << std::static_pointer_cast<Lazik>(*iter)->DajKat() << std::endl;
    StrmWy << std::endl;
    StrmWy << "Podaj numer lazik >";
    StrmWe >> numer_lazika;
    WyborLazika(numer_lazika);   
}


void Scena::zmien_szybkosc(std::istream &StrmWe, std::ostream &StrmWy)
{
    double nowa_szybkosc;
    StrmWy << "Podaj nowa szybkosc lazika: ";
    StrmWe >> nowa_szybkosc;
    AktualnyLazik->WpiszSzybkosc(nowa_szybkosc);
}


TypKolizji Scena::CzyAktywnyLazikKoliduje()
{
    CzyMoznaZebrac = false;
    TypKolizji wynikKolizji = TK_BrakKolizji;
   // std::shared_ptr<ObiektGeom>  ObKolid = nullptr;
    for(const std::shared_ptr<ObiektGeom> & Ob : ObiektySceny)
    {
        if(ObiektySceny.empty()) return wynikKolizji;
        if(Ob != AktualnyLazik)
        {
            //if(Ob->CzyKolizja(AktualnyLazik) == TK_Kolizja) std::cout << "Kolizja" <<std::endl;
            wynikKolizji = Ob->CzyKolizja(AktualnyLazik);
            if(wynikKolizji != TK_BrakKolizji) // KOLIZJA!
            {
                if(Ob->JakiObiekt() == "ProbkaRegolitu" && AktualnyLazik->JakiObiekt() == "LazikSFR") 
                {
                    /* jeśli kolidują ze sobą próbka regolitu i łazik SFR to można zebarać probkę */
                    AktualnaProbka = std::static_pointer_cast<ProbkaRegolitu>(Ob);
                    CzyMoznaZebrac = true;
                }
                return wynikKolizji;
            }
        }
    }
    return wynikKolizji;
} 

void Scena::WyswietlProbki (std::ostream &StrmWy)
{
    int i=-2;
    for(const std::shared_ptr<ObiektGeom> & Ob : ObiektySceny)
    {
        if(ObiektySceny.empty()) {StrmWy << "Brak probek na liscie!" << std::endl; break;}
        if(Ob->JakiObiekt() == "ProbkaRegolitu")
        {
            StrmWy<<i<<". ";
            StrmWy << Ob->DajNazweObiektu() << std::endl;
        }
        ++i;
    }
}

 void Scena::ZbierzProbke (std::shared_ptr<ObiektGeom>  Probka)
 {
     if(AktualnyLazik->JakiObiekt() != "LazikSFR") // Jeśli nie jest to lazik sfr to nie można zebrać probki
     {
         std::cerr << "Lazik inny niz SFR. Nie mozna zebrac probki!" << std::endl;
     }
     else // Aktulany lazik jest Lazikiem SFR
     {
         std::static_pointer_cast<LazikSFR>(AktualnyLazik)->DodajDoListyProbek(std::static_pointer_cast<ProbkaRegolitu>(Probka));
         Lacze.UsunNazwePliku(Probka->DajNazwePlikuBrylaRysowana());
         ObiektySceny.remove(Probka);
         Lacze.Rysuj();
     }
 }

void Scena::PodejmijProbke(std::ostream& StrmWy)
{
    if(CzyMoznaZebrac == false) StrmWy << "Nie można zebrać probki" << std::endl;
    else ZbierzProbke(AktualnaProbka);
}
 
 void Scena::WyswietlProbkiSFR (std::ostream &StrmWyj)
 {
    if(AktualnyLazik->JakiObiekt() == "LazikSFR") 
    {
        std::static_pointer_cast<LazikSFR>(AktualnyLazik)->WyswietlListeProbek(StrmWyj);
    }
 }

void Scena::StanAktualnegoLazika (std::ostream& StrmWy)
{
    AktualnyLazik->WyswietlStan(StrmWy);
}