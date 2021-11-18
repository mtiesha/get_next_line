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

char	*ft_reader(const int fd, char **fd_stack)
{
	char	*heap;

	heap = (char *)malloc(BUFF_SIZE * sizeof(char));
	if (!heap || (read(fd, heap, BUFF_SIZE) < 0))
		return (NULL);
	heap[BUFF_SIZE] = 0;
	if (fd_stack[fd][0] != NULL)
	{
		ft_strjoin(fd_stack[fd], heap);
	}
}

char	*ft_get_next_line(int fd)
{
	char		*ret;
	static char	**fd_stack[MAX_FD];

	if (fd > MAX_FD || fd < 0 || fd == 1)
		return (NULL);
	fd_stack[MAX_FD][0] = '0';
	return (ft_reader(fd, fd_stack));
}
