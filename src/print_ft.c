/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euleow <euleow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:18:30 by euleow            #+#    #+#             */
/*   Updated: 2024/12/15 20:37:47 by euleow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(void)
{
	write(1, "Error occurs/n", 13);
	exit(0);
}
