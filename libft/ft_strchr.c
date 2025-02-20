/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luestira <luestira@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:21:37 by luestira          #+#    #+#             */
/*   Updated: 2024/10/08 13:04:35 by luestira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int i)
{
	int		count;
	char	*ps;

	ps = (char *)s;
	count = 0;
	while (ps[count] != '\0')
	{
		if ((char)ps[count] == (char)i)
			return (&ps[count]);
		count++;
	}
	if ((char)i == '\0')
		return (&ps[count]);
	return (NULL);
}
