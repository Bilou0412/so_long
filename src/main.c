/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoudach <bmoudach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:26:52 by bmoudach          #+#    #+#             */
/*   Updated: 2023/07/21 14:18:35 by bmoudach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../mlx_linux/mlx.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		i;
	t_data	data;

	i = 0;
	if (argc == 2)
	{
		data.map = fill_map(argv[1]);
		if (!data.map)
			return (0);
		if (!valid_wall(data.map))
			return (free_tab(data.map, 0), 0);
		main_graphic(data);
	}
	else
		return (0);
	return (free_tab(data.map, i), 0);
}
