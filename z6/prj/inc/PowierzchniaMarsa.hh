#ifndef POWIERZCHNIAMARSA_HH
#define POWIERZCHNIAMARSA_HH

#include "lacze_do_gnuplota.hh"



#define ROMIAR_POWIERZCHNI_X    200
#define ROMIAR_POWIERZCHNI_Y    200
#define ROZMIAR_OCZKA_KRATY     10


/*!
   * \brief Funkcja inicjalizująca powierzchnie marsa.
   * 
   * \param [in] &rLacze - referencja łącza
   * \retrun 
   */
bool Inicjalizuj_PowierzchnieMarsa(
				    PzG::LaczeDoGNUPlota  &rLacze
				  );

#endif
