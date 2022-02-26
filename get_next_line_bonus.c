/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha <mtiesha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:55:42 by mtiesha           #+#    #+#             */
/*   Updated: 2021/12/09 13:52:54 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_reader(int fd, char **buf, long *read_size)
{
	*read_size = read(fd, *buf, BUFFER_SIZE);
	return (*read_size);
}

static char	*ft_join(char **str1, char *str2, int slide)
{
	char	*ret;

	if (!*str1 || slide)
		ret = ft_strdup_gnl(str2);
	else
	{
		ret = ft_strjoin_gnl(&*str1, &str2, ft_strlen_gnl(*str1), ft_strlen_gnl(str2));
		free(*str1);
	}
	if (slide)
		free(*str1);
	return (ret);
}

static int	ft_full_cloud(char **ret_str, char **cloud)
{
	char	*ptr;

	ptr = ft_strchr_gnl(*cloud, '\n');
	if (ptr)
	{
		*ptr = 0;
		*ret_str = ft_join(&*ret_str, *cloud, 0);
		*ret_str = ft_join(&*ret_str, "\n", 0);
		*cloud = ft_join(&*cloud, ++ptr, 1);
		return (1);
	}
	else
	{
		if (ft_strlen_gnl(*cloud))
			*ret_str = ft_join(&*ret_str, *cloud, 0);
		free(*cloud);
		*cloud = NULL;
		return (0);
	}
}

static char	*ft_loop_read(char **cloud, int fd, char *buf, int *n_in_cloud)
{
	long		read_size;
	char		*ret_str;
	char		*ptr;

	ret_str = NULL;
	read_size = 1;
	if (*cloud)
		*n_in_cloud = ft_full_cloud(&ret_str, &*cloud);
	while (!*n_in_cloud && ft_reader(fd, &buf, &read_size) > 0)
	{
		buf[read_size] = 0;
		if (ft_strchr_gnl(buf, '\n'))
		{
			ptr = ft_strchr_gnl(buf, '\n');
			*ptr = 0;
			*cloud = ft_join(&*cloud, ++ptr, 0);
			ret_str = ft_join(&ret_str, buf, 0);
			return ((ret_str = ft_join(&ret_str, "\n", 0)));
		}
		ret_str = ft_join(&ret_str, buf, 0);
	}
	if (!read_size && !ret_str)
		return (NULL);
	return (ret_str);
}

char	*get_next_line(int fd)
{
	static char	*array_fd[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	int			n_in_cloud;

	if (fd > OPEN_MAX || fd < 0)
		return (NULL);
	n_in_cloud = 0;
	return (ft_loop_read(&*(array_fd + fd), fd, buff, &n_in_cloud));
}
