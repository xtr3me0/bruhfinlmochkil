// add the 42 header
//
//
//
//
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;
	char		**tab;

	line = NULL;
	while (1)
	{
		if (buff == NULL)
		{
			buff = malloc((size_t)BUFFER_SIZE + 1);
			if (buff == NULL)
				return (NULL);
			buff[BUFFER_SIZE] = '\0';
			if (read(fd, buff, BUFFER_SIZE) <= 0)
				return (free(buff), buff = NULL, NULL);
		}
		else
		{
			if (ft_strchr(buff, '\n') == NULL)
			{
				line = fake_join(line, buff);
				if (line == NULL)
					return (NULL);
			}
			else
			{
				tab = fake_split(buff);
				if (tab == NULL)
					return (free(buff), buff = NULL, free(line), NULL);
				line = fake_join(line, tab[0]);
				if (line == NULL)
					return (free(buff), buff = NULL, free(tab[1]), free(tab), NULL);
				return (free(buff), buff = tab[1], free(tab), line);
			}
		}
	}
}

char	*fake_join(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (str = ft_strdup(s2), free(s2), s2 = NULL, str);
	if (s2 == NULL)
		return (str = ft_strdup(s1), free(s1), s1 = NULL, str);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (free(s1), free(s2), s1 = NULL, s2 = NULL, NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (free(s1), free(s2), s1 = NULL, s2 = NULL, str);
}

char	**fake_split(char *str)
{
	size_t	i;
	char	**tab;
	char	*ptr;

	if (str == NULL)
		return (NULL);
	tab = malloc(2 * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	i = 0;
	ptr = ft_strchr(str, '\n') + 1;
	tab[0] = ft_substr(str, 0, ptr - str);
	if (*ptr == '\0')
		return (tab[1] = NULL, tab);
	tab[1] = ft_strdup(ptr);
	return (tab);
}
