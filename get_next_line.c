#include "get_next_line.h"

static char *left_over;

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
static	*char ft_init_acc(char **left_over, int	*data_len, int *acc_len)
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
//	acc[0] = '\0';// ?
	*data_len = 0;
	*acc_len = BUFFER_SIZE + 1;
	return (acc);
}

static *char ft_extract_line()
{
	if (len == 0)
		return (free(acc, buffer), NULL);
	if (ft_find_line())
	{
		save_in left over;
		return (ft_substr());
	}
	return (acc);
}

char *get_next_line(int fd)
{
	char	*buffer;
	char	*acc;
	int		data_len;
	int		acc_len;
	int		r;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	acc = ft_init_acc(&left_over, &data_len, &acc_len);
	if (acc == NULL)
		return (NULL);// allwyes if ft_init return NULL left over = NULL so we dont need to free
	if (ft_find_line(acc))
		return (extract_line(acc));
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	r = read(fd, buffer, BUFFER_SIZE);
	while (r > 0)
	{
		if ((data_len + r + 1) > acc_len)
		{
			if (ft_realloc(&acc) == NULL)
				return (free(buffer, acc), NULL);
		}
		ft_memcpy(acc+len, buffer, r);
		if (ft_find_line())
			retur`n (extract_acc());
		r = read(fd, buffer, BUFFER_SIZE);
	}
	if (r < 0)
		return (free(buffer, acc), NULL);
	return (ft_extract_line(acc , len, left_over));
}
