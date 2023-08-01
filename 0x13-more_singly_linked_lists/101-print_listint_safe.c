#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: Pointer to the head of the list.
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow, *fast;
	size_t count = 0;

	slow = head;
	fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			/* Cycle detected, exit with status 98 */
			printf("[%p] %d\n", (void *)slow, slow->n);
			exit(98);
		}
		count++;
	}

	/* Print the last node in the case of a non-cyclic list */
	if (slow != NULL)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		count++;
	}

	return (count);
}
