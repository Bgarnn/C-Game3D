#include "libft.h"

static int	ft_countword(char const *s, char val)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != val)
		{
			word++;
			while ((s[i] != val) && (s[i] != '\0'))
				i++;
		}
		else
			i++;
	}
	return (word);
}

static int	ft_countchar(char const *s, char val)
{
	int		i;

	i = 0;
	while ((s[i] != '\0') && (s[i] != val))
		i++;
	return (i);
}

static char	**ft_free(char **str, int str_i)
{
	while (str_i >= 0)
	{
		free(str[str_i]);
		str_i--;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char val)
{
	char	**str;
	int		str_i;
	int		s_i;

	str_i = 0;
	s_i = 0;
	if (s == NULL)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (ft_countword(s, val) + 1));
	if (str == NULL)
		return (NULL);
	while (str_i < (ft_countword(s, val)))
	{
		while ((s[s_i] != '\0') && (s[s_i] == val))
			s_i++;
		str[str_i] = ft_substr(s, s_i, ft_countchar(&s[s_i], val));
		if (str[str_i] == NULL)
			return (ft_free(str, str_i));
		while ((s[s_i] != '\0') && (s[s_i] != val))
			s_i++;
		str_i++;
	}
	str[str_i] = NULL;
	return (str);
}
// split string (s) by (val) character, NULL-terminate