/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_B.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:49:35 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/02/10 16:09:40 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_B.h"

void	ft_check_path(char **map, int y, int x, t_principal *m)
{
	if (map[y][x] == '1' || map[y][x] == 'E')
		return ;
	map[y][x] = '1';
	ft_check_path(map, y + 1, x, m);
	ft_check_path(map, y - 1, x, m);
	ft_check_path(map, y, x - 1, m);
	ft_check_path(map, y, x + 1, m);
}

void	ft_check_path_e(char **map, int y, int x, t_principal *m)
{
	if (map[y][x] == '1')
		return ;
	map[y][x] = '1';
	ft_check_path_e(map, y + 1, x, m);
	ft_check_path_e(map, y - 1, x, m);
	ft_check_path_e(map, y, x - 1, m);
	ft_check_path_e(map, y, x + 1, m);
}

void	ft_check_ce(t_principal *m)
{
	int	i;
	int	j;

	i = 0;
	while (m->flod[i])
	{
		j = 0;
		while (m->flod[i][j])
		{
			if (m->flod[i][j] == 'C' || m->flode[i][j] == 'E')
				(write(2, "Error\ninvalide path!\n", 22), exit(1));
			j++;
		}
		i++;
	}
}

void	ft_check_path1(t_principal *m)
{
	int	i;

	i = 0;
	ft_check_path(m->flod, m->pos.y, m->pos.x, m);
	ft_check_path_e(m->flode, m->pos.y, m->pos.x, m);
	ft_check_ce(m);
}
