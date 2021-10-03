/*
 * fonction.h
 *
 *  Created on: 5 Dec 2017
 *      Author: adrien
 */

#ifndef FONCTIONS_H_
	#ifdef FONCTIONS_HEADER
		#define FONCTIONS
	#else
		#define FONCTIONS extern
	#endif
	#define FONCTIONS_H_

	typedef struct noeud{
		char car;
		int numero;
		struct noeud * filsG, * filsD;
	}noeud;

	FONCTIONS noeud * NouvNoeud(char);
	FONCTIONS noeud * RechercheNoeud(noeud *, int);
	FONCTIONS void insereFG(noeud *, noeud *, int);
	FONCTIONS void insereFD(noeud *, noeud *, int);
	FONCTIONS void parcoursPrefixe(noeud *);




#endif /* FONCTIONS_H_ */
