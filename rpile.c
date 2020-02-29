/*Pile de ratio*/

#include "rpile.h"
#include "ratio.h"
#define N 256

// On déclare une pile de n élément (un tableau) et la variable qui représentera le haut de la pile
static ratio_t * _pile[N];
static int _haut = -1;

// Fonction qui empile
void rpush (ratio_t * v){
	_pile[++_haut] = v;
}

// Fonction qui dépile
ratio_t * rpop(void){
	return _pile[_haut--];
}

// return true si c'est vide sinon false
extern int rempty(void){
	return _haut < 0;
}