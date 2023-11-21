#include "sort.h"

/**
 * bubble_sort - bubble sort ints in ascending order
 * @array: array of unsorted ints
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{

	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{

		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{

			if (array[i] > array[i + 1])
			{

				switch_val(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
