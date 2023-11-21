#include "sort.h"

void switch_val(int *val, int *valu);
int lomuto_part_sch(int *array, size_t size, int L, int R);
void lomuto_sort(int *array, size_t size, int L, int R);
void quick_sort(int *array, size_t size);

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
 * lomuto_part_sch - sorts arr via lumo...
 * @array: ints array
 * @size: array size
 * @L: starting idx
 * @R: ending idx
 * Return: The final partition index.
 */
int lomuto_part_sch(int *array, size_t size, int L, int R)
{
	int *pivot, up, down;

	pivot = array + R;
	for (up = down = L; down < R; down++)
	{
		if (array[down] < *pivot)
		{
			if (up < down)
			{
				switch_val(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *pivot)
	{
		switch_val(array + up, pivot);
		print_array(array, size);
	}

	return (up);
}

/**
 * lomuto_sort - uses recursion to lumoto sort
 * @array: array to be sorted
 * @size: array sizeu
 * @L: starting idx
 * @R: ending idx
 */
void lomuto_sort(int *array, size_t size, int L, int R)
{
	int part;

	if (R - L > 0)
	{
		part = lomuto_part_sch(array, size, L, R);
		lomuto_sort(array, size, L, part - 1);
		lomuto_sort(array, size, part + 1, R);
	}
}

/**
 * quick_sort - performs quicksort algorithm
 * @array: array of ints
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
