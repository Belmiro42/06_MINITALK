/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_i.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:12:07 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/05/30 12:27:56 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	do_i(int p, unsigned int *length, unsigned int *index, int iteration)
{
	char		c;
	long int	n;

	n = (long int)p;
	if (n < 0)
	{
		*length += write(1, "-", 1);
		n = -n;
	}
	if (n / 10)
		do_i(n / 10, length, index, iteration + 1);
	c = '0' + n % 10;
	if (!iteration)
		*index += 2;
	*length += write(1, &c, 1);
}
