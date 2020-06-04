/*!
 * \file jeu.h
 *
 * \author Ilias Bougrhous, Vincent Donney, Sacha Grumelart et Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 11 mai 2020
 *
 * \brief header des fonctions relatives au déroulement d'une partie de jeu
 *
 *
 */

#ifndef __JEU_H__
#define __JEU_H__

// Inclusion des librairies
#include "tableau.h"

/**
 * \fn void ajoutTuile(int** tab, int n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 20 mai 2020
 *
 * \brief permet d'ajouter aléatoirement une tuile
 *
 *
 * \param tab le tableau à modifier
 * \param n la taille du tableau
 * \return le tableau agrandi
 *
 */
void ajoutTuile(int** tab, int n);


/**
 * \fn void deplacer(int** tab, int n)
 *
 * \author Vincent Donney <donneyvinc@eisti.eu>
 * \version 0.1
 * \date 30 mai 2020
 *
 * \brief permet de déplacer toutes les tuiles dans une direction
 *
 *
 * \param tab le tableau à modifier
 * \param n la taille du tableau
 *
 */
void deplacer(int** tab, int n);


/**
 * \fn void deplacerDroite(int** tab, int n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 30 mai 2020
 *
 * \brief permet de déplacer toutes les tuiles vers la doite
 *
 *
 * \param tab le tableau à modifier
 * \param n la taille du tableau
 *
 */
void deplacerDroite(int** tab, int n);


/**
 * \fn void deplacerGauche(int** tab, int n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 30 mai 2020
 *
 * \brief permet de déplacer toutes les tuiles vers la gauche
 *
 *
 * \param tab le tableau à modifier
 * \param n la taille du tableau
 *
 */
void deplacerGauche(int** tab, int n);


/**
 * \fn void deplacerHaut(int** tab, int n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 30 mai 2020
 *
 * \brief permet de déplacer toutes les tuiles vers en haut
 *
 *
 * \param tab le tableau à modifier
 * \param n la taille du tableau
 *
 */
void deplacerHaut(int** tab, int n);


/**
 * \fn void deplacerBas(int** tab, int n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 30 mai 2020
 *
 * \brief permet de déplacer toutes les tuiles vers en bas
 *
 *
 * \param tab le tableau à modifier
 * \param n la taille du tableau
 *
 */
void deplacerBas(int** tab, int n);


/**
 * \fn int aGagne(int** tab, int n)
 *
 * \author Sacha Grumelart <grumelarts@eisti.eu>
 * \version 0.1
 * \date 31 mai 2020
 *
 * \brief permet de déterminer si l'utilisateur a gagné la partie
 *
 *
 * \param tab le plateau de jeu
 * \param n la taille du tableau
 * \return 1 si le joueur a gagné, 0 sinon
 *
 */
int aGagne(int** tab, int n);


/**
 * \fn int aPerdu(int** tab, int n)
 *
 * \author Sacha Grumelart <grumelarts@eisti.eu>
 * \version 0.1
 * \date 31 mai 2020
 *
 * \brief permet de déterminer si l'utilisateur a perdu la partie
 *
 *
 * \param tab le plateau de jeu
 * \param n la taille du tableau
 * \return 1 si le joueur a perdu, 0 sinon
 *
 */
int aPerdu(int** tab, int n);


#endif
