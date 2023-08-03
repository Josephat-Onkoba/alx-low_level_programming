#include "main.h"

/**
 * get_bit - Gets the value of a bit at a given index
 * @n: The number to extract the bit from
 * @index: The index of the bit to get (starting from 0)
 *
 * Return: The value of the bit at index index,
 * or -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8) /* Check if index is valid */
		return (-1);

	return ((n >> index) & 1);
}
