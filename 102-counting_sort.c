#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int maximum, index;

	for (maximum = array[0], index = 1; index < size; index++)
	{
		if (array[index] > maximum)
			maximum = array[index];
	}

	return (maximum);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *counter, *sortedArray, maximumValue, index;

	if (array == NULL || size < 2)
		return;

	sortedArray = malloc(sizeof(int) * size);
	if (sortedArray == NULL)
		return;
	maximumValue = get_max(array, size);
	counter = malloc(sizeof(int) * (maximumValue + 1));
	if (counter == NULL)
	{
		free(sortedArray);
		return;
	}

	for (index = 0; index < (maximumValue + 1); index++)
		counter[index] = 0;
	for (index = 0; index < (int)size; index++)
		counter[array[index]] += 1;
	for (index = 0; index < (maximumValue + 1); index++)
		counter[index] += counter[index - 1];
	print_array(counter, maximumValue + 1);

	for (index = 0; index < (int)size; index++)
	{
		sortedArray[counter[array[index]] - 1] = array[index];
		counter[array[index]] -= 1;
	}

	for (index = 0; index < (int)size; index++)
		array[index] = sortedArray[index];

	free(sortedArray);
	free(counter);
}
