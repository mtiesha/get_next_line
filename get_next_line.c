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

static char	*ft_is_cloud(char **arr_fd, int fd, char **str)
{
	char	*ptr;

	ptr = NULL;
	if (arr_fd[fd] != NULL)
	{
		ptr = ft_strchr(arr_fd[fd], '\n');
		if (ptr)
		{
			*ptr = '\0';
			*str = ft_strdup(arr_fd[fd]);
			free(arr_fd[fd]);
			arr_fd[fd] = ft_strdup(++ptr);
		}
		else
			free(arr_fd[fd]);
	}
	return (ptr);
}

static char	*ft_loop_read(char **cloud, int fd)
{
	char	*heap;
	long	read_size;
	char	*n_ptr;
	char	*temp;

	read_size = 1;
	if (cloud[fd] != NULL)
	{
		heap = ft_strdup(cloud[fd]);
		free(cloud[fd]);//maybe not
	}
	else
	{
		heap = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!heap)
			return (NULL);
	}
	n_ptr = ft_is_cloud(cloud, fd, &heap);
	while (read_size != 0 && !n_ptr)
	{
		read_size = read(fd, heap, BUFFER_SIZE);
		if (read_size < 0)
			return (NULL);
		if (read_size == 0 && cloud[fd] == NULL)
		{
			free(heap);
			return (NULL);
		}
		heap[read_size] = 0;
		n_ptr = ft_strchr(heap, '\n');
		if (!n_ptr)
		{
			*n_ptr = '\0';
			cloud[fd] = ft_strdup(++n_ptr);
		}
		temp = cloud[fd];
		heap = ft_strjoin(cloud[fd], heap);
		free(temp);
		if (read_size == 0)
		{
			free(cloud[fd]);
			return (NULL);
		}
	}
	return (heap);
}

char	*get_next_line(int fd)
{
	static char	*array_fd[OPEN_MAX];

	if (fd > OPEN_MAX || fd < 0)
		return (NULL);
	return (ft_loop_read(array_fd, fd));
}
