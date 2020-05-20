/*!
 * \file main.c
 *
 * \author Ilias Bougrhous, Vincent Donney, Sacha Grumelart et Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 11 mai 2020
 *
 * \brief fonction princpale
 *
 *
 */

// Inclusion des librairies
#include "tableau.h"
#include "jeu.h"

//Code de la fonction

int main(int argc, char const *argv[]) {
  int** tab;
  int n;
  n = 4;
  tab = creerTabEntier2D(n);
  afficherTab(tab, n);
  freeTab2D(tab, n);
  return 0;
}
