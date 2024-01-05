#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	if (ptr != NULL)
	{
		while (str[i] != '\0')
		{
			ptr[i] = str[i];
			i++;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}
// allocate memmory for a copr of (str)