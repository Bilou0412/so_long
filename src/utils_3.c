/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoudach <bmoudach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:16:54 by bmoudach          #+#    #+#             */
/*   Updated: 2023/07/21 16:02:13 by bmoudach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	p_pos(t_data *data)
{
	data->pos_px = 0;
	data->pos_py = 0;
	while (data->map[data->pos_py])
	{
		while (data->map[data->pos_py][data->pos_px])
		{
			if (data->map[data->pos_py][data->pos_px] == 'P')
				return ;
			data->pos_px++;
		}
		data->pos_px = 0;
		data->pos_py++;
	}
}

void	move(t_data *data, int x, int y)
{
	if (data->map[data->pos_py + y][data->pos_px + x] == '1')
		return ;
    else if(data->map[data->pos_py + y][data->pos_px + x] == 'E' && data->count_c > 0)
        return;
	else
	{
	    if (data->map[data->pos_py + y][data->pos_px + x] == 'C')
            data->count_c--;
	    if (data->map[data->pos_py + y][data->pos_px + x] == 'E' && data->count_c == 0)
            exit_and_free(data);          
		data->map[data->pos_py][data->pos_px] = '0';
		data->map[data->pos_py + y][data->pos_px + x] = 'P';
		data->pos_px = data->pos_px + x;
		data->pos_py = data->pos_py + y;
		display_map(data);
	}
}