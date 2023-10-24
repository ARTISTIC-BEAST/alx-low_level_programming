#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

int main(void)
{
    int *array = NULL;
    size_t size = 0;

    printf("Found %d at index: %d\n", 0, advanced_binary(array, size, 0));
    return (EXIT_SUCCESS);
}

