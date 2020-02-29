#include "fpile.h"
#define N 256

// On déclare une pile de n élément (un tableau) et la variable qui représentera le haut de la pile
static float _pile[N];
static int _haut = -1;

// Fonction qui empile
void fpush (float v){
	_pile[++_haut] = v;
}

// Fonction qui dépile
float fpop(void){
	return _pile[_haut--];
}

// return true si c'est vide sinon false
extern float fempty(void){
	return _haut < 0;
}