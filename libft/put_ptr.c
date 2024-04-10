/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ptr.c                                 :+:      :+:    :+:   		  */
/*                                                    +:+ +:+         +:+     */
/*   By: lpesan <lpesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:50:48 by lpesan            #+#    #+#             */
/*   Updated: 2024/02/28 15:22:49 by lpesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	h_digits(uintptr_t n)
{
	size_t	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		digits += 1;
		n /= 16;
	}
	return (digits);
}

void	put_hexa_ptr(uintptr_t nbr, char ident)
{
	static char	upper_digits[] = "0123456789ABCDEF";
	static char	lower_digits[] = "0123456789abcdef";

	if (nbr >= 16)
		put_hexa_ptr((nbr / 16), ident);
	if (ident == 'X')
		write(STDOUT_FILENO, &upper_digits[nbr % 16], 1);
	else
		write(STDOUT_FILENO, &lower_digits[nbr % 16], 1);
}

size_t	put_ptr(void *addr, char ident)
{
	if (addr == NULL)
		return (write(STDOUT_FILENO, "(nil)", 5));
	write(STDOUT_FILENO, "0x", 2);
	put_hexa_ptr((uintptr_t) addr, ident);
	return (h_digits((uintptr_t)addr) + 2);
}
