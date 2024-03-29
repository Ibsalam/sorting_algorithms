#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
    size_t left_child, right_child, largest;

    left_child = 2 * root + 1;
    right_child = 2 * root + 2;
    largest = root;

    if (left_child < base && array[left_child] > array[largest])
        largest = left_child;
    if (right_child < base && array[right_child] > array[largest])
        largest = right_child;

    if (largest != root)
    {
        swap_ints(array + root, array + largest);
        print_array(array, size);
        max_heapify(array, size, base, largest);
    }
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
    int idx;

    if (array == NULL || size < 2)
        return;

    for (idx = (size / 2) - 1; idx >= 0; idx--)
        max_heapify(array, size, size, idx);

    for (idx = size - 1; idx > 0; idx--)
    {
        swap_ints(array, array + idx);
        print_array(array, size);
        max_heapify(array, size, idx, 0);
    }
}
