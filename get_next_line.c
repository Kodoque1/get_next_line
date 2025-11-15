/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:03:05 by zaddi             #+#    #+#             */
/*   Updated: 2025/11/15 17:06:13 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	acquire_data(char *buffer, t_stack s, int *red, int fd, char **res)
{
	*red = read(fd, buffer, BUFFER_SIZE);
	if (!(*red))
	{
		if (s.size)
		{
			*res = (char *)malloc(sizeof(char) * (s.size + 1));
			if (*res == NULL)
				return (-1);
			ft_memcpy(*res, s.data, s.size);
			(*res)[s.size] = '\0';
		}
	}
	return (0);
}

int	extract_new_line(int *i, t_stack *s, char *buffer, int red, char **res)
{
	while (*i < red && !(*res))
	{
		append(s, buffer[*i]);
		if (buffer[*i] == '\n')
		{
			*res = (char *)malloc(sizeof(char) * (s->size + 1));
			if (*res == NULL)
				return (-1);
			ft_memcpy(*res, s->data, s->size);
			(*res)[s->size] = '\0';
		}
		(*i)++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*res;
	static int	i = 1;
	static int	red = 0;
	static char	buffer[BUFFER_SIZE];
	t_stack		s;

	s.capacity = 1;
	s.size = 0;
	s.data = (char *)malloc(sizeof(char));
	res = NULL;
	while (1)
	{
		if (i >= red)
		{
			i = 0;
			if ((acquire_data(buffer, s, &red, fd, &res) == -1) || res || !red)
				break ;
		}
		if ((extract_new_line(&i, &s, buffer, red, &res) == -1) || res)
			break ;
	}
	free(s.data);
	return (res);
}
