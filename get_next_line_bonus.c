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

static char	*ft_n_in(char **cloud, int fd)
{
	char	*temp;
	char	*ret;
	int		i;

	i = 0;
	while (cloud[fd][i] != '\n')
		i++;
	ret = ft_substr(cloud[fd], 0, i);
	temp = ft_strdup(&(cloud[fd][i + 1]));
	free(cloud[fd]);
	cloud[fd] = temp;
	return (ret);
}

static void	*ft_full_cloud(char **ret, int file, char *str)//maybe void **
{
	char	*temp;
	int		i;

	i = 0;
	while (ret[file][i] != '\n' && ret[file][i] != '\0')
		if (ret[file][i++] == '\n')
			return(ft_n_in(ret, file));
	temp = ft_strjoin(ret[file], str);
	if (temp == NULL)
		return (NULL);
	free(ret[file]);
	free (str);
	ret[file] = temp;
	return (ret);
}

char	*ft_get_next_line(int fd)
{
	char		*heap;
	static char	*cloud[OPEN_MAX];
	long		read_size;

	heap = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd > OPEN_MAX || fd < 0 || !heap)
		return (NULL);
	read_size = read(fd, heap, BUFFER_SIZE);
	if (read_size < 0 || (read_size == 0 && cloud[fd] == NULL))
	{
		free(heap);
		return (NULL);
	}
	heap[read_size] = 0;
	if (cloud[fd] == NULL)
		cloud[fd] = ft_strdup(heap);
	else
		ft_full_cloud(cloud, fd, heap);
	return (cloud[fd]);
}
