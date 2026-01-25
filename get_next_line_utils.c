/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:05:17 by zaddi             #+#    #+#             */
/*   Updated: 2026/01/25 14:46:27 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	append(t_stack *s, char c)
{
	char	*buf;

	if (s->capacity == s->size)
	{
		buf = (char *)malloc(sizeof(char) * (s->capacity + BUFFER_SIZE));
		if (!buf)
			return (-1);
		ft_memcpy(buf, s->data, s->capacity);
		free(s->data);
		s->data = buf;
		s->capacity += BUFFER_SIZE;
	}
	s->data[s->size] = c;
	s->size++;
	return (1);
}

char	read_buffer(t_buffer_state *bstate, int fd)
{
	if (bstate->i >= bstate->red)
	{
		bstate->red = read(fd, bstate->data, BUFFER_SIZE);
		bstate->i = 0;
	}
	return (bstate->data[bstate->i++]);
}

char	*stack_to_line(t_stack *s)
{
	char	*res;

	res = NULL;
	if (s->size)
	{
		res = (char *)malloc(sizeof(char) * (s->size + 1));
		if (res == NULL)
		{
			free(s->data);
			return (NULL);
		}
		ft_memcpy(res, s->data, s->size);
		res[s->size] = '\0';
	}
	free(s->data);
	return (res);
}
