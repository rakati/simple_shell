#include "shell.h"

/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: Pointer to the previously allocated memory block.
 * @old_size: Size of the allocated space for ptr, in bytes.
 * @new_size: New size for the memory block, in bytes.
 *
 * Return: Pointer to the reallocated memory block, or NULL if failed.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	unsigned int min_size = 0;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);

	if (new_size > old_size)
		min_size = old_size;
	else
		min_size = new_size;

	if (new_ptr != NULL)
	{
		_memcpy(new_ptr, ptr, min_size);
		free(ptr);
	}
	return (new_ptr);
}
