#include "libft.h"

char	*ft_strchr(const char *str, int val)
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr != '\0')
	{
		if (*ptr == (char)val)
			return (ptr);
		ptr++;
	}
	if (val == '\0')
		return (ptr);
	return (NULL);
}
// locate first (val) in (str), NULL-terminare