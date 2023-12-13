/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:33:02 by msoriano          #+#    #+#             */
/*   Updated: 2023/12/13 11:34:17 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigusr(int signum, siginfo_t *info, void *ucontent)
{
	static int				bit_itr = -1;
	static unsigned char	c;

	(void)ucontent;
	if (bit_itr < 0)
		bit_itr = 7;
	if (signum == SIGUSR1)
		c |= (1 << bit_itr);
	bit_itr--;
	if (bit_itr < 0)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		c = 0;
		if (kill(info->si_pid, SIGUSR1) == -1)
			ft_printf("Error. Server failed to send SIGUSR1");
	}
}

void	config_signals(void)
{
	struct sigaction	sa_newsig;

	sa_newsig.sa_sigaction = &handle_sigusr;
	sa_newsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
		ft_printf("Error. Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &sa_newsig, NULL) == -1)
		ft_printf("Error. Failed to change SIGUSR2's behavior");
}

int	main(void)
{
	ft_printf("SERVER PID = %d\n\n", getpid());
	while (1)
		config_signals();
	return (EXIT_SUCCESS);
}
