# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 11:47:23 by bmatos-d          #+#    #+#              #
#    Updated: 2024/05/30 23:00:16 by bmatos-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM =			rm -rf
UTILITIES = 	utils.a
UTILS = 		ft_printf.c 	\
				do_c.c 			\
				do_i.c 			\
				do_n.c 			\
				do_u.c 			\
				do_p.c 			\
				do_s.c 			\
				do_x.c 			\
				ft_atoi.c 		\
				handle_errors.c \
				ft_strlen.c 	\
				ft_isdigit.c	

UTILS_OBJ=		$(UTILS:.c=.o)

$(UTILITIES): $(UTILS_OBJ)
			ar rcs $(UTILITIES) $(UTILS_OBJ)

.c.o:
	cc -Wall -Werror -Wextra -c -o $@ $<

all: @$(UTILITIES)

clean:
	$(RM) $(UTILS_OBJ)

fclean: clean
	$(RM) $(UTILITIES)
 
re: fclean all