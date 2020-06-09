/*!
 * \file saisie.h
 *
 * \author Ilias Bougrhous, Vincent Donney, Sacha Grumelart et Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 30 mai 2020
 *
 * \brief définition des méthodes de saisie
 *
 *
 */

 // Inclusion des entêtes de librairies
#include "saisie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>


// Codes des fonctions

int saisirEntier(void)
{
  int int_nbrSaisi; //le nombre qui sera saisie
  while (!scanf("%d", &int_nbrSaisi)) {
    //on vide le buffer pour eviter une boucle infini
    viderBuffer();
    printf("Erreur lors de la saisie ! Veuillez entrer un entier :");
  }
  return(int_nbrSaisi);
}

void viderBuffer(void)
{
  char char_saisie; //le caracère courant dans le buffer
  scanf("%c", &char_saisie);
  while (char_saisie!='\n') {
    scanf("%c", &char_saisie);
  }
}

int getkey() {
  int character;
  struct termios orig_term_attr;
  struct termios new_term_attr;

  /* set the terminal to raw mode */
  tcgetattr(fileno(stdin), &orig_term_attr);
  memcpy(&new_term_attr, &orig_term_attr, sizeof(struct termios));
  new_term_attr.c_lflag &= ~(ECHO|ICANON);
  new_term_attr.c_cc[VTIME] = 0;
  new_term_attr.c_cc[VMIN] = 0;
  tcsetattr(fileno(stdin), TCSANOW, &new_term_attr);

  /* read a character from the stdin stream without blocking */
  /*   returns EOF (-1) if no character is available */
  character = fgetc(stdin);

  /* restore the original terminal attributes */
  tcsetattr(fileno(stdin), TCSANOW, &orig_term_attr);

  return character;
}
