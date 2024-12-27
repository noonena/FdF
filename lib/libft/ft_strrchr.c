/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euleow <euleow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:49:21 by euleow            #+#    #+#             */
/*   Updated: 2024/12/15 16:38:35 by euleow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*temp;

	temp = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			temp = (char *) &s[i];
		}
		i++;
	}
	if (s[i] == (char)c)
		temp = (char *) &s[i];
	return (temp);
}
