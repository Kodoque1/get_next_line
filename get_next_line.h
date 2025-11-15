/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaddi <zaddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:01:55 by zaddi             #+#    #+#             */
/*   Updated: 2025/11/15 17:04:50 by zaddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	char	*data;
	int		capacity;
	int		size;
}			t_stack;

char		*get_next_line(int fd);
int			append(t_stack *s, char c);
void		*ft_memcpy(void *dest, const void *src, int n);

#endif
