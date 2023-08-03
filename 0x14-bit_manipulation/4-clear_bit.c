#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at a given index
 * @n: The number in which to clear the bit
 * @index: The index of the bit to clear (starting from 0)
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	if (index >= sizeof(unsigned long int) * 8) /* Check if index is valid */
		return (-1);

	mask = 1UL << index; /* Create a mask with the bit at the index set to 1 */
	mask = ~mask; /* Invert the mask to set the bit at the index to 0 */
	*n = (*n & mask); /* Clear the bit at the index to 0 */

	return (1);
}
