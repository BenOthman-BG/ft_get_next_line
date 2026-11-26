/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenyahy <obenyahy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 18:25:13 by obenyahy          #+#    #+#             */
/*   Updated: 2026/11/26 12:08:08 by obenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*p_src;
	char	*p_dest;

	p_src = (char *)src;
	p_dest = (const char *)dest;
	while (n > 0)
	{
		*p_dest = *p_src;
		p_dest++;
		p_src++;
		n--;
	}
	return (dest);
}

int	ft_find_line(char *s, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_realloc(char **acc, int *acc_len, int data_len, int need)
{
	char	*new_space;

	while (*acc_len < need)
		*acc_len *= 2;
	new_space = malloc(*acc_len * sizeof(char));
	if (new_space == NULL)
		return (free(*acc), 0);
	ft_memcpy(new_space, acc, data_len);
	free(*acc);
	*acc = new_space;
	return (1);
}
