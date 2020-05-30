/*!
 * \file saisie.h
 *
 * \author Ilias Bougrhous, Vincent Donney, Sacha Grumelart et Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 30 mai 2020
 *
 * \brief déclaration des méthodes de saisie
 *
 *
 */

#ifndef __SAISIE_H__
#define __SAISIE_H__
#include <stdio.h>
#include <stdlib.h>


/**
 *\fn int saisirEntier(void)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 30 mai 2020
 *
 *\brief vérifie la saisie d'un entier
 *
 *
 *\return l'entier saisi
 *
 */
int saisirEntier(void);

/**
 *\fn void viderBuffer(void)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 30 mai 2020
 *
 *\brief vide le buffer
 *
 *
 */
void viderBuffer(void);

#endif
