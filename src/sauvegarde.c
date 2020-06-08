/*!
 * \file sauvegarde.c
 *
 * \author Ilias Bougrhous, Vincent Donney, Sacha Grumelart et Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 08 juin 2020
 *
 * \brief fonctions qui gère le système de sauvegarde
 *
 *
 */

#include "sauvegarde.h"

void sauvegarde(int** plateau, int taille)
{
	FILE* fichier = NULL;
	//ouverture du fichier
	fichier = fopen(NOMFICHIER, "w");
	//si l'ouverture est réussie
	if(fichier != NULL){
		//on écrit dans le fichier de sauvegarde la taille du plateau
		fprintf(fichier, "%d\n", taille);
		//On parcourt toutes les cases du plateau et on écrit la valeur de chaque case dans le fichier
		for(int i = 0; i < taille; i++){
			for(int j = 0; j < taille; j++){
				fprintf(fichier, "%d ", plateau[i][j]);
			}
		}
	}
	//cas où l'ouverture du fichier échoue
	else{
		printf("Erreur de sauvegarde !!\n");
	}
	//on ferme le fichier
	fclose(fichier);
}


int** restauration(int* taille)
{
	int** plateau;
	FILE* fichier = NULL;
	//ouverture du fichier
	fichier = fopen(NOMFICHIER, "r");
	//on teste l'ouverture du fichier
	if(fichier != NULL){
		//on récupère la taille du plateau de jeu à restaurer
		fscanf(fichier, "%d", taille);
		//on initialise le plateau de jeu à la bonne taille
		plateau = creerTabEntier2D(*taille);
		//on récupère les valeurs du plateau de jeu dans l'ordre où elles ont été écrites.
		for(int i = 0; i < *taille; i ++){
			for(int j = 0; j < *taille; j++){
				fscanf(fichier, "%d", &plateau[i][j]);
			}
		}
	}
	//cas où l'ouverture du fichier a échoué
	else{
		printf("Erreur dans la restauration de la sauvegarde !!\n");
	}
	//on ferme le fichier
	fclose(fichier);
	return(plateau);
}

int sauvegardeDispo(){
	int estDispo;
	FILE* fichier;
	estDispo = 0;
	fichier = NULL;
	//ouverture du fichier
	fichier = fopen(NOMFICHIER, "r");
	//on teste l'ouverture du fichier
	if(fichier != NULL){
      fclose(fichier);
      estDispo = 1;
  }
  return(estDispo);
}
