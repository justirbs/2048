/*!
 * \file tableau.c
 *
 * \author Ilias Bougrhous, Vincent Donney, Sacha Grumelart et Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 11 mai 2019
 *
 * \brief fonctions pour créer des tableau
 *
 *
 */

//Inclusion des entêtes de librairies
#include"tableau.h"


// Codes des fonctions

int** creerTabEntier2D(int n)
{
  int** tab; //tableau d'entiers
  int i; //iterrateur de boucle
  int j; //iterrateur de boucle
  tab = malloc(n*sizeof(int*));
  if(tab==NULL){
    fprintf(stderr, "problème d'alloc\n");
    exit(1);
  }
  for(i=0; i<n; i++){
    tab[i] = malloc(n*sizeof(int));
    if(tab==NULL){
    fprintf(stderr, "problème d'alloc\n");
    exit(1);
    }
    // toutes les tuiles sont vides
    for(j=0; j<n; j++){
      tab[i][j] = 0;
    }
  }
  // deux tuile sont initialement placé de façon aléatoire sur le plateau
  ajoutTuile(tab, n);
  ajoutTuile(tab, n);
  return(tab);
}


void freeTab2D(int** tab, int n){
  int i; //iterrateur de boucle
  for(i=0; i<n; i++){
    free(tab[i]);
  }
  free(tab);
}


void afficherTab(int** tab, int n){
  int i; //iterrateur de boucle
  int j; //iterrateur de boucle
  int k; //iterrateur de boucle
  for(i=0; i<n; i++){
    for(k=0; k<n; k++){
      printf("-------");
    }
    printf("-\n|");
    for(j=0; j<n; j++){
      if(tab[i][j] == 0){
        printf("      |");
      } else {
        if(tab[i][j] < 10){
          printf("   %d  |", tab[i][j]);
        } else {
          if(tab[i][j] < 100){
            printf("  %d  |", tab[i][j]);
          } else {
            if(tab[i][j] < 1000){
              printf("  %d |", tab[i][j]);
            } else {
              printf(" %d |", tab[i][j]);
            }
          }
        }
      }
    }
    printf("\n");
  }
  for(k=0; k<n; k++){
    printf("-------");
  }
  printf("-\n");
}

int** copieTab2D(int** tab1, int n){
  int i;
  int j;
  int** tab2; //la copie
  tab2 = creerTabEntier2D(n);
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      tab2[i][j] = tab1[i][j];
    }
  }
  return(tab2);
}
