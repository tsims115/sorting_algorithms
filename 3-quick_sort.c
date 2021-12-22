#include "sort.h"

/**
 * swap - swaps two variables
 * @i: first one to swap
 * @j: second one to swap
 */

void swap(int *i, int *j)
{
	int tmp = *i;

	*i = *j;
	*j = tmp;
}

/**
 * partition - Lomuto parition
 * @arr: array to start
 * @low: lowest value
 * @high: highest value
 * @size: size of array
 * Return: pivot
 *
 */

int partition(int *arr, int low, int high, size_t size)
{
	int pivot = arr[high];
	int i = low;
	int j;

	for (j = low; j < high; j++)
	{
		if (arr[j] < pivot)
		{
			if (i != j)
			{
				swap(&arr[i], &arr[j]);
				print_array(arr, size);
			}
			i++;
		}
	}
	swap(&arr[i], &arr[high]);
	print_array(arr, size);
	return (i);
}

/**
 * lomuto_scheme - uses lomuto scheme to sort array
 * @arr: array to be sorted
 * @low: lowest value
 * @high: highest value -- pivot
 * @size: size of the array
 */
void lomuto_scheme(int *arr, int low, int high, size_t size)
{
	int i;

	if (low < high)
	{
		i = partition(arr, low, high, size);
		lomuto_scheme(arr, low, i - 1, size);
		lomuto_scheme(arr, i + 1, high, size);
	}
}

/**
 * quick_sort - sorts arr of ints in ascending order using quick sort
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{

	lomuto_scheme(array, 0, size - 1, size);
}
