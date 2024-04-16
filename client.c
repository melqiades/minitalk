/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpesan <lpesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:43:44 by lpesan            #+#    #+#             */
/*   Updated: 2024/04/16 18:44:32 by lpesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./libft/libft.h"

int	decom_num(char num, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((num >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		usleep(600);
	}
	return (1);
}

int	main(int ac, char *av[])
{
	int	pid;
	int	i;

	i = 0;
	if (ac != 3)
		return (ft_printf("\n[Error] You have to use two arguments.\n"), 1);
	pid = ft_atoi(av[1]);
	if (pid == 0)
		return (ft_printf("error getting PID of server\n exiting...\n"), 1);
	while (av[2][i])
	{
		decom_num(av[2][i++], pid);
	}
	decom_num(4, pid);
}
