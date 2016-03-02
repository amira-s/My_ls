#include <stdlib.h>

void my_memcpy(void *dest, void *src, int size);

void my_swap(char** a, char** b, int size)
{
    char* tmp;

    tmp = malloc(size);
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void int_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
