/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoudach <bmoudach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:16:30 by bmoudach          #+#    #+#             */
/*   Updated: 2023/07/15 18:16:54 by bmoudach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	valid_wall(char **map)
{
	int	i;
	int	j;
	int	x;

	j = 0;
	i = 0;
	x = 2;
	while (x--)
	{
		while (map[j][i])
		{
			if (map[j][i++] != '1')
				return (0);
		}
		j = number_line(map) - 1;
		i = 0;
	}
	j = 0;
	while (map[j])
	{
		if (map[j][0] != '1' || map[j][ft_strlen(map[j]) - 1] != '1')
			return (0);
		j++;
	}
	return (1);
}
