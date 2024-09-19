/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:50:41 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/05/30 14:56:57 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	do_stuff(char const *s, va_list args,
			unsigned int *index, unsigned int *length)
{
	if (s[*index] == '%' && s[*index + 1] == 'c')
		do_c((char)(va_arg(args, int)), length, index);
	else if (s[*index] == '%' && s[*index + 1] == 's')
		do_s(va_arg(args, char *), index, length);
	else if (s[*index] == '%' && (s[*index + 1] == 'i' || s[*index + 1] == 'd'))
		do_i(va_arg(args, int), length, index, 0);
	else if (s[*index] == '%' && s[*index + 1] == 'p')
		do_p(va_arg(args, void *), index, length);
	else if (s[*index] == '%' && (s[*index + 1] == 'x' || s[*index + 1] == 'X'))
		do_x(va_arg(args, unsigned int), s[*index + 1], index, length);
	else if (s[*index] == '%' && s[*index + 1] == 'u')
		do_u(va_arg(args, unsigned int), index, length, 0);
	else
		do_n(s, index, length);
}

int	ft_printf(char const *str, ...)
{
	va_list			args;
	unsigned int	index;
	unsigned int	count;

	va_start(args, str);
	index = 0;
	count = 0;
	while (str[index])
	{
		do_stuff(str, args, &index, &count);
	}
	return (count);
}
