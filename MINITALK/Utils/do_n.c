/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_n.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:10:16 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/05/30 12:28:01 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	do_n(char const *s, unsigned int *index, unsigned int *length)
{
	(*length) += write(1, &s[*index], 1);
	(*index) += 1;
	if (s[*index - 1] == '%' && s[*index] == '%')
		(*index) += 1;
}
