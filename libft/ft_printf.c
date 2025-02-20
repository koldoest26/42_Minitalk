/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luestira <luestira@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:33:46 by luestira          #+#    #+#             */
/*   Updated: 2025/01/28 17:32:24 by luestira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_what_is(char c, va_list ap, int *count)
{
	if (c == '%')
		*count += write(1, "%", 1);
	else if (c == 'c')
		ft_putchar(va_arg(ap, int), count);
	else if (c == 's')
		ft_putstr(va_arg(ap, char *), count);
	else if (c == 'p')
		ft_printptr(va_arg(ap, void *), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr_base((long long int)va_arg(ap, int), 10, count, "0123456789");
	else if (c == 'u')
		ft_putnbr_base((long long int)va_arg(ap, unsigned int), 10, \
			count, "0123456789");
	else if (c == 'x')
		ft_putnbr_base(va_arg(ap, unsigned int), 16, count, "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_base(va_arg(ap, unsigned int), 16, count, "0123456789ABCDEF");
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_what_is(*str, ap, &count);
		}
		else
			count += write(1, &(*str), 1);
		str++;
	}
	va_end(ap);
	return (count);
}
