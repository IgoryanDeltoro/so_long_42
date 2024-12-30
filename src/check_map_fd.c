/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:39:10 by marvin            #+#    #+#             */
/*   Updated: 2024/12/27 15:39:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int check_map_fd(char *str)
{
    int len;

    len = ft_strlen(str);
    if (ft_strcmp(&str[len - 4], ".ber") != 0)
        return (print_error("WN"), -1);
    if (len < 4)
        return (print_error("TSN"), -1);
    return (1);
}