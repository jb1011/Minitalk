/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 08:45:34 by jdemenet          #+#    #+#             */
/*   Updated: 2021/07/21 08:45:44 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (((c >> i) & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

void	ft_send(char *str, int pid)
{
	int	i;

	i = 0;
	while (ft_isprint(str[i]))
	{
		send_char(str[i], pid);
		i++;
	}
	if (str[i] == 0)
		send_char(str[i], pid);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		ft_send(argv[2], pid);
	}
	else
		ft_putstr_fd("please put PID then message", 0);
}
