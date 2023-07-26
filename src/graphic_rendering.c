/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_rendering.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoudach <bmoudach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:16:13 by bmoudach          #+#    #+#             */
/*   Updated: 2023/07/25 21:09:57 by bmoudach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	initialise_image(t_data *data)
{
	int	i;

	i = 0;
	data->textures[0] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/0.xpm",
			&(data->size_ximg), &(data->size_yimg));
	data->textures[1] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/1.xpm",
			&(data->size_ximg), &(data->size_yimg));
	data->textures[2] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/C.xpm",
			&(data->size_ximg), &(data->size_yimg));
	data->textures[3] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/E.xpm",
			&(data->size_ximg), &(data->size_yimg));
	data->textures[4] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/P.xpm",
			&(data->size_ximg), &(data->size_yimg));
	while (i < 5)
	{
		if (data->textures[i] == NULL)
		{
			write(2, "Error\nImage no initialise", 26);
			exit_and_free(data);
		}
		i++;
	}
}

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == 65307)
		exit_and_free(data);
	if (keysym == 119 || keysym == 65362)
		move(data, 0, -1);
	if (keysym == 115 || keysym == 65364)
		move(data, 0, 1);
	if (keysym == 97 || keysym == 65361)
		move(data, -1, 0);
	if (keysym == 100 || keysym == 65363)
		move(data, 1, 0);
	return (0);
}

void	display_map_2(t_data *data, int *i, int *j)
{
	if (data->map[*j][*i] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[1],
			(*i * 50), (*j * 50));
	if (data->map[*j][*i] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[0],
			(*i * 50), (*j * 50));
	if (data->map[*j][*i] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[2],
			(*i * 50), (*j * 50));
	if (data->map[*j][*i] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[4],
			(*i * 50), (*j * 50));
	if (data->map[*j][*i] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[3],
			(*i * 50), (*j * 50));
}

void	display_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			display_map_2(data, &i, &j);
			i++;
		}
		i = 0;
		j++;
	}
}

int	main_graphic(t_data data)
{
	init_data(&data);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, ft_strlen(data.map[0]) * 50,
			number_line(data.map) * 50, "hi :)");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	initialise_image(&data);
	display_map(&data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &exit_and_free,
		&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
