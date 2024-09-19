/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:13:26 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/05/30 12:28:15 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	do_s(char *c, unsigned int *index, unsigned int *length)
{
	unsigned int	index_s;

	index_s = 0;
	if (c == NULL)
	{
		write(1, "(null)", 6);
		*length += 6;
		*index += 2;
		return ;
	}
	while (c[index_s])
	{
		write(1, &c[index_s++], 1);
		(*length) += 1;
	}
	*index += 2;
}
