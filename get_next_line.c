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

static int	ft_reader(int fd, char **buf, long *read_size)
{
	*read_size = read(fd, *buf, BUFFER_SIZE);
	return (*read_size);
}

static char	*ft_join(char **str1, char *str2, int save)
{
	char	*ret;

	if (!*str1 || save)
		ret = ft_strdup(str2);
	else
	{
		ret = ft_strjoin(&*str1, &str2, ft_strlen(*str1), ft_strlen(str2));
		free(*str1);
	}
	if (save)
		free(*str1);
	return (ret);
}

static int	ft_full_cloud(char **ret_str, char **cloud)
{
	char	*ptr;

	ptr = ft_strchr(*cloud, '\n');
	if (ptr)
	{
		*ptr = 0;
		*ret_str = ft_join(&*ret_str, *cloud, 0);
		*ret_str = ft_join(&*ret_str, "\n", 0);
		*cloud = ft_join(&*cloud, ++ptr, 1);
		return (0);
	}
	else
	{
		if (ft_strlen(*cloud))
			*ret_str = ft_join(&*ret_str, *cloud, 0);
		free(*cloud);
		*cloud = NULL;
		return (1);
	}
}

static char	*ft_loop_read(char **cloud, int fd, char *buf, int *flag)
{
	long		read_size;
	char		*ret_str;
	char		*ptr;

	ret_str = NULL;
	read_size = 1;
	if (*cloud)
		*flag = ft_full_cloud(&ret_str, &*cloud);
	while (*flag && ft_reader(fd, &buf, &read_size) > 0)
	{
		buf[read_size] = 0;
		if (ft_strchr(buf, '\n'))
		{
			ptr = ft_strchr(buf, '\n');
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
	static char	*array_fd;
	char		buff[BUFFER_SIZE + 1];
	int			flag;

	flag = 1;
	if (fd > OPEN_MAX || fd < 0)
		return (NULL);
	return (ft_loop_read(&array_fd, fd, buff, &flag));
}
