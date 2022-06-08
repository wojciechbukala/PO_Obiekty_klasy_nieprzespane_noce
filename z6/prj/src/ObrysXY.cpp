#include "ObrysXY.hh"
#include <cmath>
#include <algorithm>

bool ObrysXY::NakladajaSie(ObrysXY DrugiLazik)
{


        if((bokX[0] < DrugiLazik.bokX[1] && DrugiLazik.bokX[0] < bokX[1]) && 
        (bokY[0] < DrugiLazik.bokY[1] && DrugiLazik.bokY[0] < bokY[1]))
         { return true;} // nakładają się
    else return false; // nie nakładają się 
}