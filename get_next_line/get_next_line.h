#ifndef GET_NEXT_LINE_H
 #define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
// #include "../libft/libft.h"

char    *read_line(char    *str);
char    *read_next_line(char   *str);
char *main_read(char *st , int fd);
char	  *get_next_line(int fd);


char	*ft_strdup(const char *s);

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);


#endif