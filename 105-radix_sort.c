#include "sort.h"
#include <stdio.h>


/**
 * count_sort: count sorts the array by smallest number first
 * @array
 * 
 */

void count_sort(int *array, int *array_copy, int *new_array, size_t size)
{
	size_t j;
	int i;
	int idx = 0;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (array_copy[j] % 10 == i)
			{
				new_array[idx] = array[j];
				idx++;
			}
		}
	}
}

/**
 * radix_sort - sortsd using radix method
 *
 * @array: array to sort
 * @size: size of the array
 */

void radix_sort(int *array, size_t size)
{
	size_t flag = 0;
	size_t i, j;
	int max = 0;
	size_t degree = 0;
	int *array_copy = malloc(sizeof(int) * size);
	int *new_array = malloc(sizeof(int) * size);

	if (size == 0)
	{
		return;
	}
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
		array_copy[i] = array[i];
	}
	while (max > 10)
	{
		max /= 10;
		degree++;
	}

	count_sort(array, array_copy, new_array, size);
	while (flag <= degree)
	{
		
		flag++;
		for (i = 0; i < size; i++)
		{
			array[i] = new_array[i];
			array_copy[i] = new_array[i];
		}
		for (i = 0; i < flag; i++)
			for(j = 0; j < size; j++)
				array_copy[j] /= 10;
		count_sort(array, array_copy, new_array, size);
		print_array(array, size);
	}
	free(array_copy);
	free(new_array);
}
