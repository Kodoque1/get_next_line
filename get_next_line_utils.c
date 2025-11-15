/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:05:17 by zaddi             #+#    #+#             */
/*   Updated: 2025/11/15 17:05:44 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_strndup(const char *s, int len)
{
	char	*str;

	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s, len);
	str[len] = '\0';
	return (str);
}

int	append(t_stack *s, char c)
{
	char	*buf;

	if (s->capacity == s->size)
	{
		buf = (char *)malloc(sizeof(char) * s->capacity * 2);
		if (!buf)
			return (-1);
		ft_memcpy(buf, s->data, s->capacity);
		free(s->data);
		s->data = buf;
		s->capacity *= 2;
	}
	s->data[s->size] = c;
	s->size++;
	return (1);
}
