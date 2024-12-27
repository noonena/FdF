/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euleow <euleow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:40:04 by euleow            #+#    #+#             */
/*   Updated: 2024/12/15 16:04:49 by euleow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words_space(char const *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (s[i] != ' ' && s[i] != '\0' && s[i] != '\n')
			count++;
		while (s[i] != ' ' && s[i] != '\0')
			i++;
	}
	return (count);
}

char	**freesplitspace(char **s, int pos)
{
	while (pos >= 0)
		free(s[pos--]);
	free(s);
	return (NULL);
}

static int	ft_spacelen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != ' ' && s[i] != '\n')
		i++;
	return (i);
}

char	**ft_split_space(char const *s)
{
	int		i;
	int		start;
	char	**temp;

	i = 0;
	start = 0;
	temp = (char **)malloc(sizeof(char *) * (ft_count_words_space(s) + 1));
	while (s[start] && s[start] != '\n')
	{
		if (s[start] != ' ' && s[start] != '\n')
		{
			temp[i] = ft_substr(s, start, ft_spacelen(&s[start]));
			if (!temp[i])
				return (freesplitspace(temp, i));
			i++;
			start += ft_spacelen(&s[start]);
		}
		else
			start++;
	}
	temp[i] = NULL;
	return (temp);
}
