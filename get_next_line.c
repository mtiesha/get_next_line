/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha <mtiesha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 06:57:20 by mtiesha           #+#    #+#             */
/*   Updated: 2021/11/12 06:57:20 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_call_struct(char *buff, int fd, struct_t fd_stack)
{
	while (fd != 
}

char	*ft_get_next_line(int fd)
{
	char		*heap;
	static struct_t	fd_stack;

	heap = (char *)malloc((BUFF_SIZE + 1) * sizeof(char));
	if (fd >= 65536 || fd < 0 || !heap)
		return (NULL);
	ft_call_struct(heap, fd, fd_stack);
	
}
