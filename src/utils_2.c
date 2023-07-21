/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoudach <bmoudach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:01:28 by bmoudach          #+#    #+#             */
/*   Updated: 2023/07/21 14:15:57 by bmoudach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**malloc_two_d(char **tab)
{
	char	**copy;
	int		num_line;
	int		i;

	i = 0;
	num_line = number_line(tab);
	copy = malloc((num_line + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	while (i < num_line)
	{
		copy[i] = malloc((ft_strlen(tab[0]) + 1) * sizeof(char));
		if (!copy[i])
			return (free_tab(copy, i), NULL);
		i++;
	}
	return (copy);
}

char	**ft_strdup_two_d(char **tab)
{
	char	**copy;
	int		x;
	int		y;

	x = 0;
	y = 0;
	copy = malloc_two_d(tab);
	if (!copy)
		return (NULL);
	while (tab[y])
	{
		while (tab[y][x])
		{
			copy[y][x] = tab[y][x];
			x++;
		}
		copy[y][x] = '\0';
		x = 0;
		y++;
	}
	copy[y] = NULL;
	return (copy);
}

int	valid_ext_map(char *pathname)
{
	int	last_index;

	last_index = ft_strlen(pathname) - 1;
	if (pathname[last_index] != 'r' || pathname[last_index - 1] != 'e'
		|| pathname[last_index - 2] != 'b' || pathname[last_index - 3] != '.')
		return (0);
	else
		return (1);
}

void	mlx_destroy_image_if_exists(void *mlx_ptr, void *img)
{
	if (img)
		mlx_destroy_image(mlx_ptr, img);
}

int	exit_and_free(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
		free(data->map[i++]);
	free(data->map);
	mlx_destroy_image_if_exists(data->mlx_ptr, data->textures[0]);
	mlx_destroy_image_if_exists(data->mlx_ptr, data->textures[1]);
	mlx_destroy_image_if_exists(data->mlx_ptr, data->textures[2]);
	mlx_destroy_image_if_exists(data->mlx_ptr, data->textures[3]);
	mlx_destroy_image_if_exists(data->mlx_ptr, data->textures[4]);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	exit(EXIT_SUCCESS);
}
