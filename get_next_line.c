#include "get_next_line.h"

static *char ft_init_acc(char **left_over_p, int *data_len, int *acc_len)
{
	char	*acc;

	if (*left_over != NULL)
	{
		acc = *left_over;
		*left_over = NULL;
		*data_len = ft_strlen(*left_over);
		*acc_len = *data_len + 1;
		return (acc);
	}
	acc = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (acc == NULL)
		return (NULL);
	acc[0] = '\0';
	*data_len = 0;
	*acc_len = BUFFER_SIZE + 1;
	return (acc);
}

static char *ft_extract_and_save(char *acc, int len, int find_line, char **left_over_p)
{
	char	*line;
	int		rest;

	if (find_line < 0)
		return (acc);
	line = malloc(find_line + 2);
	left = ft_find_line(acc, len);
	if (line == NULL)
		return (free(acc), NULL);
	ft_memcpy(line, acc, find_line + 1) line[find_line + 1] = '\0';
	rest = len - (find_line + 1);
	if (rest > 0)
	{
		*left_over = malloc(rest + 1);
		if (*left_over == NULL)
			return (free(acc, line), NULL);
		ft_memcpy(*left_over, acc + find_len, rest);
		left_over[0][rest] = '\0';
	}
	free(acc);
	return (line);
}

static int	init_read(char *acc, char **buffer, int *find_len)
{
	*find_len = -1;
	*buffer = malloc(BUFFER_SIZE + 1);
	if (*buffer == NULL)
		return (free(acc), 0);
	return (1);
}

int	ft_read_loop(char **acc, int *acc_len, int *data_len, int fd)
{
	char	*buffer;
	int		r;
	int		find_len;

	if (init_read(acc, &buffer, &find_len) == 0)
		return (-1);
	while (find_len < 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r <= 0)
			break ;
		if ((*data_len + r + 1) > *acc_len && !ft_realloc(&acc, &acc_len, data_len, data_len + r + 1))
			return (free(*acc, buffer), NULL);
		ft_memcpy(*acc + *len, buffer, r);
		find_len = ft_find_line(buffer, r);
		*len += r;
	}
	if (r < 0)
		return (free(*acc, buffer), 0);
	acc[0][*len] = '\0';
	if (find_len >= 0)
		return (free(buffer), find_len + *len - r);
	return (free(buffer), -1);
}

char	*get_next_line(int fd)
{
	static char	*left_over;
	char		*acc;
	int			data_len;
	int			acc_len;
	int			find_len;

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
		return (free(acc), NULL);
	return (ft_extract_and_save(acc, len, find_len, &left_over));
}
