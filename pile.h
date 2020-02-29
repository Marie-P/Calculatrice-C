#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define PILE_MAX 256

extern void push(int v); // empiler()
extern int pop (void); // dépiler()
extern int empty(void); // vide?()