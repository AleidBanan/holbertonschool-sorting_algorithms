#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: pointer to the array to sort
 * @size: number of elements in the array
 *
 * Return: nothing (void)
 */

void bubble_sort(int *array, size_t size)

{
	size_t count;

	size_t i;

	int temp;

	if (array == NULL || size == 1)
		return;


	for (count = 0; count < size; count++)
	{
		int swapped = 0;

		for (i = 0; i < size - count - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);

				swapped = 1;
			}
		}

		if (!swapped)
			break;
	}
}
