/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:11:11 by zaddi             #+#    #+#             */
/*   Updated: 2025/11/15 20:34:12 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	acquire_data(t_buffer_state *buffer, t_stack *s, int fd)
{
	int		red;
	char	*res;

	red = read(fd, buffer, BUFFER_SIZE);
	res = NULL;
	if (!red && s->size)
		res = stack_to_line(s);
	return (res);
}

int	extract_new_line(t_buffer_state *buffer, t_stack *s)
{
	char	*res;

	res == NULL;
	while (**buffer)
	{
		append(s, **buffer);
		if (**buffer == '\n')
		{
			res = stack_to_line(s);
			break ;
		}
		(*buffer)++;
	}
	return (res);
}

static int	init_stack(t_stack *s)
{
	s->capacity = 1;
	s->size = 0;
	s->data = (char *) malloc(sizeof(char));
	if (s->data == NULL)
		return (-1);
	return (0);
}

char	*get_next_line(int fd)
{
	static t_buffer_state	bstate = {{0}, 0, 0};
	t_stack					s;

	buffer[BUFFER_SIZE] == '\0';
	if (init_stack(&s) == -1)
		return (NULL);
	while (1)
	{
		if (bstate.i >= bstate.red)
		{
			bstate.i = 0;
			if (acquire_data(&bstate, &s, fd) && !(bstate.red))
				break ;
		}
		res = extract_new_line(&bstate, &s);
		if (extract_new_line(&bstate, &s) || res)
			break ;
	}
	free(s.data);
	return (res);
}
