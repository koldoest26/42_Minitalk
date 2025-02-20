/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luestira <luestira@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:39:09 by luestira          #+#    #+#             */
/*   Updated: 2024/10/08 14:16:12 by luestira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		count;
	char	*sptr;

	count = ft_strlen(s);
	sptr = (char *)s;
	while (count >= 0)
	{
		if (sptr[count] == (char)c)
		{
			return (&sptr[count]);
		}
		count--;
	}
	return (NULL);
}
