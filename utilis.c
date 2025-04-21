#include "main.h"

/**
 * in - check if char in string
 * @s: string to check
 * @c: the char is lloking for
 * Return: true  or false
 */

bool in(const char *s, char c)
{
	if (s == NULL)
		return (false);
	while (*s)
	{
		if (*s == c)
			return (true);
		++s;
	}
	return (false);
}
