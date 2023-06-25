#include "sort.h"

/**
 * selection_sort - sorts an array of integers with selection sort
 * @array: array of integers
 * @size: size of array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, key;
	int temp;

	if (array == NULL || size == 0)
		return;
	for (i = 0; i < size - 1; i++)
	{
		key = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[key])
				key = j;
		}
		if (key != i)
		{
			temp = array[key];
			array[key] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
