/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euleow <euleow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:06:20 by euleow            #+#    #+#             */
/*   Updated: 2024/12/16 00:00:13 by euleow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*create_newnode(char *str, size_t size)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->context = malloc(size + 1);
	if (!newnode->context)
	{
		free(newnode);
		return (NULL);
	}
	ft_strncpy(newnode->context, str, size);
	newnode->context[size] = '\0';
	newnode->next = NULL;
	return (newnode);
}

void	addback_list(t_list **head, char *str, size_t size)
{
	t_list			*currentnode;
	static t_list	*lastnode = NULL;

	currentnode = create_newnode(str, size);
	if (!currentnode)
		return ;
	if (*head == NULL)
		*head = currentnode;
	else
		lastnode->next = currentnode;
	lastnode = currentnode;
}

char	*handle_line(t_list **list, char *str, size_t pos)
{
	char	*line;

	if (str)
		addback_list(list, str, pos + 1);
	line = combine_tostring(list);
	if (!line)
		return (NULL);
	if (pos + 1 < ft_strlen(str))
		addback_list(list, &str[pos + 1], ft_strlen(str) - pos - 1);
	return (line);
}

char	*read_and_process_buffer(int fd, t_list **list, char *char_buffer)
{
	int	readline;
	int	pos;

	while (1)
	{
		readline = read(fd, char_buffer, BUFFER_SIZE);
		if (readline == 0)
			return (combine_tostring(list));
		char_buffer[readline] = '\0';
		pos = loop_find_newline(readline, char_buffer);
		if (pos < readline)
			return (handle_line(list, char_buffer, pos));
		addback_list(list, char_buffer, readline);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*char_buffer;
	char			*remain;

	remain = process_remaining_context(&list);
	if (remain)
		return (remain);
	char_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!char_buffer)
		return (NULL);
	remain = read_and_process_buffer(fd, &list, char_buffer);
	free(char_buffer);
	return (remain);
}
