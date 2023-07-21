/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoudach <bmoudach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:29:37 by bmoudach          #+#    #+#             */
/*   Updated: 2023/07/21 15:48:56 by bmoudach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*textures[5];
	char	**map;
	int		size_ximg;
	int		size_yimg;
	int		pos_px;
	int		pos_py;
	int		count_c;
}			t_data;

char		*get_next_line(int fd, int *error);
void		free_tab(char **tab, int until);
char		**fill_map(char *pathname);
int			ft_strlen(char *str);
int			ft_strlen_param(char *str, char c, int *error);
int			valid_wall(char **map);
int			number_line(char **map);
int			valid_ext_map(char *pathname);
int			p(char **map);
int			e(char **map);
int			c(char **map);
t_point		find_p(char **map);
int			way(char **map);
char		**ft_strdup_two_d(char **tab);
int			main_graphic(t_data data);
int			exit_and_free(t_data *data);
void		p_pos(t_data *data);
void		display_map(t_data *data);
void		move(t_data *data, int x, int y);

#endif