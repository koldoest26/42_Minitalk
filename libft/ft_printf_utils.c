/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luestira <luestira@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:23:57 by luestira          #+#    #+#             */
/*   Updated: 2025/01/28 17:32:44 by luestira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c, int *count)
{
	*count += write(1, &c, 1);
}

void	ft_putstr(char *str, int *count)
{
	if (str == NULL)
		str = "(null)";
	while (*str)
		*count += write(1, &(*str++), 1);
}

void	ft_putnbr_base(long long int n, int b_len, int *count, char *base)
{
	if (n < 0)
	{
		n *= -1;
		*count += write(1, "-", 1);
	}
	if (n >= b_len)
		ft_putnbr_base(n / b_len, b_len, count, base);
	ft_putchar(base[n % b_len], count);
}

void	ft_putunsnbr_base(unsigned long n, size_t b_len, int *count, char *base)
{
	if (n >= b_len)
		ft_putunsnbr_base(n / b_len, b_len, count, base);
	ft_putchar(base[n % b_len], count);
}

void	ft_printptr(void *ptr, int *count)
{
	unsigned long	num;

	if (!ptr)
	{
		ft_putstr("(nil)", count);
		return ;
	}
	num = (unsigned long) ptr;
	ft_putstr("0x", count);
	ft_putunsnbr_base(num, 16, count, "0123456789abcdef");
}
