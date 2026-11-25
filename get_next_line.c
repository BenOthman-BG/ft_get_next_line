#include "get_next_line.h"

static int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

static	*char ft_init_acc(char **left_over_p, int	*data_len, int *acc_len)
{
	char *acc;

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

static *char ft_extract_and_save(char *acc, int len, char **left_over_p)
{
	int	left;

	if (len == 0)
		return (free(acc), NULL);
	left = ft_find_line(acc, len);
	if (left >= 0)
	{
		if (left < len)
		{
			*left = malloc(len - left + 1);
			*left = ft_memcpy(*left, acc + left, len - left);
		}
		return (ft_substr(acc, 0, left));
	}
	return (acc);
}

int	ft_read_loop(char **acc, int *acc_len, int *data_len, int fd)
{
	char *buffer;
	int	r;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	r = read(fd, buffer, BUFFER_SIZE);
	while (r > 0)
	{
		if ((data_len + r + 1) > acc_len)
			*acc = ft_realloc(acc);
		if (*acc == NULL)
			return (free(*acc, buffer), NULL);
		ft_memcpy*(acc + *len, buffer, r);
		*len += r;
		if (ft_find_line(buffer))
			break ;
		r = read(fd, buffer, BUFFER_SIZE);
	}
	if (r < 0)
		return (free(*acc, buffer), NULL);
	acc[0][*len] = '\0';
	return (free(buffer), *acc);
}

char *get_next_line(int fd)
{

	static char *left_over;
	char	*acc;
	int		data_len;
	int		acc_len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	acc = ft_init_acc(&left_over, &data_len, &acc_len);
	if (acc == NULL)
		return (NULL);// allwyes if ft_init return NULL left over = NULL so we dont need to free
	if (ft_find_line(acc))
		return (ft_extract_and_save(acc, len, &left_over));
	if (ft_read_loop(&acc, &acc_len, &data_len, fd) == NULL)
		return (NULL);
	if (data_len == 0)
		return (NULL);
	return (ft_extract_and_save(acc , len, &left_over));
}
