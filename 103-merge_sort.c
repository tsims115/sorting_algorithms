#include <stdio.h>
#include "sort.h"

/**
 * split_array - splits array
 *
 * @array: array to sort
 * @newArray: array to sort to
 * @size: size of the arary
 * @sp: starting point
 */


void split_array(int *array, int *newArray, size_t size, int *sp)
{
	size_t i;
	size_t left_size = size / 2;
	size_t right_size = size - left_size;
	int *left_array = array;
	int *right_array = array + left_size;

	(void)newArray;
	if (left_size > 1)
		split_array(left_array, newArray, left_size, sp);
	if (right_size > 1)
		split_array(right_array, newArray, right_size, sp);
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
	*sp += 1;
}

/**
 * merge_sort - merge sorts the given int array
 * @array: array to sort
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int start_point = 0;
	int *sp = &start_point;
	int *newArray = malloc(sizeof(int) * size);

	split_array(array, newArray, size, sp);
	free(newArray);
}
