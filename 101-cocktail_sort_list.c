#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **current);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **current);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @current: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **current)
{
    listint_t *tmp = (*current)->next;

    if ((*current)->prev != NULL)
        (*current)->prev->next = tmp;
    else
        *list = tmp;
    tmp->prev = (*current)->prev;
    (*current)->next = tmp->next;
    if (tmp->next != NULL)
        tmp->next->prev = *current;
    else
        *tail = *current;
    (*current)->prev = tmp;
    tmp->next = *current;
    *current = tmp;
}

/**
 * swap_node_behind - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @current: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **current)
{
    listint_t *tmp = (*current)->prev;

    if ((*current)->next != NULL)
        (*current)->next->prev = tmp;
    else
        *tail = tmp;
    tmp->next = (*current)->next;
    (*current)->prev = tmp->prev;
    if (tmp->prev != NULL)
        tmp->prev->next = *current;
    else
        *list = *current;
    (*current)->next = tmp;
    tmp->prev = *current;
    *current = tmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *tail, *current;
    bool sorted = false;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    for (tail = *list; tail->next != NULL;)
        tail = tail->next;

    while (sorted == false)
    {
        sorted = true;
        for (current = *list; current != tail; current = current->next)
        {
            if (current->n > current->next->n)
            {
                swap_node_ahead(list, &tail, &current);
                print_list((const listint_t *)*list);
                sorted = false;
            }
        }
        for (current = current->prev; current != *list; current = current->prev)
        {
            if (current->n < current->prev->n)
            {
                swap_node_behind(list, &tail, &current);
                print_list((const listint_t *)*list);
                sorted = false;
            }
        }
    }
}
