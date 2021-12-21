#include "sort.h"
/**
 * selection_sort - sort array of int ascending order using selection algorithm
 * @array: array to sort
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, idx;
	int tmp, min;
	int flag = 0;

	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		for (j = i; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				idx = j;
				flag = 1;
			}
			if ((flag == 1) && (j == size - 1))
			{
				tmp = array[idx];
				array[idx] = array[i];
				array[i] = tmp;
				print_array(array, size);
			}
		}
		flag = 0;
	}
}
