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

void menu(void){
  int choix;
  int key;
  key = -1;
  system("clear");
  printf("---Menu---\n\n ._________________.\n |                 |\n |  ~JEU DU 2048~  |\n |                 |\n ._________________.\n\n\n  Bienvenue sur 2048!  \n\n1. Règles du jeu\n2. Jouons !\n3. Quitter\n\nVotre choix?\n\n");
  do{
    choix = saisirEntier();
  } while (choix != 1  &&  choix != 2 && choix != 3);
  switch(choix)
  {
    case 1 :
      system("clear");
      printf("Voici les règles du jeu : \n\nLe but est d'atteindre une tuile de valeur 2048. \n" "Pour cela, il faut assembler les tuiles de même valeur en les faisant glisser à droit, à gauche, en bas ou à droite \n\n\nAppuyer sur la touche espace pour quitter\n");
      while (key != 0x20){
        key = getkey();
      }
      menu();
      break;
    case 2 :
      jouePartie();
      break;
    case 3 :
    exit(EXIT_FAILURE);
      break;
    default:
      printf("Erreur\n");
      break;
  }
}


void jouePartie(void){
  int** tab;
  int n;
  int key;
  n = 0;
  key=0;
  //si il a un fichier de sauvegarde
  if(sauvegardeDispo()){
    system("clear");
    printf("Voulez vous reprendre votre partie en cours ? (Appuyer sur la touche 'R' pour reprendre et 'I' pour ignorer)\n");
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
      if(deplacer(tab, n)){
        //faire apparaite la nouvelle tuile
        ajoutTuile(tab, n);
        //sauvegarder l'état actuel de la partie
        sauvegarde(tab, n);
      }
    } while (!aGagne(tab, n)  &&  !aPerdu(tab, n));
    remove(NOMFICHIER);
    system("clear");
    afficherTab(tab, n);
    if(aGagne(tab, n)){
      printf("Vous avez gagné la partie !\n");
    } else {
      if(aPerdu(tab, n)){
        printf("Vous avez perdu... Toutes les cases sont pleines\n");
      }
    }
    freeTab2D(tab, n);
  }
}


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


int deplacer(int** tab, int n){
  int key;
  int valRetour;
  valRetour = 0;
  printf("Pour déplacer les tuiles, appuyer sur les touches Z, Q, S, et D.\n");
  do{
    key = getkey();
  }
  //tant que le joueur n'apuie pas sur Z, Q, S, D
  while(key != 0x7A && key != 0x71 && key != 0x73 && key != 0x64);

  switch(key){
    case 0x7A : // z
      valRetour = deplacerHaut(tab, n);
      break;
    case 0x71 : // q
      valRetour = deplacerGauche(tab, n);
      break;
    case 0x73 : // s
      valRetour = deplacerBas(tab, n);
      break;
    case 0x64 : // d
      valRetour = deplacerDroite(tab, n);
      break;
    default :
      printf("erreur\n");
      break;
  }
  return(valRetour);
}


int deplacerDroite(int** tab, int n){
  int i;
  int j;
  int k;
  int tmp;
  int deb;
  int valRetour;
  int aFusionne;
  valRetour = 0;
  aFusionne = 0;
  for(i=0; i<n; i++){
    deb = n-1;
    for(j=deb-1; j>=0; j--){
      if(tab[i][j] != 0){
        k=j;
        while(k<deb && tab[i][k+1] == 0){
          k++;
        }
        if(k != deb && tab[i][j] == tab[i][k+1]){
          tab[i][k+1] = tab[i][k+1] + tab[i][j];
          tab[i][j] = 0;
          aFusionne = 1;
          valRetour = 1;
        }
        else{
          if(k!=j){
            tmp = tab[i][j];
            tab[i][j] = tab[i][k];
            tab[i][k] = tmp;
            valRetour = 1;
          }
        }
      }
      if(aFusionne)deb = k;
      aFusionne = 0;
    }
  }
  return(valRetour);
}


int deplacerGauche(int** tab, int n){
  int i;
  int j;
  int k;
  int tmp;
  int deb;
  int valRetour;
  int aFusionne;
  valRetour = 0;
  aFusionne = 0;
  for(i=0; i<n; i++){
    deb = 0;
    for(j=deb+1; j<n; j++){
      if(tab[i][j] != 0){
        k=j;
        while(k>deb && tab[i][k-1] == 0){
          k--;
        }
          if(k != deb && tab[i][j] == tab[i][k-1]){
            tab[i][k-1] = tab[i][k-1] + tab[i][j];
            tab[i][j] = 0;
            aFusionne = 1;
            valRetour = 1;
          }
          else{
            if(k!=j){
              tmp = tab[i][j];
              tab[i][j] = tab[i][k];
              tab[i][k] = tmp;
              valRetour = 1;
            }
          }
      }
      if(aFusionne)deb = k;
      aFusionne = 0;
    }
  }
  return(valRetour);
}


int deplacerHaut(int** tab, int n){
  int i;
  int j;
  int k;
  int tmp;
  int deb;
  int valRetour;
  int aFusionne;
  valRetour = 0;
  aFusionne = 0;
  for(j=0; j<n; j++){
    deb = 0;
    for(i=deb+1; i<n; i++){
      if(tab[i][j] != 0){
        k=i;
        while(k>deb && tab[k-1][j] == 0){
          k--;
        }
          if(k != deb && tab[i][j] == tab[k-1][j]){
            tab[k-1][j] = tab[k-1][j] + tab[i][j];
            tab[i][j] = 0;
            aFusionne = 1;
            valRetour = 1;
          }
          else{
            if(k!=i){
              tmp = tab[i][j];
              tab[i][j] = tab[k][j];
              tab[k][j] = tmp;
              valRetour = 1;
            }
          }
      }
      if(aFusionne)deb = k;
      aFusionne = 0;
    }
  }
  return(valRetour);
}


int deplacerBas(int** tab, int n){
  int i;
  int j;
  int k;
  int tmp;
  int deb;
  int valRetour;
  int aFusionne;
  valRetour = 0;
  aFusionne = 0;
  for(j=0; j<n; j++){
    deb = n-1;
    for(i=deb-1; i>=0; i--){
      if(tab[i][j] != 0){
        k=i;
        while(k<deb && tab[k+1][j] == 0){
          k++;
        }
        if(k != deb && tab[i][j] == tab[k+1][j]){
          tab[k+1][j] = tab[k+1][j] + tab[i][j];
          tab[i][j] = 0;
          aFusionne = 1;
          valRetour = 1;
        }
        else{
          if(k!=i){
            tmp = tab[i][j];
            tab[i][j] = tab[k][j];
            tab[k][j] = tmp;
            valRetour = 1;
          }
        }
      }
      if(aFusionne)deb = k;
      aFusionne = 0;
    }
  }
  return(valRetour);
}


int aGagne(int** tab, int n){
  int i;
	int j;
  int res;
  res = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (tab[i][j] == 2048)
			{
				res = 1;
			}
		}
	}
  return(res);
}


int aPerdu(int** tab, int n){
  int i;
	int j;
  int res;
  res = 1;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (tab[i][j] == 0)
			{
				res = 0;
			}
		}
	}
  return(res);
}
