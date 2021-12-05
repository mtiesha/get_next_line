/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha <mtiesha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 06:57:20 by mtiesha           #+#    #+#             */
/*   Updated: 2021/11/12 06:57:20 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
//# include <limits.h>
# define OPEN_MAX 1024
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif
# if BUFFER_SIZE < 0
# undef BUFFER_SIZE
# define BUFFER_SIZE 0
# endif

size_t	ft_strlen(const char *string);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *destination, const void *src, size_t n);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *str1, char const *str2);
char	*get_next_line(int fd);
#endif
