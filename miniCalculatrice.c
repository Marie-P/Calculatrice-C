#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>
#include "ratio.h"
#include "pile.h"
#include "fpile.h"
#include "rpile.h"

void infix2postfix(char * s, char * d){
	int point = 1;

	while(*s)
	{
		if((*s >= '0' && *s <= '9') || (*s == '.' && point))   // Si c'est un point et qu'il n'y a pas déjà de point 
		{
			do
			{
				if(*s == '.')
				 	point = 0;
				*d++ = *s++;

			} while((*s >= '0' && *s <= '9') || (*s == '.' && point));
			*d++ = ' ';
			if(!*s)
				break;
		}

		if((*s == ')') && !fempty()) 
		{ 
			*d++ = (char)fpop(); 
			*d++ = ' '; 
		}

		else if(*s == '+') 
		{
			fpush((int) *s);
			point = 1;
		}

		else if(*s == '-') 
		{
			fpush((int) *s);
			point = 1;
		}
		
		else if(*s == '*')
		{
			fpush((int) *s);
			point = 1;
		}

		else if(*s == '/')
		{
			fpush((int) *s);
			point = 1;
		}
		s++;
	}
	while(!fempty())
	{
		*d++ = (char)fpop();
		*d++ = ' ';
	}
	*d = '\0';
}


float calcul(char operateur)
{
	float gauche = 0.0;
	float droit = 0.0;
	ratio_t * rgauche;
	ratio_t * rdroit;

	switch(operateur)
	{

		case 43:
			droit = fpop();
			gauche = fpop();
			rdroit = rpop();
			rgauche = rpop();
			rpush(ratio_plus(rgauche,rdroit));
			ratio_delete(rgauche);ratio_delete(rdroit); 
			return gauche + droit;
		case 45:
			droit = fpop();
			gauche = fpop();
			rdroit = rpop();
			rgauche = rpop();
			rpush(ratio_moins(rgauche,rdroit));
			ratio_delete(rgauche);ratio_delete(rdroit); 
			return gauche - droit;
		case 42:
			droit = fpop();
			gauche = fpop();
			rdroit = rpop();
			rgauche = rpop();
			rpush(ratio_mul(rgauche,rdroit));
			ratio_delete(rgauche);ratio_delete(rdroit); 
			return gauche * droit;
		case 47:
			droit = fpop();
			gauche = fpop();
			rdroit = rpop();
			rgauche = rpop();
			rpush(ratio_div(rgauche,rdroit));
			ratio_delete(rgauche);ratio_delete(rdroit);
			return gauche / droit;
	}
}

float miniCalculatrice(char * s)
{
	float res = 0;

	while(*s)
	{
		if (*s == ' ') // L'espace sépare 2 nombres, donc si il y en a un on transforme le nombre en réel avant de continuer
		{
			for (int i = -3; i < 0; ++i) // On prend les 3 chiffres après la virgule
				res += pop() * pow(10, i);
		
			pop(); //On enlève le point

			for (int i = 0; !empty() ; i++) // maintenant on rajoute le nombre devant la virgule
				res += pop() * pow(10, i);
			

			fpush(res); // On ajoute le nombre à notre pile
			rpush(ratio_new((int)(res*1000),1000));
			res = 0;
		}

		else if (*s == '+' || *s == '-' || *s == '*' || *s == '/')
		{
			res = calcul(*s);
			fpush(res);
			res = 0;
			*s++; // On avance ne pour pas compter l'espace après l'opérateur
		}
		else
			push(*s - '0');
		s++;
	}


	res = fpop(); // Le dernier de la pile sera le résultat de toute celle ci
	return res;
}

int main(int argc, char const *argv[])
{
	char chaine[255]; 
	char chainePostfixe[255];
	ratio_t * r;

	gets(&chaine);

	infix2postfix(chaine,chainePostfixe);
	float result = miniCalculatrice(chainePostfixe);

	printf("%s\n", chainePostfixe);

	r = rpop();
	printf("%d / %d = ", ratio_num(r), ratio_denom(r));
	ratio_delete(r);
 	printf("%.3f\n",result);
	return 0;
}
