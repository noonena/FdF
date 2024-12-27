/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euleow <euleow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:25:12 by euleow            #+#    #+#             */
/*   Updated: 2024/12/15 15:43:00 by euleow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	loop_find_newline(int str_len, char *char_buffer)
{
	int	pos;

	pos = 0;
	while (pos < str_len)
	{
		if (char_buffer[pos] == '\n')
			break ;
		pos++;
	}
	return (pos);
}

char	*process_remaining_context(t_list **list)
{
	size_t	pos;
	char	*char_buffer;
	char	*line;

	char_buffer = NULL;
	if (*list != NULL)
	{
		pos = loop_find_newline(ft_strlen((*list)->context), (*list)->context);
		if (pos < ft_strlen((*list)->context))
		{
			char_buffer = malloc(ft_strlen((*list)->context) + 1);
			if (!char_buffer)
				return (NULL);
			char_buffer = ft_strncpy(char_buffer, (*list)->context, \
				ft_strlen((*list)->context) + 1);
			free((*list)->context);
			free(*list);
			*list = NULL;
			line = handle_line(list, char_buffer, pos);
			free (char_buffer);
			return (line);
		}
		free (char_buffer);
	}
	return (NULL);
}
