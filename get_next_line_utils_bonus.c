/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha <mtiesha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:55:42 by mtiesha           #+#    #+#             */
/*   Updated: 2021/12/09 13:52:54 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)(c))
			return ((char *)(s));
		s++;
	}
	return (NULL);
}

void	*ft_memcpy(void *destination, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!destination && !src)
		return (NULL);
	d = destination;
	s = src;
	while (n-- > 0)
		*d++ = *s++;
	return (destination);
}

char	*ft_strdup(const char *str)
{
	unsigned char	*s;
	int				str_len;

	str_len = ft_strlen(str) + 1;
	s = (unsigned char *)malloc(str_len * sizeof(char));
	if (s != NULL)
	{
		ft_memcpy(s, str, str_len);
		return ((char *)(s));
	}
	return (NULL);
}

char	*ft_strjoin(char **str1, char **str2, size_t str1_len, size_t str2_len)
{
	size_t			str1str2_len;
	unsigned char	*ret;

	str1str2_len = str1_len + str2_len;
	ret = malloc((str1str2_len + 1) * sizeof(char));
	if (ret != NULL)
	{
		ft_memcpy(ret, *str1, str1_len);
		ft_memcpy(ret + str1_len, *str2, str2_len);
		ret[str1str2_len] = 0;
		return ((char *)(ret));
	}
	return (NULL);
}
