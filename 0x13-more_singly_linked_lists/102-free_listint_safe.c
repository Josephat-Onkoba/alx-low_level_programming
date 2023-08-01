#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list.
 * @h: Pointer to the head of the list.
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *slow, *fast;
	size_t size = 0;

	slow = *h;
	fast = *h;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			/* Cycle detected, free the list and exit */
			size = 0;
			while (*h != NULL)
			{
				slow = *h;
				*h = (*h)->next;
				free(slow);
				size++;
			}
			*h = NULL;
			exit(98);
		}
	}

	/* No cycle detected, free the list normally */
	size = 0;
	while (*h != NULL)
	{
		slow = *h;
		*h = (*h)->next;
		free(slow);
		size++;
	}
	*h = NULL;

	return (size);
}
