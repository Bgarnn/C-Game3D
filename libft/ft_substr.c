#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t num)
{
	char	*sub;
	size_t	str_len;
	size_t	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	str_len = ft_strlen(str);
	if (start >= str_len)
		return (ft_strdup(""));
	if (num > (str_len - start))
		num = str_len - start;
	sub = (char *)malloc(sizeof(char) * (num + 1));
	if (sub == NULL)
		return (NULL);
	while (i < num)
	{
		sub[i] = str[start];
		i++;
		start++;
	}
	sub[num] = '\0';
	return (sub);
}
// allocate substr from (str), begin at index (start), up to (num) size