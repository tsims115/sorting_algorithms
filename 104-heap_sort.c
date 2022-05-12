#include "sort.h"
#include <stdio.h>


/**
 * heap_sort - heap sorts an array
 *
 * @array: array to sort
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i = 0;

	if (size != 0)
		for (i = 0; i < size - 1; i++)
			print_array(array, size);
}