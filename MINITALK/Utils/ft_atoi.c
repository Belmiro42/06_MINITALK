/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:47:45 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/05/30 12:28:26 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "utils.h"

int	ft_atoi(const char *str)
{
	int		number;
	int		valence;

	valence = 1;
	number = 0;
	while (((*str >= 9 && *str <= 13) || *str == ' ') && *str++)
		;
	if ((*str == '+' || (*str == '-' && valence-- && --valence)) && *str++)
		;
	while ((48 <= *str && *str <= 57))
		number = number * 10 + (*str++ - '0');
	return (number * valence);
}
/*
int main(void)
{
    char str[] = "       -123as213";
    int p = ft_atoi(str);
    printf("The value of x is %d\n", p);
}
*/
