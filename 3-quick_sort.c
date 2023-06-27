#include "sort.h"
/**
 * swap - swaps two array
 * @a: array a
 * @b: array b
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * partition - partition
 * @array: array of integer
 * @low: lower
 * @high: higher
 *
 * Return: i
 */
int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, high + 1);
		}
	}

	swap(&array[i + 1], &array[high]);
	print_array(array, high + 1);

	return (i + 1);
}
/**
 * quick_sort_recursive - quick sort recursive
 * @array: array of int
 * @low: lower
 * @high: higher
 *
 * Return: void
 */
void quick_sort_recursive(int *array, int low, int high)
{
	if (low < high)
	{
		int pi = partition(array, low, high);

		quick_sort_recursive(array, low, pi - 1);
		quick_sort_recursive(array, pi + 1, high);
	}
}
/**
 * quick_sort - sorts elements in an array of int using quick sort
 * @array: array of int
 * @size: size of array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1);
}
