/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpesan <lpesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:50:48 by lpesan            #+#    #+#             */
/*   Updated: 2024/02/28 15:22:49 by lpesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	int_len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	put_nbr(int n)
{
	char	prnt;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		prnt = '-';
		write(1, &prnt, 1);
		n = -n;
	}
	if (n > 9)
	{
		put_nbr(n / 10);
		put_nbr(n % 10);
	}
	else
	{
		prnt = n + '0';
		write(1, &prnt, 1);
	}
}

int	put_int(int n)
{
	put_nbr(n);
	return (int_len(n));
}
