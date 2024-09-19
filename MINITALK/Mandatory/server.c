/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:47:18 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/06/04 11:35:08 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

//build characters from signals recieved in order to compose your message
void	handle_sigusr(int signum, siginfo_t *info, void *ucontent)
{
	//declare bit_index (STATIC)
	static int bit_index = -1;
	//declare c (STATIC)
	static int current_character = 0b00000000;

	//declare ucontent as void so we dont get "unused" error as 
	//handler needs to contain 3 variables
	(void)ucontent;
	(void)info;
	//if we've finished our last character reset bit_index
	if (bit_index < 0)
		bit_index = 7;
	//if sigusr1 set that bit of c to 1
	if (signum == SIGUSR1)
		current_character |= (1 << bit_index);
	//next bit position
	bit_index--;
	//if we've finished reading a character
	if (bit_index < 0)
	{
		//print character to terminal
		write(STDOUT_FILENO, &current_character, 1);
		//reset character
		current_character = 0b00000000;
		//return
		return ;
	}
}

//self explanatory but configure what happens when signal is recieved
void	config_signals(void)
{
	//Create a new struct STRU
	struct sigaction server;
	//Define sigaction function as handle sigsur
	server.sa_sigaction = &handle_sigusr;
	//Use siginfo so we get PID of signal sender
	server.sa_flags = SA_SIGINFO;
	//Change action taken on receipt of sigsur 1 + 2
	if (sigaction(SIGUSR1, &server, NULL) == -1)
		handle_errors("FAILED TO CONFIGURE SIGUSR1 BEHAVIOUR");
	if (sigaction(SIGUSR2, &server, NULL) == -1)
		handle_errors("FAILED TO CONFIGURE SIGUSR2 BEHAVIOUR");
	usleep(100);
	//Handle failure for both
}

int	main(void)
{
	pid_t process_id;
	//Print erver process ID
	process_id = getpid();
	ft_printf("SERVER PID = %d\n\n", process_id);
	//Run Config signals in an infinite loop
	config_signals();
	while (1)
		pause();
	//Return success
	return (EXIT_SUCCESS);
}


