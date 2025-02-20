/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luestira <luestira@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:56:26 by luestira          #+#    #+#             */
/*   Updated: 2024/10/08 14:56:04 by luestira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*dest;
	char	*src;

	dest = (char *) s1;
	src = (char *) s2;
	if (s1 == s2)
		return (s1);
	else if (s1 > s2)
	{
		dest += n;
		src += n;
		while (n)
		{
			dest--;
			src--;
			*dest = *src;
			n--;
		}
	}
	else
	{
		return (ft_memcpy(s1, s2, n));
	}
	return (s1);
}
