#include "libft.h"

static void	*ft_memset(void *str, int val, size_t num)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (num > 0)
	{
		*ptr = (unsigned char)val;
		num--;
		ptr++;
	}
	return (str);
}

void	ft_bzero(void *str, size_t num)
{
	ft_memset(str, 0, num);
}
// fill zero to (str), (num) byte