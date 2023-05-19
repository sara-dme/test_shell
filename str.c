#include "main.h"

int _strlen(const char *s)
{
        int count = 0;

        while (s[count])
        {
                count++;
        }
        return (count);
}

char *_strcpy(char *dest, char *src)
{
        unsigned int src_len, i;

        src_len = _strlen(src);

        for (i = 0; i < src_len; i++)
        {
		if (src[i + 1] == '\n' && src[i] == ' ')
		{
		}
		else
                	dest[i] = src[i];
        }
        dest[i] = '\0';

        return (dest);
}
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
