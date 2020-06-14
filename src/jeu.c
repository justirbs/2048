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
  int choix; //le choix de l'utilisateur
  int key; //la touche du clavier sur laquelle l'utilisateur va taper
  key = 0;
  system("clear");
  printf("---Menu---\n\n ._________________.\n |                 |\n |  ~JEU DU 2048~  |\n |                 |\n ._________________.\n\n\n  Bienvenue sur 2048!  \n\n1. Règles du jeu\n2. Jouons !\n3. Quitter\n\nVotre choix?\n\n");
  //l'utilisateur fait un choix parmi les options proposées
  do{
    choix = saisirEntier();
  } while (choix != 1  &&  choix != 2 && choix != 3);
  switch(choix)
  {
    case 1 : //On affiche les règles du jeu
      system("clear");
      printf("Voici les règles du jeu : \n\nLe but du jeu est de fusionner les nombres ensemble (puissances de 2) et d’atteindre le nombre 2048.\nUne grille est constitué de 4 lignes et 4 colonnes.\nChaque cellule peut être vide ou contenir un nombre.\nA l’état initial la grille possède simplement deux carrés initialisés. \nSuivant les déplacements souhaités de l’utilisateur, les tuiles vont s’additionner ou se déplacer.\nA chaque déplacement, une tuile apparaît de manière aléatoire sur le plateau.\n\n\nAppuyez sur la touche espace pour quitter\n");
      while (key != 0x20){
        key = getkey();
      }
      menu();
      break;
    case 2 : //On lance une partie
      jouePartie();
      break;
    case 3 : //On quitte le programme
    exit(EXIT_FAILURE);
      break;
    default:
      printf("Erreur\n");
      break;
  }
}


void jouePartie(void){
  int** tab; //le plateau de jeu
  int n; //la taille du plateau
  int key; //la touche sur laquelle tape l'utilisateur
  n = 0;
  key = 0;
  //Dans le cas où il y a un fichier de sauvegarde
  if(sauvegardeDispo()){
    system("clear");
    printf("Voulez vous reprendre votre partie en cours ? (Appuyer sur la touche 'R' pour reprendre et 'I' pour ignorer)\n");
    while(key != 0x72 && key != 0x69){
      key = getkey();
    }
    if(key == 0x72){
      //on restaure la sauvegarde de la partie prédédente
      tab = restauration(&n);
    } else {
      //on commence une nouvelle partie
      n = choixTaille();
      tab = creerTabEntier2D(n);
    }
  }
  else{
    //s'il n'y a pas de sauvegarde, on commence une nouvelle partie
    system("clear");
    n = choixTaille();
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
    afficheScore(tab, n);
    freeTab2D(tab, n);
  }
}


int choixTaille(void){
  int n; //la taille choisie par l'utilisateur
  printf("Quelle taille de plateau voulez vous ?\n(le minimum jouable est 4)\n");
  do {
    n = saisirEntier();
  } while(n < 4);
  return (n);
}


void afficheScore(int** tab, int n){
  system("clear");
  afficherTab(tab, n);
  if(aGagne(tab, n)){
    printf("Vous avez gagné la partie! Bravo!\n");
  } else {
    if(aPerdu(tab, n)){
      printf("Vous avez perdu... Vous n'avez plus de déplacements possibles\n");
    }
  }
}


void ajoutTuile(int** tab, int n){
  int ligne;
  int colonne;
  srand(time(NULL)); //on initialise la fonction rand
  do{
    //on prend une valeur entière aléatoire entre 0 et n-1
    ligne = (rand()%n);
    colonne = (rand()%n);
    //il faut que la case correspondante soit vide
  }while (tab[ligne][colonne] != 0);
  do{
    //on prend une valeur entière aléatoire entre 0 et 4
    tab[ligne][colonne] = (rand()%5);
    //il faut que la valeur de la tuile soit 2 ou 4
  }while (tab[ligne][colonne] != 2  &&  tab[ligne][colonne] != 4);
}


int deplacer(int** tab, int n){
  int key; //la touche du clavier sur laquelle l'utilisateur va taper
  int valRetour; //la valeur de retour qui indique si un déplacement a été effectué ou non
  valRetour = 0;
  printf("Pour déplacer les tuiles, appuyer sur les touches Z, Q, S, et D.\n");
  do{
    key = getkey();
  }
  //tant que le joueur n'apuie pas sur Z, Q, S, D
  while(key != 0x7A && key != 0x71 && key != 0x73 && key != 0x64);
  switch(key){
    case 0x7A : // si l'utilisateurà saisi Z (haut)
      valRetour = deplacerHaut(tab, n);
      break;
    case 0x71 : // si l'utilisateurà saisi Q (gauche)
      valRetour = deplacerGauche(tab, n);
      break;
    case 0x73 : // si l'utilisateurà saisi S (bas)
      valRetour = deplacerBas(tab, n);
      break;
    case 0x64 : // si l'utilisateurà saisi D (droite)
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
  int k; //variable de parcours des cases vides
  int tmp; //variable temporaire pour échanger deux cases
  int deb; //début du parcours des cases
  int valRetour; //la valeur de retour qui indique si un déplacement a été effectué ou non
  int aFusionne; //variable qui induque si une fusion entre deux tuile a été effectuée
  valRetour = 0;
  aFusionne = 0;
  for(i=0; i<n; i++){
    deb = n-1;
    for(j=deb-1; j>=0; j--){
      if(tab[i][j] != 0){
        k=j;
        //On cherche la case vide la plus à droite
        while(k<deb && tab[i][k+1] == 0){
          k++;
        }
        //si la case suivante est égale à la tuile qu'on veut déplacer, on les fusionne
        if(k != deb && tab[i][j] == tab[i][k+1]){
          tab[i][k+1] = tab[i][k+1] + tab[i][j];
          tab[i][j] = 0;
          aFusionne = 1;
          valRetour = 1;
        }
        //sinon on pousse la tuile
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
  int k; //variable de parcours des cases vides
  int tmp; //variable temporaire pour échanger deux cases
  int deb; //début du parcours des cases
  int valRetour; //la valeur de retour qui indique si un déplacement a été effectué ou non
  int aFusionne; //variable qui induque si une fusion entre deux tuile a été effectuée
  valRetour = 0;
  aFusionne = 0;
  for(i=0; i<n; i++){
    deb = 0;
    for(j=deb+1; j<n; j++){
      if(tab[i][j] != 0){
        k=j;
        //On cherche la case vide la plus à gauche
        while(k>deb && tab[i][k-1] == 0){
          k--;
        }
        //si la case suivante est égale à la tuile qu'on veut déplacer, on les fusionne
        if(k != deb && tab[i][j] == tab[i][k-1]){
          tab[i][k-1] = tab[i][k-1] + tab[i][j];
          tab[i][j] = 0;
          aFusionne = 1;
          valRetour = 1;
        }
        //sinon on pousse la tuile
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
  int k; //variable de parcours des cases vides
  int tmp; //variable temporaire pour échanger deux cases
  int deb; //début du parcours des cases
  int valRetour; //la valeur de retour qui indique si un déplacement a été effectué ou non
  int aFusionne; //variable qui induque si une fusion entre deux tuile a été effectuée
  valRetour = 0;
  aFusionne = 0;
  for(j=0; j<n; j++){
    deb = 0;
    for(i=deb+1; i<n; i++){
      if(tab[i][j] != 0){
        k=i;
        //On cherche la case vide la plus en haut
        while(k>deb && tab[k-1][j] == 0){
          k--;
        }
        //si la case suivante est égale à la tuile qu'on veut déplacer, on les fusionne
        if(k != deb && tab[i][j] == tab[k-1][j]){
          tab[k-1][j] = tab[k-1][j] + tab[i][j];
          tab[i][j] = 0;
          aFusionne = 1;
          valRetour = 1;
        }
        //sinon on pousse la tuile
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
  int k; //variable de parcours des cases vides
  int tmp; //variable temporaire pour échanger deux cases
  int deb; //début du parcours des cases
  int valRetour; //la valeur de retour qui indique si un déplacement a été effectué ou non
  int aFusionne; //variable qui induque si une fusion entre deux tuile a été effectuée
  valRetour = 0;
  aFusionne = 0;
  for(j=0; j<n; j++){
    deb = n-1;
    for(i=deb-1; i>=0; i--){
      if(tab[i][j] != 0){
        k=i;
        //On cherche la case vide la plus en bas
        while(k<deb && tab[k+1][j] == 0){
          k++;
        }
        //si la case suivante est égale à la tuile qu'on veut déplacer, on les fusionne
        if(k != deb && tab[i][j] == tab[k+1][j]){
          tab[k+1][j] = tab[k+1][j] + tab[i][j];
          tab[i][j] = 0;
          aFusionne = 1;
          valRetour = 1;
        }
        //sinon on pousse la tuile
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
  int res; //valeur de retour : 1 si le joueur a gagné, 0 sinon
  res = 0;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
      //on gagne si une tuile vaut 2048
			if (tab[i][j] == 2048){
				res = 1;
			}
		}
	}
  return(res);
}


int aPerdu(int** tab, int n){
  int i;
	int j;
  int res; //valeur de retour : 1 si le joueur a perdu, 0 sinon
  int** copieTab; //la copie du plateau
  res = 1;
  copieTab = copieTab2D(tab, n);
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
      //l'utilisateur n'a pas perdu s'il reste au moins une tuile vide
			if (copieTab[i][j] == 0){
				res = 0;
			}
		}
	}
  //l'utilisateur n'a pas perdu s'il reste des déplacements possibles
  if (res == 1 && (deplacerBas(copieTab, n) || deplacerHaut(copieTab, n) || deplacerDroite(copieTab, n) || deplacerGauche(copieTab, n))){
    res = 0;
  }
  return(res);
}
