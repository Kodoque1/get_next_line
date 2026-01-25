/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:01:55 by zaddi             #+#    #+#             */
/*   Updated: 2026/01/25 14:54:26 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_stack
{
	char	*data;
	int		capacity;
	int		size;
}			t_stack;

typedef struct s_buffer_state
{
	char	data[BUFFER_SIZE];
	int		i;
	int		red;
}			t_buffer_state;

char		*get_next_line(int fd);
int			append(t_stack *s, char c);
char		*stack_to_line(t_stack *s);
char		read_buffer(t_buffer_state *bstate, int fd);

#endif
