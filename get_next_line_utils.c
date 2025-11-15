/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:05:17 by zaddi             #+#    #+#             */
/*   Updated: 2025/11/15 20:06:04 by zaddi            ###   ########.fr       */
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

char	*stack_to_line(t_stack *s)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (s->size + 1));
	if (res == NULL)
		return (NULL);
	ft_memcpy(res, s->data, s->size);
	res[s->size] = '\0';
	return (res);
}
