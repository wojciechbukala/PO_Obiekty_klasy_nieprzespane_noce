#include <iostream>
#include "WyrazenieZesp.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */



bool WczytajWyrazenieZesp(WyrazenieZesp &rWyrZ, std::istream &rStrmWe)
{
  rStrmWe >> rWyrZ.Arg1.re;
  
  return rStrmWe.fail() == false;
}

