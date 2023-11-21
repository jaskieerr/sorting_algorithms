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
 * selection_sort - performs selection sort on an array of integers
 * @array: array of integers
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	int *min_ptr;
	size_t i;
	size_t j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_ptr = array + i;

		for (j = i + 1; j < size; j++)
			min_ptr = (array[j] < *min_ptr) ? (array + j) : min_ptr;

		if ((array + i) != min_ptr)
		{
			switch_val(array + i, min_ptr);
			print_array(array, size);
		}
	}
}
