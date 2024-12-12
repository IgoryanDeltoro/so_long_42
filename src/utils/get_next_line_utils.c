/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoryan <igoryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:17:00 by ibondarc          #+#    #+#             */
/*   Updated: 2024/12/12 12:49:18 by igoryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int	s1_len;
	int	s2_len;
	int	total_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len;
	result = malloc(sizeof(char) * (total_len + 1));
	if (!result)
		return (NULL);
	result[total_len] = '\0';
	while (s1_len--)
	{
		result[s1_len] = s1[s1_len];
	}
	while (total_len-- > ft_strlen(s1))
	{
		result[total_len] = s2[--s2_len];
	}
	return (result);
}

char	*ft_strdup(char *s)
{
	char	*result;
	int		s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	result = malloc(sizeof(char) * (s_len + 1));
	if (!result)
		return (NULL);
	result[s_len] = '\0';
	while (s_len--)
		result[s_len] = s[s_len];
	return (result);
}


