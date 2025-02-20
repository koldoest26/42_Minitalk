/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luestira <luestira@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:41:23 by luestira          #+#    #+#             */
/*   Updated: 2024/10/08 13:16:52 by luestira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		j;
	int		i;
	char	*s_new;

	len = ft_strlen(s1) + ft_strlen(s2);
	s_new = malloc((len + 1) * sizeof(char));
	if (!s_new)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s_new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		s_new[i] = s2[j];
		i++;
		j++;
	}
	s_new[i] = '\0';
	return (s_new);
}
