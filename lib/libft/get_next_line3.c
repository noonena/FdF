/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euleow <euleow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:33:27 by euleow            #+#    #+#             */
/*   Updated: 2024/12/15 15:49:37 by euleow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, char *s2, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	while (i < size)
	{
		s1[i] = '\0';
		i++;
	}
	return (s1);
}

int	list_length(t_list **list)
{
	t_list	*node;
	int		len;

	len = 0;
	node = *list;
	while (node)
	{
		len += ft_strlen(node->context);
		node = node->next;
	}
	return (len);
}

char	*combine_tostring(t_list **list)
{
	char	*line;
	t_list	*node;
	t_list	*temp;
	int		offset;

	offset = 0;
	if (*list == NULL)
		return (NULL);
	line = (char *)malloc((list_length(list)) + 1);
	if (!line)
		return (NULL);
	node = *list;
	while (node)
	{
		ft_strncpy(&line[offset], node->context, ft_strlen(node->context));
		offset += ft_strlen(node->context);
		temp = node;
		node = node->next;
		free(temp->context);
		free(temp);
	}
	line[offset] = '\0';
	*list = NULL;
	return (line);
}
