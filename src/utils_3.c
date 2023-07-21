/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoudach <bmoudach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:16:54 by bmoudach          #+#    #+#             */
/*   Updated: 2023/07/21 16:15:10 by bmoudach         ###   ########.fr       */
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
    static int i;
    
	if (data->map[data->pos_py + y][data->pos_px + x] == '1')
		return ;
    else if(data->map[data->pos_py + y][data->pos_px + x] == 'E' && data->count_c > 0)
        return;
	else
	{
        i++;
	    if (data->map[data->pos_py + y][data->pos_px + x] == 'C')
            data->count_c--;
	    if (data->map[data->pos_py + y][data->pos_px + x] == 'E' && data->count_c == 0)
            exit_and_free(data);          
		data->map[data->pos_py][data->pos_px] = '0';
		data->map[data->pos_py + y][data->pos_px + x] = 'P';
		data->pos_px = data->pos_px + x;
		data->pos_py = data->pos_py + y;
        ft_putnbr(i);
        write(1, "\n", 1);
		display_map(data);
	}
}
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void ft_putnbr(int n)
{
	long int	nb;

	nb = (long int)n;
	if (nb < 0)
	{
		nb = nb * -1;
		write(1, "-", 1);
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	if (nb <= 9)
	{
		ft_putchar(nb + '0');
	}
}