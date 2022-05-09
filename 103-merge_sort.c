#include <stdio.h>
#include "sort.h"

/**
 * split_array - splits array
 *
 * @array: array to sort
 * @newArray: array to sort to
 * @size: size of the arary
 */


void split_array(int *array, int *newArray, size_t size)
{
	size_t i;
	size_t left_size = size / 2;
	size_t right_size = size - left_size;
	int *left_array = array;
	int *right_array = array + left_size;

	(void)newArray;
	if (left_size > 1)
		merge_sort(left_array, left_size);
	if (right_size > 1)
		merge_sort(right_array, right_size);
	printf("Merging...\n");
	printf("[left]: ");
	for (i = 0; i < left_size; i++)
		printf("%d ", left_array[i]);
	printf("\n");
	printf("[right]: ");
	for (i = 0; i < right_size; i++)
		printf("%d ", right_array[i]);
	printf("\n");
	printf("[Done]: ");
	for (i = 0; i < right_size + left_size; i++)
		printf("%d ", left_array[i]);
	printf("\n");
}

/**
 * merge_sort - merge sorts the given int array
 * @array: array to sort
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *newArray = malloc(sizeof(int) * size);

	split_array(array, newArray, size);
	free(newArray);
}
