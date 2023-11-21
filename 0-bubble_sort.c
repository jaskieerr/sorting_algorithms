
#include "sort.h"

/**
 * switch_val - switches two values with eachother
 * @val: 1st value
 * @valu: 2nd
 */
void switch_val(int *val, int *valu)
{
	int swp;

	swp = *val;
	*val = *valu;
	*valu = swp;
}

/**
 * bubble_sort - bubble sort ints in ascending order
 * @array: array of unsorted ints
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool swapped = false;

	if (array == NULL || size < 2)
		return;
	while (!swapped)
	{
		swapped = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				switch_val(array + i, array + i + 1);
				print_array(array, size);
				swapped = false;
			}
		}
		len--;
	}
}
