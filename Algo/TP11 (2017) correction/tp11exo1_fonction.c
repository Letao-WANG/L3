/*
 * fonction.c
 *
 *  Created on: 5 Dec 2017
 *      Author: adrien
 */


#define FONCTION_HEADER

#include "tp11exo1_fonction.h"

#include <stdio.h>
#include <stdlib.h>

noeud * NouvNoeud(char cara){
	noeud * tmpNoeud = (noeud *)malloc(sizeof(noeud));
	static int numero = 0;
	if (!tmpNoeud){
		printf("Erreur d'allocation dans la fonction NouvNoeud");
		exit(EXIT_FAILURE);
	}
	tmpNoeud->car = cara;
	tmpNoeud->numero = numero;
	tmpNoeud->filsG = tmpNoeud->filsD = NULL;
	numero++;
	return tmpNoeud;
}
noeud * RechercheNoeud(noeud * n, int numNoeud){
	noeud * tmpNoeud;
	if (n == NULL)
		return NULL;
	if(n->numero == numNoeud)
		return n;
	tmpNoeud = RechercheNoeud(n->filsG, numNoeud);
	if(tmpNoeud != NULL)
		return tmpNoeud;
	return RechercheNoeud(n->filsD, numNoeud);
}

void insereFG(noeud * nouveauNoeud, noeud * noeudRacine, int position){
	noeud * nouveauRacine = RechercheNoeud(noeudRacine, position);
	nouveauNoeud->filsG = nouveauRacine->filsG;
	nouveauRacine->filsG = nouveauNoeud;

}
void insereFD(noeud * nouveauNoeud, noeud * noeudRacine, int position){
	noeud * nouveauRacine = RechercheNoeud(noeudRacine, position);
	nouveauNoeud->filsD = nouveauRacine->filsD;
	nouveauRacine->filsD = nouveauNoeud;
}

void parcoursPrefixe(noeud * racine){
	if (racine != NULL){
		printf("%c", racine->car);
		parcoursPrefixe(racine->filsG);
		parcoursPrefixe(racine->filsD);
	}
}


