/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luestira <luestira@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:05:59 by luestira          #+#    #+#             */
/*   Updated: 2024/10/10 20:13:41 by luestira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static void	ft_free_split(char **lst, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(lst[i]);
		i++;
	}
	free(lst);
}

static char	*ft_get_next_word(char const **s, char c)
{
	size_t	word_len;
	char	*word;

	while (**s == c)
		(*s)++;
	if (!ft_strchr(*s, c))
		word_len = ft_strlen(*s);
	else
		word_len = ft_strchr(*s, c) - *s;
	word = ft_substr(*s, 0, word_len);
	*s += word_len;
	return (word);
}

static char	**ft_split_words(char const *s, char c, char **lst, int word_count)
{
	int	i;

	i = 0;
	while (*s && i < word_count)
	{
		lst[i] = ft_get_next_word(&s, c);
		if (!lst[i])
		{
			ft_free_split(lst, i);
			return (NULL);
		}
		i++;
	}
	lst[i] = NULL;
	return (lst);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = ft_countword(s, c);
	lst = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!lst)
		return (NULL);
	return (ft_split_words(s, c, lst, word_count));
}
