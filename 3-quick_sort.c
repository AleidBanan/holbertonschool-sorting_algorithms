#include "sort.h"

/**
 * swap_int - swaps two integers in an array
 * @a: first integer
 * @b: second integer
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - partitions an array using the Lomuto scheme
 * @array: array to partition
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 *
 * Return: the final index of the pivot
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	size_t i, j;

	i = low;
	for (j = low; j < high; j++)
	{
		if (array[j] <= array[high])
		{
			if (i != j)
			{
				swap_int(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		swap_int(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_recursive - recursive helper function for Quick sort
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 */
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);

		if (pivot > 0)
			quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm (Lomuto partition scheme)
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
