/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenyahy <obenyahy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 18:25:13 by obenyahy          #+#    #+#             */
/*   Updated: 2026/11/25 19:57:05 by obenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, size_t n))
{
	char *p_src;
	char *p_dest;

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

int	ft_find_line(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char *ft_realloc(char *acc, int acc_len, int data_len)
{
}
