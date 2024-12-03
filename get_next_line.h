// add 42 header
//
//
//
//
//
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 22
# endif
char	*get_next_line(int fd);
char    *ft_strdup(const char *s1);
size_t  ft_strlen(const char *s);
char    *ft_strdup(const char *s1);
char    *fake_join(char *s1, char *s2);
char    **fake_split(char *str);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
#endif
