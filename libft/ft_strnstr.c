/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luestira <luestira@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:48:16 by luestira          #+#    #+#             */
/*   Updated: 2024/10/08 15:05:15 by luestira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t n)
{
	size_t	i;
	size_t	j;
	char	*b;
	char	*l;

	i = 0;
	b = (char *)big;
	l = (char *)small;
	if (*small == '\0')
		return (b);
	while (b[i] != '\0' && i < n)
	{
		if (b[i] == l[0])
		{
			j = 0;
			while (b[j] != '\0' && b[i + j] == l[j] && (i + j) < n)
			{
				j++;
				if (l[j] == '\0')
					return (&b[i]);
			}
		}
		i++;
	}
	return (NULL);
}
