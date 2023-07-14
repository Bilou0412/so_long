/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoudach <bmoudach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 00:41:58 by bmoudach          #+#    #+#             */
/*   Updated: 2023/07/11 23:35:09by bmoudach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

void	free_tab(char **tab, int until)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (i < until)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*get_next_line(int fd)
{
	int i = 0;
	int rd = 0;
	char character;
	char *buffer;

	buffer = malloc(100000);
	if(!buffer)
		return (NULL);
	while ((rd = read(fd, &character, 1)) > 0)
	{
		buffer[i++] = character;
		if (character == '\n')
			break ;
	}
	buffer[i] = '\0';
	if (rd == -1 || i == 0 || (!buffer[i - 1] && !rd))
		return (free(buffer), NULL);
	return (buffer);
}