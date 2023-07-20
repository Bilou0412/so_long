/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoudach <bmoudach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:26:52 by bmoudach          #+#    #+#             */
/*   Updated: 2023/07/18 20:43:23 by bmoudach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../mlx_linux/mlx.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	**map;
	int		i;

	i = 0;
	if (argc == 2)
	{
		map = fill_map(argv[1]);
		if (!map)
			return (0);
		if (!valid_wall(map))
			return (free_tab(map, 0), 0);
		while (map[i])
		{
			printf("%s\n", map[i]);
			i++;
		}
	}
	else
		return (0);
	return (free_tab(map, i), 0);
}
