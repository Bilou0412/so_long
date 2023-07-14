/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoudach <bmoudach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 22:02:19 by bmoudach          #+#    #+#             */
/*   Updated: 2023/07/14 14:16:30 by bmoudach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	info_map(char *pathname, int *number_of_line, int *number_of_char)
{
	int		fd;
	char	*str;
	int		error;

	error = 0;
	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		return (-1);
	str = get_next_line(fd, &error);
	while (str && str[0] == '\n')
	{
		free(str);
		str = get_next_line(fd, &error);
	}
	while (str && str[0] != '\n')
	{
		*number_of_line = *number_of_line + 1;
		if (*number_of_line == 1)
			*number_of_char = ft_strlen(str) - 1;
		free(str);
		str = get_next_line(fd, &error);
	}
	while (str && str[0] == '\n')
	{
		free(str);
		str = get_next_line(fd, &error);
	}
	if (!str && error == 0)
		return (close(fd), free(str), 0);
	return (close(fd), free(str), -1);
}

char	**malloc_map(char *pathname)
{
	int		number_of_line;
	int		number_of_char;
	int		i;
	char	**map;

	number_of_char = 0;
	number_of_line = 0;
	i = 0;
	if (info_map(pathname, &number_of_line, &number_of_char))
		return (NULL);
	map = malloc((number_of_line + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	while (number_of_line > i)
	{
		map[i] = malloc((number_of_char + 1) * sizeof(char));
		if (!map[i])
			return (free_tab(map, i), NULL);
		i++;
	}
	return (map);
}

char	**fill_map(char *pathname)
{
	char	**map;
	int		fd;
	char	*str;
	int		i;
	int		j;
	int		error;

	i = 0;
	j = 0;
	error = 0; 
	map = malloc_map(pathname);
	if (!map)
		return (NULL);
	fd = open(pathname, O_RDONLY);
	if (fd < 0)
		return (NULL);
	str = get_next_line(fd, &error);
	while (str && str[0] == '\n')
	{
		free(str);
		str = get_next_line(fd, &error);
	}
	while (str && str[0] != '\n')
	{
		while (str[j] != '\n' && str[j] != '\0')
		{
			map[i][j] = str[j];
			j++;
		}
		map[i][j] = '\0';
		i++;
		j = 0;
		free(str);
		str = get_next_line(fd, &error);
	}
	if (!str && error == 1)
		return (close(fd), NULL);
	free(str);
	map[i] = NULL;
	close(fd);
	return (map);
}
