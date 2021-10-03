/*
 * main.c
 *
 *  Created on: 5 Dec 2017
 *      Author: adrien
 */


#include "tp11exo1_fonction.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
	noeud * racine = NouvNoeud('?');
	insereFG(NouvNoeud('B'), racine, 0);
	insereFG(NouvNoeud('A'), racine, 1);
	insereFD(NouvNoeud('O'), racine, 1);
	insereFG(NouvNoeud('R'), racine, 1);
	insereFD(NouvNoeud('V'), racine, 4);
	printf("Parcours préfixe : \n\t- ");
	parcoursPrefixe(racine->filsG);
	printf("\n");

	return EXIT_SUCCESS;
}
