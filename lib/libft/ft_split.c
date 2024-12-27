/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euleow <euleow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:29:43 by euleow            #+#    #+#             */
/*   Updated: 2024/12/15 16:38:22 by euleow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char sep)
{
	int	phrase_count;
	int	i;

	i = 0;
	phrase_count = 0;
	while (s[i])
	{
		if (s[i] != sep && (s[i + 1] == sep || s[i + 1] == '\0'))
			phrase_count++;
		i++;
	}
	return (phrase_count);
}

static int	len(const char *s, char sep)
{
	int	i;

	i = 0;
	while (*s && *s != sep)
	{
		i++;
		s++;
	}
	return (i);
}

static char	**freesplit(char **str, int n)
{
	while (n >= 0)
		free(str[n--]);
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**temp;
	int		start;
	int		i;

	start = 0;
	i = 0;
	temp = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!s || !temp)
		return (NULL);
	while (s[start])
	{
		if (s[start] != c)
		{
			temp[i] = ft_substr(s, start, len(&s[start], c));
			if (!temp[i])
				return (freesplit(temp, i));
			i++;
			start += len(&s[start], c);
		}
		else
			start++;
	}
	temp[i] = NULL;
	return (temp);
}
