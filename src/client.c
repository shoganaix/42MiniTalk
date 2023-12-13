/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:33:17 by msoriano          #+#    #+#             */
/*   Updated: 2023/12/13 11:33:18 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	args_check(int argc, char **argv)
{
	int	i;

	i = -1;
	if (argc != 3)
	{
		ft_printf("Error. Invalid number of parameters");
		exit(EXIT_FAILURE);
	}
	while (argv[1][++i])
	{
		if (!ft_strchr("0123456789", argv[1][i]))
		{
			ft_printf("Error. Incorrect PID!");
			exit(EXIT_FAILURE);
		}
	}
	if (*argv[2] == 0)
	{
		ft_printf("Error. Empty message");
		exit(EXIT_FAILURE);
	}
}

void	send_msg(int sv_pid, char *msg)
{
	unsigned char	c;
	int				nbr_bits;

	while (*msg)
	{
		c = *msg;
		nbr_bits = 8;
		while (nbr_bits--)
		{
			if (c & 0b10000000)
				kill(sv_pid, SIGUSR1);
			else
				kill(sv_pid, SIGUSR2);
			usleep(50);
			c <<= 1;
		}
		msg++;
	}
}

void	sig_handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("Signal coming out! 📟 \n");
}

void	config_signals(void)
{
	struct sigaction	new_sig;

	new_sig.sa_handler = &sig_handler;
	new_sig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &new_sig, NULL) == -1)
		ft_printf("Error. Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &new_sig, NULL) == -1)
		ft_printf("Error. Failed to change SIGUSR2's behavior");
}

int	main(int argc, char **argv)
{
	ft_printf("CLIENT PID = %d\n\n", getpid());
	args_check(argc, argv);
	config_signals();
	send_msg(ft_atoi(argv[1]), argv[2]);
	return (EXIT_SUCCESS);
}
