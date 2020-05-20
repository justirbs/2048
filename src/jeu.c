/*!
 * \file jeu.c
 *
 * \author Ilias Bougrhous, Vincent Donney, Sacha Grumelart et Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 11 mai 2020
 *
 * \brief fonctions relatives au déroulement d'une partie
 *
 *
 */

// Inclusion des librairies
#include "jeu.h"


// Codes des fonctions

void ajoutTuile(int** tab, int n){
  int ligne;
  int colonne;
  srand(time(NULL)); //on initialise la fonction rand
  do{
    ligne = (rand()%n);
    colonne = (rand()%n);
  }while (tab[ligne][colonne] != 0);
  do{
    tab[ligne][colonne] = (rand()%5);
  }while (tab[ligne][colonne] != 2  &&  tab[ligne][colonne] != 4);
}
