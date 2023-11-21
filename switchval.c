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
