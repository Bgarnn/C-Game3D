#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t num)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((num > 0) && (str1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		num--;
		i++;
	}
	return (0);
}
// compare NULL-terminate strings, (num) character