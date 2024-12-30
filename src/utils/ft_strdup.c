/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:17:00 by ibondarc          #+#    #+#             */
/*   Updated: 2024/12/27 12:54:56 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	*ft_strdup(char *s)
{
	char	*result;
	int		s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!result)
		return (NULL);
	result[s_len] = '\0';
	while (s_len--)
		result[s_len] = s[s_len];
	return (result);
}
