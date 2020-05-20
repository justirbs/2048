/*!
 * \file tableau.h
 *
 * \author Ilias Bougrhous, Vincent Donney, Sacha Grumelart et Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 11 mai 2019
 *
 * \brief header des fonctions pour créer des tableaux
 *
 *
 */



#ifndef __TABLEAU_H__
#define __TABLEAU_H__

 // Inclusion des entêtes de librairies
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * \fn int** creerTabEntier2D(int n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 20 mai 2020
 *
 * \brief permet de créer un tableau à deux dimensions
 *
 * \param n la taille du tableau
 * \return tab l'adresse de la première case du tableau crée
 *
 *
 */
int** creerTabEntier2D(int n);

/**
 * \fn void afficherTab(int** tab, int n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 20 mai 2020
 *
 * \brief permet d'afficher un tableau à une dimension
 *
 *
 * \param tab le tableau à afficher
 * \param n la taille du tableau
 *
 */
void afficherTab(int** tab, int n);

/**
 * \fn void freeTab2D(int** tab, int n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 20 mai 2020
 *
 * \brief permet de free des tableaux à deux dimenssions
 *
 *
 * \param tab le tableau à supprimer
 * \param n la taille du tableau
 * \return le tableau agrandi
 *
 */
void freeTab2D(int** tab, int n);




#endif
