#include "ObrysXY.hh"
#include <cmath>
#include <algorithm>

bool ObrysXY::NakladajaSie(ObrysXY DrugiLazik)
{

    double dlugosc_boku_x = bokX[1] - bokX[0];
    double dlugosc_boku_y = bokY[1] - bokY[0];


    double drugi_lazik_dlugosc_boku_x = DrugiLazik.bokX[1] - DrugiLazik.bokX[0];
    double drugi_lazik_dlugosc_boku_y = DrugiLazik.bokY[1] - DrugiLazik.bokY[0];

    double pom1, pom2;

    if(bokX[1]*DrugiLazik.bokX[0]>=0) 
        pom1 = abs(std::max(bokX[1],bokX[0])-std::min(DrugiLazik.bokX[0], DrugiLazik.bokX[1]));
    else pom1 = abs(std::max(bokX[1],bokX[0])+std::min(DrugiLazik.bokX[0],DrugiLazik.bokX[1])); 

    if(bokY[1]*DrugiLazik.bokY[0]>=0) pom2 = abs(std::max(bokY[1],bokY[0])-std::min(DrugiLazik.bokY[0], DrugiLazik.bokY[1]));
    else pom2 = abs(std::max(bokY[1],bokY[0])+std::min(DrugiLazik.bokY[0],DrugiLazik.bokY[1])); 
 
    if((pom1 <= dlugosc_boku_x + drugi_lazik_dlugosc_boku_x)
        && (pom2<= dlugosc_boku_y + drugi_lazik_dlugosc_boku_y))
         {     std::cout << DrugiLazik.bokX << " " << DrugiLazik.bokY<< std::endl;
                std::cout << drugi_lazik_dlugosc_boku_x << " "<< drugi_lazik_dlugosc_boku_y << std::endl; 
                 std::cout << bokX << " " << bokY<< std::endl;
                std::cout << dlugosc_boku_x << " "<< dlugosc_boku_y << std::endl; 
                std::cout << pom1 << " " << pom2 << std::endl;

    return true;} // nakładają się
    else return false; // nie nakładają się 

}