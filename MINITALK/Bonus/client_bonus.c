/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:47:25 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/05/30 22:47:48 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

//check for error in the arguments
void	args_check(int argc, char **argv)
{
	int i;

	i = 0;
	//check 3 params
	if (argc != 3)
		handle_errors("INVALID NUMBER OF ARGUMENTS");
	//check pid is all num
	while (argv[1][i])
		if (!ft_isdigit(argv[1][i++]))
			handle_errors("INVALID PID");
	//check message not empty
	if (!*argv[2])
		handle_errors("TEXT EMPTY");
}

//how to send a message
void	send_msg(pid_t server_pid, char *text)
{
	unsigned char	character;
	int 			bit_index_r;

	//for each character in the message, and for each bit in the 
	//character send1 if one and 0 if 0
	while (*text)
	{
		character = *text;
		bit_index_r = 8;
		while (bit_index_r--)
		{
			if (character & 0b10000000)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			usleep(500);
			character <<= 1;
		}
		text++;
	}
}

//what happens when we get a signal back
void	sig_handler(int signum)
{
	//if recieving sigusr2 print character recieved
	if (signum == SIGUSR2)
		ft_printf("CHARACTER RECIEVED\n");
}

//self explanatory but configure what happens when signal is recieved
void	config_signals(void)
{
	//Create a new struct STRU
	struct sigaction client;

	//Define sigaction function as handle sigsur
	client.sa_handler = &sig_handler;
	//Use siginfo so we get PID of signal sender
	client.sa_flags = SA_SIGINFO;
	//Change action taken on receipt of sigsur1
	if (sigaction(SIGUSR1, &client, NULL) == -1)
		handle_errors("FAILED TO CONFIGURE SIGUSR1 BEHAVIOUR");
	if (sigaction(SIGUSR2, &client, NULL) == -1)
		handle_errors("FAILED TO CONFIGURE SIGUSR2 BEHAVIOUR");
	//Handle failure for both
}

int	main(int argc, char **argv)
{
	pid_t server_pid;

	//run args check
	args_check(argc, argv);
	//convert arg to int
	server_pid = ft_atoi(argv[1]);
	//run config signals
	config_signals();
	//run send message
	send_msg(server_pid, argv[2]);
	//infinite loop
	while (1)
		pause();
	//return success
	return (EXIT_SUCCESS);
}
