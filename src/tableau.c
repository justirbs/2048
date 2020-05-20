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
    for(j=0; j<n; j++){
      tab[i][j] = 0;
    }
  }
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
      printf("----");
    }
    printf("-\n|");
    for(j=0; j<n; j++){
      if(tab[i][j] == 0){
        printf("   |");
      } else {
        printf(" %d |", tab[i][j]);
      }
    }
    printf("\n");
  }
  for(k=0; k<n; k++){
    printf("----");
  }
  printf("-\n");
}
