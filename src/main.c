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
#include "sauvegarde.h"
#include <string.h>

//Code de la fonction

int main(int argc, char const *argv[]) {
  int** tab;
  int n;
  int key;
  n = 0;
  key=0;
  //si il a un fichier de sauvegarde
  if(sauvegardeDispo()){
    system("clear");
    printf("Voulez vous reprendre votre partie en cour ? (Appuyer sur la touche 'R' pour reprendre et 'I' pour ignorer)\n");
    while(key != 0x72 && key != 0x69){
      key = getkey();
    }

    if(key == 0x72){
      tab = restauration(&n);
    } else {
      n = 4;
      tab = creerTabEntier2D(n);
    }
  }
  else{
    n = 4;
    tab = creerTabEntier2D(n);
  }
  if(n>0){
    do{
      system("clear");
      afficherTab(tab, n);
      //faire jouer le joueur
      deplacer(tab, n);
      //faire apparaite la nouvelle tuile
      ajoutTuile(tab, n);
      //sauvegarder l'état actuel de la partie
      sauvegarde(tab, n);
    } while (!aGagne(tab, n)  &&  !aPerdu(tab, n));
    remove(NOMFICHIER);
    if(aGagne(tab, n)){
      printf("Vous avez gagné la partie !\n");
    } else {
      if(aPerdu(tab, n)){
        printf("Vous avez perdu... Toutes les cases sont pleines\n");
      }
    }
    freeTab2D(tab, n);
  }
  return 0;
}
