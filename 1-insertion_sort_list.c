#include "sort.h"

/**
 * node_swap - swaps 2 dll nodes with each other
 * @head: head ptr
 * @a: node to be swapped num1
 * @b: node to be swapped num2
 */
void node_swap(listint_t **head, listint_t **a, listint_t *b)
{
	(*a)->next = b->next;

	if (b->next != NULL)
		b->next->prev = *a;
	b->prev = (*a)->prev;
	b->next = *a;
	if ((*a)->prev != NULL)
		(*a)->prev->next = b;
	else
		*head = b;
	(*a)->prev = b;
	*a = b->prev;
}

/**
 * insertion_sort_list - sorts a dll "insertion sorinly"
 * @list: dll head pointer
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = tmp)
	{
		tmp = i->next;
		j = i->prev;
		while (j != NULL && i->n < j->n)
		{
			node_swap(list, &j, i);
			print_list((const listint_t *)*list);
		}
	}
}
