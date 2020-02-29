/*Bibliothèque pour gérer une unique pile d'entiers*/

#include <stdio.h>
#include "ratio.h"

extern void rpush(ratio_t *); // empiler()
extern ratio_t * rpop (void); // dépiler()
extern int rempty(void); // vide?()