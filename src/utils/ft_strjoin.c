/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:49:09 by ibondarc          #+#    #+#             */
/*   Updated: 2024/12/27 12:53:56 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		s1_len;
	int		s2_len;
	int		total_len;

	if (!s1 || !s2)
		return (NULL);
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
