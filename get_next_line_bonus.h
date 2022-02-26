/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha <mtiesha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:55:42 by mtiesha           #+#    #+#             */
/*   Updated: 2021/12/09 15:37:40 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif
# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

size_t	ft_strlen_gnl(const char *string);
char	*ft_strchr_gnl(const char *s, int c);
void	*ft_memcpy_gnl(void *destination, const void *src, size_t n);
char	*ft_strdup_gnl(const char *str);
char	*ft_strjoin_gnl(char **str1, char **str2, size_t str1_len, size_t str2_len);
char	*get_next_line(int fd);
#endif
