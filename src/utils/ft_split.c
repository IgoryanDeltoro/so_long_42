/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:07:05 by ibondarc          #+#    #+#             */
/*   Updated: 2024/12/27 12:55:59 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	flag;

	flag = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && !flag)
		{
			flag = 1;
			count++;
		}
		else if (*s == c)
		{
			flag = 0;
		}
		s++;
	}
	return (count);
}

static char	*malloc_word(const char *start, int len)
{
	char	*word;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, start, len + 1);
	return (word);
}

static char	**hendle_words(char **dest, char const *s, char c)
{
	int			i;
	int			len;
	const char	*start;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			len = 0;
			while (*s && *s != c)
			{
				len++;
				s++;
			}
			dest[i] = malloc_word(start, len);
			if (!dest[i])
				return (free_alocated_memory(dest, i));
			i++;
		}
		else
			s++;
	}
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**arr;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	arr[words] = NULL;
	arr = hendle_words(arr, s, c);
	return (arr);
}
