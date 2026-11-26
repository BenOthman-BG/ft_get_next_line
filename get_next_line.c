#include "get_next_line.h"

#include "get_next_line.h"

static char	*ft_init_acc(char **left_over_p, size_t *data_len, size_t *acc_len)
{
	char	*acc;

	if (*left_over_p != NULL)
	{
		acc = *left_over_p;
		*left_over_p = NULL;
		*data_len = ft_strlen(acc);
		*acc_len = *data_len + 1;
		return (acc);
	}
	acc = malloc((size_t)BUFFER_SIZE + 1);
	if (acc == NULL)
		return (NULL);
	acc[0] = '\0';
	*data_len = 0;
	*acc_len = (size_t)BUFFER_SIZE + 1;
	return (acc);
}

static char	*ft_extract_and_save(char *acc, size_t len,
				size_t find_line, char **left_over_p)
{
	char	*line;
	size_t	rest;

	if (find_line < 0)
		return (acc);
	line = malloc(find_line + 2);
	if (line == NULL)
		return (ft_cleanup(&acc, NULL));
	ft_memcpy(line, acc, find_line + 1);
	line[find_line + 1] = '\0';
	rest = len - (find_line + 1);
	if (rest > 0)
	{
		*left_over_p = malloc(rest + 1);
		if (*left_over_p == NULL)
			return (ft_cleanup(&acc, &line));
		ft_memcpy(*left_over_p, acc + find_line + 1, rest);
		(*left_over_p)[rest] = '\0';
	}
	free(acc);
	return (line);
}

static int	init_read(char **acc, char **buffer, size_t *find_len)
{
	*find_len = -1;
	*buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (*buffer == NULL)
	{
		ft_cleanup(acc, NULL);
		return (0);
	}
	return (1);
}

static size_t	ft_read_loop(char **acc, size_t *acc_len,
					size_t *data_len, int fd)
{
	char	*buffer;
	size_t	r;
	size_t	find_len;

	if (init_read(acc, &buffer, &find_len) == 0)
		return (-1);
	while (find_len < 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r <= 0)
			break ;
		if ((*data_len + r + 1) > *acc_len
			&& !ft_realloc(acc, acc_len, *data_len, *data_len + r + 1))
			return (ft_cleanup(&buffer, NULL), 0);
		ft_memcpy(*acc + *data_len, buffer, r);
		find_len = ft_find_line(buffer, r);
		*data_len += r;
	}
	free(buffer);
	if (r < 0)
		return (ft_cleanup(acc, NULL) ,0);
	(*acc)[*data_len] = '\0';
	if (find_len >= 0)
		return (find_len + *data_len - r);
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*left_over;
	char		*acc;
	size_t		data_len;
	size_t		acc_len;
	size_t		find_len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	acc = ft_init_acc(&left_over, &data_len, &acc_len);
	if (acc == NULL)
		return (NULL);
	find_len = ft_find_line(acc, data_len);
	if (find_len < 0)
		find_len = ft_read_loop(&acc, &acc_len, &data_len, fd);
	if (acc == NULL)
		return (NULL);
	if (data_len == 0)
		return (ft_cleanup(&acc, NULL));
	return (ft_extract_and_save(acc, data_len, find_len, &left_over));
}
