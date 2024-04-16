/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpesan <lpesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:43:40 by lpesan            #+#    #+#             */
/*   Updated: 2024/04/11 16:05:01 by lpesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"
#include <unistd.h>

void	signal_handler(int signum)
{
	static char	c;
	static int	i;

	if (signum == SIGUSR1)
	{
		c = c << 1;
		i++;
	}
	else if (signum == SIGUSR2)
	{
		c = ((c << 1) | 1);
		i++;
	}
	if (i == 8)
	{
		if (c == 4)
			ft_printf("\n");
		else
			ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset (&sa.sa_mask);
	sa.sa_handler = &signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (ft_printf("Error setting up SIGUSR1 handler\n exiting..."), 1);
	sigaction(SIGUSR2, &sa, NULL);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (ft_printf("Error setting up SIGUSR2 handler\n exiting..."), 1);
	printf("Server is running\nPID = %d\n", getpid());
	while (1)
		sleep(1);
	return (0);
}
