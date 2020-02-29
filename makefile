#NOM : BWELLE Marie-Paule
# NUMERO : 17802001
# EMAIL : mpbwelle@gmail.com

CC=gcc
CFLAGS=-Wall
#OBJ=$(SRC:.c=.o)

miniCalculatrice: miniCalculatrice.o pile.o rpile.o fpile.o ratio.o miniCalculatrice.h pile.h rpile.h fpile.h -lm
	$(CC) -o $@ $^

%.o:%.c
	$(CC) -o $@  -c $< $(CFLAGS)

clean:
	rm *.o *~ core


#gcc miniCalculatrice.c miniCalculatrice.h pile.c fpile.c fpile.h pile.h rpile.c rpile.h ratio.c ratio.h -lm -o miniCalculatrice