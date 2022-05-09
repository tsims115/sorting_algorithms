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
	{
		if (i == left_size - 1)
			printf("%d", left_array[i]);
		else
			printf("%d, ", left_array[i]);
	}
	printf("\n");
	printf("[right]: ");
	for (i = 0; i < right_size; i++)
	{
		if (i == right_size - 1)
			printf("%d", right_array[i]);
		else
			printf("%d, ", right_array[i]);
	}
	printf("\n");
	printf("[Done]: ");
	for (i = 0; i < right_size + left_size; i++)
		if (i == right_size + left_size - 1)
			printf("%d", left_array[i]);
		else
			printf("%d, ", left_array[i]);
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
	int tmp;
	int start_point = 0;
	int *sp = &start_point;
	int *newArray = malloc(sizeof(int) * size);

	if (size > 1)
	{
		if (size == 2)
		{
			if (array[1] < array[0])
			{
				printf("Merging...\n[left]: %d\n", array[0]);
				printf("[Right]: %d\n", array[1]);
				tmp = array[1];
				array[1] = array[0];
				array[0] = tmp;
				printf("[Done]: %d, %d\n", array[0], array[1]);
			}
		}
		else
			split_array(array, newArray, size, sp);
	}
	free(newArray);
}
