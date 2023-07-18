/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoudach <bmoudach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:34:18 by bmoudach          #+#    #+#             */
/*   Updated: 2023/07/18 16:34:21 by bmoudach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	fill(char **tab, t_point size, t_point cur)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| (tab[cur.y][cur.x] != 'P' && tab[cur.y][cur.x] != 'C'
			&& tab[cur.y][cur.x] != '0' && tab[cur.y][cur.x] != 'E'))
		return ;
	tab[cur.y][cur.x] = 'X';
	fill(tab, size, (t_point){cur.x - 1, cur.y});
	fill(tab, size, (t_point){cur.x + 1, cur.y});
	fill(tab, size, (t_point){cur.x, cur.y - 1});
	fill(tab, size, (t_point){cur.x, cur.y + 1});
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin);
}

int	valid_char(char **map)
{
	int		i;
	int		j;
	t_point	size;

	i = 0;
	j = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] != 'E' && map[j][i] != 'P' && map[j][i] != 'C'
				&& map[j][i] != '0' && map[j][i] != '1')
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	size.x = ft_strlen(map[0]);
	size.y = j;
	return (flood_fill(map, size, find_p(map)), 1);
}

int	valid_item(char **map)
{
	if (p(map) != 1 || e(map) != 1 || c(map) < 1)
		return (0);
	return (valid_char(map));
}

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
	return (valid_item(map));
}
