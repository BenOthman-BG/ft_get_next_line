/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenyahy <obenyahy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 18:25:13 by obenyahy          #+#    #+#             */
/*   Updated: 2026/11/27 09:38:14 by obenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*p_src;
	unsigned char		*p_dest;

	p_src = (const unsigned char *)src;
	p_dest = (unsigned char *)dest;
	while (n > 0)
	{
		*p_dest = *p_src;
		p_dest++;
		p_src++;
		n--;
	}
	return (dest);
}

ssize_t	ft_find_line(const char *s, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (s[i] == '\n')
			return ((ssize_t)i);
		i++;
	}
	return (-1);
}

int	ft_realloc(char **acc, size_t *acc_len, size_t data_len, size_t need)
{
	char	*new_space;

	while (*acc_len < need)
		*acc_len *= 2;
	new_space = malloc(*acc_len);
	if (new_space == NULL)
	{
		ft_cleanup(acc, NULL);
		return (0);
	}
	if (data_len > 0)
		ft_memcpy(new_space, *acc, data_len);
	free(*acc);
	*acc = new_space;
	return (1);
}

void	*ft_cleanup(char **ptr1, char **ptr2)
{
	if (ptr1 && *ptr1)
	{
		free(*ptr1);
		*ptr1 = NULL;
	}
	if (ptr2 && *ptr2)
	{
		free(*ptr2);
		*ptr2 = NULL;
	}
	return (NULL);
}
