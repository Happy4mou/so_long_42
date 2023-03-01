/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:39:11 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/02/01 17:58:23 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_flline(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j])
	{
		if (map[i][j] == '1' && map[i][j])
			j++;
		else
		{
			write(2, "Error\nmap invalide!\n", 21);
			exit(0);
		}
	}
}

void	ft_check_wall(char **map)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	len = ft_strlen(map[i]) - 1;
	ft_check_flline(map, i);
	i++;
	while (map[i])
	{
		if (map[i][0] == '1' && map[i][len] == '1')
			i++;
		else
		{
			write(2, "Error\nmap invalide!2\n", 22);
			exit(0);
		}
	}
	i--;
	ft_check_flline(map, i);
}
