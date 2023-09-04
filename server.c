/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:57:07 by msoriano          #+#    #+#             */
/*   Updated: 2023/09/04 19:13:24 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    signal_action(int pid, char *str)
{
    int    i;
    int    c;
    i = 0;
    while (*str)
    {
        c = *(str);
        while (i < 8)
        {
            if (c << i & 0b10000000)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            i++;
            usleep(100);
        }
        str++;
        i = 0;
    }
}

int    main(int argc, char **argv)
{
    if (argc != 3)
    {
        ft_printf("Invalid number of arguments.\n");
        ft_printf("Format: [./client <SERVER ID (PID)> <STRING>]\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        signal_action(ft_atoi(argv[1]), argv[2]);
    }
    return (0);
}
