/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:01:55 by zaddi             #+#    #+#             */
/*   Updated: 2025/11/18 14:27:53 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MAX_FDS 1024

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
void		*ft_memcpy(void *dest, const void *src, int n);
char		*stack_to_line(t_stack *s);
char		read_buffer(t_buffer_state *bstate, int fd);

#endif
