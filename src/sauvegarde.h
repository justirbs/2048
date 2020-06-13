/*!
 * \file sauvegarde.h
 *
 * \author Ilias Bougrhous, Vincent Donney, Sacha Grumelart et Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 08 juin 2020
 *
 * \brief header des fonctions qui gère le système de sauvegarde
 *
 *
 */

#ifndef __SAUVEGARDE_H__
#define __SAUVEGARDE_H__

#define NOMFICHIER "sauvegarde.txt"

#include <stdio.h>
#include <stdlib.h>
#include "tableau.h"

/**
 * \fn void sauvegarde(int** plateau, int taille)
 *
 * \author Ilias Bougrhous <bougrhousi@eisti.eu>
 * \version 0.1
 * \date 08 juin 2020
 *
 * \brief permet de sauvegarder un plateau dans un fichier
 *
 *
 * \param plateau le plateau a sauvegardé
 * \param taille la taille du plateau
 *
 */
void sauvegarde(int** plateau, int taille);

/**
 * \fn int** restauration(int* taille)
 *
 * \author Ilias Bougrhous <bougrhousi@eisti.eu>
 * \version 0.1
 * \date 08 juin 2020
 *
 * \brief permet de restaurer un fichier en plateau
 *
 *
 * \param taille la taille du plateau
 * \return le plateau restauré
 *
 */
int** restauration(int* taille);

/**
 * \fn int sauvegardeDispo(void)
 *
 * \author Ilias Bougrhous <bougrhousi@eisti.eu>
 * \version 0.1
 * \date 08 juin 2020
 *
 * \brief permet de savoir si une sauvegarde est disponible ou non
 *
 *
 * \return le plateau restauré
 *
 */
int sauvegardeDispo(void);

#endif
