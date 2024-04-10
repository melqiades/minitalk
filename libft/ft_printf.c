/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                 :+:      :+:    :+:		  */
/*                                                    +:+ +:+         +:+     */
/*   By: lpesan <lpesan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:50:48 by lpesan            #+#    #+#             */
/*   Updated: 2024/02/28 15:22:49 by lpesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	put_str(char *str)
{
	if (str == NULL)
		return (write(1, "(null)", 6));
	else
		return (write(1, str, ft_strlen(str)));
}

int	ft_prt(char ident, va_list args)
{
	if (ident == '%')
		return (write(1, "%", 1));
	if (ident == 'c')
	{
		ft_putchar_fd((char)va_arg(args, int), 1);
		return (1);
	}
	if (ident == 's')
		return (put_str(va_arg(args, char *)));
	if (ident == 'p')
		return (put_ptr(va_arg(args, void *), 'x'));
	if (ident == 'd' || ident == 'i')
		return (put_int(va_arg(args, int)));
	if (ident == 'u')
		return (put_int_uns(va_arg(args, unsigned int)));
	if (ident == 'x' || ident == 'X')
		return (put_hex(va_arg(args, int), ident));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += ft_prt(format[i], args);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			i++;
			len++;
		}
	}
	return (len);
}
