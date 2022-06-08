#ifndef LAZIK_SFR
#define LAZIK_SFR
#include "Lazik.hh"
#include "ProbkaRegolitu.hh"


class LazikSFR : public Lazik
{
    std::list<std::shared_ptr<ProbkaRegolitu>> ListaProbek;
    public:
    TypKolizji CzyKolizja(std::shared_ptr<Lazik> l) override;
};

#endif
