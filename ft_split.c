/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:22:13 by mchiacha          #+#    #+#             */
/*   Updated: 2025/11/06 12:05:17 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*word_dup(const char *s, size_t start, size_t len)
{
	char	*p;
	size_t	i;

	*p = malloc(len + 1);
	i = 0;
	if (!p)
		return (NULL);
	while (i < len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;
	size_t	words;
	char	**res;

	i = 0;
	j = 0;
	start = 0;
	words = count_words(s, c);
	res = malloc((words + 1) * sizeof(char *));
	if (!res || !s)
		return (NULL);
	while (s[i] && s[i] == c)
		i++;
	start = i;
	while (s[i] && s[i] != c)
		i++;
	res[j++] = word_dup(s, start, i - start);
	if (!res[j - 1])
	{
		while (j--) 
			free(res[j]);
			free(res);
		return (NULL);
	}
	res[j] = NULL;
	return (res);
}
