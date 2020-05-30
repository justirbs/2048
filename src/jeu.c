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


void deplacer(int** tab, int n){
  int direction;
  printf("Pour déplacer les tuiles, saisissez :\n1-Gauche\n3-Droite\n5-Haut\n2-Bas\n");
  do{
    direction = saisirEntier();
  } while (direction != 1  &&  direction != 2  &&  direction != 3  &&  direction != 5);
  switch(direction){
    case 1 :
      deplacerGauche(tab, n);
      break;
    case 3 :
      deplacerDroite(tab, n);
      break;
    case 5 :
      deplacerHaut(tab, n);
      break;
    case 2 :
      deplacerBas(tab, n);
      break;
    default :
      printf("erreur\n");
      break;
  }
}


void deplacerDroite(int** tab, int n){
  int i;
  int j;
  int tmp;
  int aContinue;
  for(i=0; i<n; i++){
    aContinue = 1;
    while (aContinue){
      aContinue = 0;
      for(j=n-2; j>=0; j--){
        if(tab[i][j] != 0  &&  tab[i][j+1] == 0){
          aContinue = 1;
          tmp = tab[i][j];
          tab[i][j] = tab[i][j+1];
          tab[i][j+1] = tmp;
        } else {
          if(tab[i][j] == tab[i][j+1]  &&  tab[i][j] != 0){
            aContinue = 1;
            tab[i][j+1] = tab[i][j+1] + tab[i][j];
            tab[i][j] = 0;
          }
        }
      }
    }
  }
}


void deplacerGauche(int** tab, int n){
  int i;
  int j;
  int tmp;
  int aContinue;
  for(i=0; i<n; i++){
    aContinue = 1;
    while (aContinue){
      aContinue = 0;
      for(j=1; j<n; j++){
        if(tab[i][j] != 0  &&  tab[i][j-1] == 0){
          aContinue = 1;
          tmp = tab[i][j];
          tab[i][j] = tab[i][j-1];
          tab[i][j-1] = tmp;
        } else {
          if(tab[i][j] == tab[i][j-1]  &&  tab[i][j] != 0){
            aContinue = 1;
            tab[i][j-1] = tab[i][j-1] + tab[i][j];
            tab[i][j] = 0;
          }
        }
      }
    }
  }
}


void deplacerHaut(int** tab, int n){
  int i;
  int j;
  int tmp;
  int aContinue;
  for(j=0; j<n; j++){
    aContinue = 1;
    while (aContinue){
      aContinue = 0;
      for(i=1; i<n; i++){
        if(tab[i][j] != 0  &&  tab[i-1][j] == 0){
          aContinue = 1;
          tmp = tab[i][j];
          tab[i][j] = tab[i-1][j];
          tab[i-1][j] = tmp;
        } else {
          if(tab[i][j] == tab[i-1][j]  &&  tab[i][j] != 0){
            aContinue = 1;
            tab[i-1][j] = tab[i-1][j] + tab[i][j];
            tab[i][j] = 0;
          }
        }
      }
    }
  }
}


void deplacerBas(int** tab, int n){
  int i;
  int j;
  int tmp;
  int aContinue;
  for(j=0; j<n; j++){
    aContinue = 1;
    while (aContinue){
      aContinue = 0;
      for(i=n-2; i>=0; i--){
        if(tab[i][j] != 0  &&  tab[i+1][j] == 0){
          aContinue = 1;
          tmp = tab[i][j];
          tab[i][j] = tab[i+1][j];
          tab[i+1][j] = tmp;
        } else {
          if(tab[i][j] == tab[i+1][j]  &&  tab[i][j] != 0){
            aContinue = 1;
            tab[i+1][j] = tab[i+1][j] + tab[i][j];
            tab[i][j] = 0;
          }
        }
      }
    }
  }
}
