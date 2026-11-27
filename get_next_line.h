#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
ssize_t	ft_find_line(const char *s, size_t len);
int		ft_realloc(char **acc, size_t *acc_len, size_t data_len, size_t need);
void	*ft_cleanup(char **ptr1, char **ptr2);

#endif
