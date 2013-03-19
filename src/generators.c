/*
 ============================================================================
 Name        : generators.c
 Author      : Nikolay
 Version     :
 Copyright   : Copyright 2013
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

struct iterator {
	int started;
	jmp_buf b;
};

typedef struct iterator iterator_t;

#define YIELD(i) it_yield(it, (i));

void it_yield(iterator_t it, int value)
{
	if (!it.started)
	{
		if (!setjmp(it.b)) {

		}
	}
}

int it_next(iterator_t it)
{
	return 0;
}

void it_done(iterator_t it)
{
	//
}

///////////////////////////////

iterator_t mygen()
{
	int i;
	iterator_t it;
	if (setjmp(&it) == 0) {
		return it;
	}

	for (i = 0; i < 1; i++) {
		puts("Line ");
		YIELD(i);
	}

	return it;
}


void driver()
{
	iterator_t it = mygen();
	int i;

	puts("Getting first");
	i = it_next(it);

	puts("Getting second");
	i = it_next(it);

	it_done(it);
}


int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
