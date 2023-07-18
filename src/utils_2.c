/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoudach <bmoudach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:01:28 by bmoudach          #+#    #+#             */
/*   Updated: 2023/07/18 17:24:42 by bmoudach         ###   ########.fr       */
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
    copy[y] = '\0';
	return (copy);
}
