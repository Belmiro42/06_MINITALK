/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:47:12 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/05/30 14:44:29 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

int			ft_printf(char const *str, ...);
void		do_x(unsigned int hex, char c,
				unsigned int *index, unsigned int *length);
void		do_u(unsigned int n, unsigned int *index,
				unsigned int *length, unsigned int iteration);
void		do_i(int n, unsigned int *length,
				unsigned int *index, int iteration);
void		do_s(char *c, unsigned int *index, unsigned int *length);
void		do_p(void *number, unsigned int *index, unsigned int *length);
void		do_n(char const *s, unsigned int *index, unsigned int *length);
void		do_c(char c, unsigned int *length, unsigned int *index);
int			ft_atoi(const char *str);
int			ft_isdigit(unsigned short c);
void		handle_errors(char *error_msg);
size_t		ft_strlen(const char *str);


#endif