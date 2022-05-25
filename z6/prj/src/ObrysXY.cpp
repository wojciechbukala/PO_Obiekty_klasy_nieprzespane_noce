#include "ObrysXY.hh"

bool ObrysXY::NakladajaSie(ObrysXY DrugiLazik)
{
    if(bokX== DrugiLazik.bokX && bokY == DrugiLazik.bokY) return false;
    /*if(bokX[0] == DrugiLazik.bokX[0] && bokY[0] == DrugiLazik.bokY[0]
     && bokX[1] == DrugiLazik.bokX[1 && bokY[1] == DrugiLazik.bokY[1]]) return false; */
    else return true;
}