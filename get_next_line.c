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

void	*ft_content_maker(char *buff)
{
	while (
}

t_list	*ft_lstnew(int id, char *content, int flag)
{
	t_list	*p;

	if (!flag)
	{
		p = (t_list *)malloc(1 * sizeof(t_list));
		if (p != NULL && ft_content_maker(content))
		{
			ft_content_maker(
			//if (!content)
			//	p -> content = NULL;
			//else
			//	p -> content = content;
			//p -> next = NULL;
			return (p);
		}
	}
	
	return (NULL);
}

void	*ft_call_struct(char *buff, int fd, t_list *s_stack)
{
	t_list	*s_str;
	t_list	*s_fd_stack;

	s_fd_stack = s_stack;
	while (fd != s_fd_stack -> id || s_fd_stack -> next != NULL)
		s_fd_stack = s_fd_stack -> next;
	if (s_fd_stack -> next == NULL)
	{
		read(fd, &buff, BUFF_SIZE);
		s_str = ft_lstnew(fd, buff, 0);
	}
	else if (fd != s_fd_stack -> id)
	{
		if (read(fd, &buff, BUFF_SIZE))
		{
			s_str = ft_lstnew(fd, buff, 1);
			if (s_str != NULL)
				s_fd_stack -> next = s_str;
		}
	}
	return (NULL);
}

char	*ft_get_next_line(int fd)
{
	char			*heap;
	static struct_t	*fd_stack;

	heap = (char *)malloc((BUFF_SIZE + 1) * sizeof(char));
	if (fd >= 65536 || fd < 0 || !heap)
		return (NULL);
	if (!ft_call_struct(heap, fd, fd_stack)
		return (NULL);
	heap[BUFF_SIZE] = 0;
	return (heap);
}
