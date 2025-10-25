#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *prev, *next;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		temp = current->prev;

		while (temp && current->n < temp->n)
		{
			prev = temp->prev;
			next = current->next;

			if (prev)
				prev->next = current;
			else
				*list = current;

			if (next)
				next->prev = temp;

			current->prev = prev;
			current->next = temp;
			temp->prev = current;
			temp->next = next;

			print_list(*list);
			temp = current->prev;
		}
		current = current->next;
	}
}
