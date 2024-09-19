# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 11:47:23 by bmatos-d          #+#    #+#              #
#    Updated: 2024/07/29 11:22:03 by bmatos-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM = 			rm -rf
COMPILE = 		cc -Wall -Wextra -Werror

#Utility Functions
UTILS_PATH = 	./Utils/utils.a


#Mandatory
SRCC = 			./Mandatory/client.c
SRCCO = 		$(SRCC:.c=.o)
SRCS =			./Mandatory/server.c
SRCSO = 		$(SRCS:.c=.o)
SERVER = 		server
CLIENT = 		client


#Bonus
BSRCC = 		./Bonus/client_bonus.c
BSRCCO = 		$(BSRCC:.c=.o)

BSRCS =			./Bonus/server_bonus.c
BSRCSO = 		$(BSRCS:.c=.o)
SERVER_BONUS =	server_bonus
CLIENT_BONUS =	client_bonus



#Commands

all: $(UTILS_PATH) $(SERVER) $(CLIENT)

bonus: $(UTILS_PATH) $(SERVER_BONUS) $(CLIENT_BONUS)

.c.o:
	$(COMPILE) -c -o $@ $<

$(UTILS_PATH): 
	@$(MAKE) -C ./Utils 

$(SERVER): $(UTILS_PATH) $(SRCSO)
	$(COMPILE) $(SRCSO) $(UTILS_PATH) -o $(SERVER) 


$(CLIENT): $(UTILS_PATH) $(SRCCO)
	$(COMPILE) $(SRCCO) $(UTILS_PATH) -o $(CLIENT) 

$(SERVER_BONUS): $(UTILS_PATH) $(BSRCSO)
	$(COMPILE) $(BSRCSO) $(UTILS_PATH) -o $(SERVER_BONUS) 


$(CLIENT_BONUS): $(UTILS_PATH) $(BSRCCO)
	$(COMPILE) $(BSRCCO) $(UTILS_PATH) -o $(CLIENT_BONUS)
	
re: fclean all 

re_bonus: fclean bonus

clean:
	$(MAKE) clean -C ./Utils && $(RM) $(BSRCSO) $(BSRCCO) $(SRCSO) $(SRCCO)
#clean object files in mandatory and bonus folders

fclean: clean
	$(RM) $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS) \
	&& $(MAKE) fclean -C ./Utils
