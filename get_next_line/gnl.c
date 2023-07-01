#include "get_next_line.h"

// read, free and malloc

char    *read_line(char    *str)
{
    int i;
    char *new;

    i = 0;
    new = NULL;
    while (str[i] && str[i] != '\n')
        i++;
    if (str[i] == '\n')
        i++;
    new = malloc(sizeof(char) * i + 1);
    if (!new)
        return (NULL);
    i = 0;
    while (str[i] && str[i] != '\n')
    {
        new[i] = str[i];
        i++;
    }
    if (str[i] == '\n')
        new[i] = str[i];
    new[++i] = '\0';
    return (new);
}

char    *read_next_line(char   *str)
{
    int i;
    char *buf;

    i = 0;
    buf = NULL;
    while (str[i] && str[i] != '\n')
        i++;
    if (str[i])
    {
        free(str);
        return (NULL);
    }
    buf = malloc((sizeof(char )* ft_strlen(str) - i + 1));
    if (!buf)
        return (NULL);
    i = 0;
    while (str[i] && str[i] != '\n')
        {
            buf[i] = str[i];
            i++;
        }
    if (str[i] == '\n')
        buf[i++] =  '\n';
    buf[i] = '\0';
    return (buf);
}

char *main_read(char *st , int fd)
{
    int     bytes;
    char    *buf;
    char    *line;

    if (fd < 0)
        return (NULL);
    bytes = 1;
    buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buf)
        return (NULL);
    while (!ft_strchr(st, '\n') && bytes != -1)
    {
        bytes = read(fd , buf, BUFFER_SIZE);
        if (bytes == -1)
        {
            free(st);
            return (NULL);
        }
        buf[bytes] = '\0';
        line = ft_strdup(st);
        free(st);
        st = ft_strjoin(line , buf);
        free(line);
    }
    free(buf);
    return (st);
}

char	  *get_next_line(int fd)
{
    char        *line;
    static char *buf;

    line = NULL;
    if (fd  < 0 ||  BUFFER_SIZE <= 0 )
        {
        return (NULL);

        }
    buf = main_read(buf , fd);
    if (!buf)
        return (NULL);
    line = read_line(buf);
    buf = read_next_line(buf);
    if (!line)
    {
        free(line);
        free(buf);
        return(NULL);
    }
    system("leaks a.out");
        return (line);
}

int main(void)
{
    int fd = open("textt", O_RDONLY);
    // (get_next_line(fd));
    char *line = get_next_line(fd);
    printf("%s",line);
    free(line);
    line = get_next_line(fd);
    printf("%s",line);
    free(line);
    line = get_next_line(fd);
    printf("%s",line);
    free(line);

}
