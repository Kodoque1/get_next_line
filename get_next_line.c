/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:11:11 by zaddi             #+#    #+#             */
/*   Updated: 2026/02/21 22:36:33 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	init_stack(t_stack *s)
{
	s->capacity = BUFFER_SIZE;
	s->size = 0;
	s->data = (char *) malloc(sizeof(char) * BUFFER_SIZE);
	if (s->data == NULL)
		return (-1);
	return (0);
}

int	read_processing(t_buffer_state *bstate, t_stack *s, int fd)
{
	char	c;

	c = read_buffer(bstate, fd);
	if (bstate->red > 0)
	{
		if (append(s, c) == -1)
		{
			free(s->data);
			return (-1);
		}
		if (c == '\n')
			return (0);
		else
			return (1);
	}
	else if (bstate->red < 0)
	{
		free(s->data);
		return (-1);
	}
	else
		return (0);
}

char	*get_next_line(int fd)
{
	static t_buffer_state	bstate = {{0}, 0, 0};
	t_stack					s;
	int						code;

	if (fd <= -1 || BUFFER_SIZE <= -1)
		return (NULL);
	if (init_stack(&s) == -1)
		return (NULL);
	while (1)
	{
		code = read_processing(&bstate, &s, fd);
		if (code == 0)
			break ;
		else if (code == -1)
			return (NULL);
	}
	return (stack_to_line(&s));
}
