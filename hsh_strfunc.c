#include "shell.h"

/**
 *
 *
 *
 */
size_t _strlen(const char *s)
{
	size_t len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}

/**
 *
 *
 *
 */
char *_strdup(char *str)
{
	int len = 0, i = 0;
	char *buff;
	
	len = _strlen(str);

	if (!str)
		return (NULL);
	
	buff = malloc(sizeof(char) * len + 1);
	if (!buff)
		return (NULL);
	
	if (buff)
	{
		for (i = 0; str[i] != '\0'; i++)
			buff[i] = str[i];
	}

	buff[i] = '\0';
	return (buff);
}

/**
 *_strcpy - copies string
 *@dest: copy of string
 *@src: source of string
 *
 *return: copy of the src
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i = 0;

	while (*src[i] != '\0')
	{
		*dest[i]  = *src[i];
		i++;
	}
	*dest[i] = '\0';
	return (dest);
}

/**
 *
 *
 *
 */
char *_strcat(char *dest, const char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;

	return (ret);
}
