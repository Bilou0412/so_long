/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoudach <bmoudach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:59:37 by bmoudach          #+#    #+#             */
/*   Updated: 2023/07/18 17:16:13 by bmoudach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	c(char **map)
{
	int	c;
	int	i;
	int	j;

	c = 0;
	i = 0;
	j = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				c++;
			i++;
		}
		i = 0;
		j++;
	}
	return (c);
}

int	e(char **map)
{
	int	e;
	int	i;
	int	j;

	e = 0;
	i = 0;
	j = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == 'E')
				e++;
			i++;
		}
		i = 0;
		j++;
	}
	return (e);
}

int	p(char **map)
{
	int	p;
	int	i;
	int	j;

	p = 0;
	i = 0;
	j = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == 'P')
				p++;
			i++;
		}
		i = 0;
		j++;
	}
	return (p);
}

t_point	find_p(char **map)
{
	t_point	begin;

	begin.x = 0;
	begin.y = 0;
	while (map[begin.y])
	{
		while (map[begin.y][begin.x])
		{
			if (map[begin.y][begin.x] == 'P')
				return (begin);
			begin.x++;
		}
		begin.x = 0;
		begin.y++;
	}
	return (begin);
}

int	way(char **map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'E' || map[y][x] == 'C')
				return (free_tab(map, 0) ,0);
			x++;
		}
		x = 0;
		y++;
	}
	return (free_tab(map, 0),1);
}