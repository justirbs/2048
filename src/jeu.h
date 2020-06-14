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
#include "sauvegarde.h"
#include <string.h>


/**
 * \fn void menu(void)
 *
 * \author Grumelart Sacha <grumelarts@eisti.eu>
 * \version 0.1
 * \date 10 juin 2020
 *
 * \brief procédure d'affichage du menu du jeu
 *
 *
 */
void menu(void);



/**
 * \fn void jouePartie(void)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 12 juin 2020
 *
 * \brief permet de lancer une partie
 *
 *
 */
void jouePartie(void);

/**
 * \fn int choixTaille(void)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 12 juin 2020
 *
 * \brief permet de choisir la taille du plateau
 *
 *
 * \return la taille du plateau
 *
 */
int choixTaille(void);


/**
 * \fn void afficheScore(int** tab, int n)
 *
 * \author Sacha Grumelart <grumelarts@eisti.eu>
 * \version 0.1
 * \date 12 juin 2020
 *
 * \brief permet d'afficher si le joueur a perdu ou gagné
 *
 *
 * \param tab le tableau à modifier
 * \param n la taille du tableau
 *
 */
void afficheScore(int** tab, int n);



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
 *
 */
void ajoutTuile(int** tab, int n);


/**
 * \fn int deplacer(int** tab, int n)
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
 * \return 1 si un déplacement a été effectué, 0 sinon
 *
 */
int deplacer(int** tab, int n);


/**
 * \fn int deplacerDroite(int** tab, int n)
 *
 * \author Vincent Donney <donneyvinc@eisti.eu>
 * \version 0.1
 * \date 30 mai 2020
 *
 * \brief permet de déplacer toutes les tuiles vers la doite
 *
 *
 * \param tab le tableau à modifier
 * \param n la taille du tableau
 * \return 1 si un déplacement a été effectué, 0 sinon
 *
 */
int deplacerDroite(int** tab, int n);


/**
 * \fn int deplacerGauche(int** tab, int n)
 *
 * \author Vincent Donney <donneyvinc@eisti.eu>
 * \version 0.1
 * \date 30 mai 2020
 *
 * \brief permet de déplacer toutes les tuiles vers la gauche
 *
 *
 * \param tab le tableau à modifier
 * \param n la taille du tableau
 * \return 1 si un déplacement a été effectué, 0 sinon
 *
 */
int deplacerGauche(int** tab, int n);


/**
 * \fn int deplacerHaut(int** tab, int n)
 *
 * \author Vincent Donney <donneyvinc@eisti.eu>
 * \version 0.1
 * \date 30 mai 2020
 *
 * \brief permet de déplacer toutes les tuiles vers en haut
 *
 *
 * \param tab le tableau à modifier
 * \param n la taille du tableau
 * \return 1 si un déplacement a été effectué, 0 sinon
 *
 */
int deplacerHaut(int** tab, int n);


/**
 * \fn int deplacerBas(int** tab, int n)
 *
 * \author Vincent Donney <donneyvinc@eisti.eu>
 * \version 0.1
 * \date 30 mai 2020
 *
 * \brief permet de déplacer toutes les tuiles vers en bas
 *
 *
 * \param tab le tableau à modifier
 * \param n la taille du tableau
 * \return 1 si un déplacement a été effectué, 0 sinon
 *
 */
int deplacerBas(int** tab, int n);


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
