#include "pile.h"

// On déclare une pile de n élément (un tableau) et la variable qui représentera le haut de la pile
static int _pile[PILE_MAX],_haut = -1;

// Fonction qui empile
void push (int v){
	_pile[++_haut] = v;
}

// Fonction qui dépile
int pop(void){
	return _pile[_haut--];
}

// return true si c'est vide sinon false
extern int empty(void){
	return _haut < 0;
}