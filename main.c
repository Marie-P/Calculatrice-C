#include "miniCalculatrice.h"

int main(int argc, char const *argv[])
{
	char * chaine = "(1+2)*3";
	char chainePostfixe[100]; // changer par BUFSIZ 
	infix2postfix(chaine,chainePostfixe);
	printf("%s\n", chainePostfixe);

	printf("%.3f\n",miniCalculatrice(chainePostfixe));


	return 0;
}