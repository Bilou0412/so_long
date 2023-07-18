/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoudach <bmoudach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:29:37 by bmoudach          #+#    #+#             */
/*   Updated: 2023/07/18 16:25:01 by bmoudach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

char	*get_next_line(int fd, int *error);
void	free_tab(char **tab, int until);
char	**fill_map(char *pathname);
int		ft_strlen(char *str);
int		ft_strlen_param(char *str, char c, int *error);
int		valid_wall(char **map);
int		number_line(char **map);
int		p(char **map);
int		e(char **map);
int		c(char **map);
t_point	find_p(char **map);

#endif