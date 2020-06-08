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
  int** tab;//
  int n;
  n = 4;
  tab = creerTabEntier2D(n);
  do{
    system("clear");
    afficherTab(tab, n);
    deplacer(tab, n);
    ajoutTuile(tab, n);
  } while (!aGagne(tab, n)  &&  !aPerdu(tab, n));
  afficherTab(tab, n);
  if(aGagne(tab, n)){
    printf("Vous avez gagné la partie !\n");
  } else {
    if(aPerdu(tab, n)){
      printf("Vous avez perdu... Toutes les cases sont pleines\n");
    }
  }
  freeTab2D(tab, n);
  return 0;
}
