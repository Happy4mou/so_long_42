/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:51:05 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/02/01 17:51:43 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_len(char **map)
{
	int	i;

	i = 0;
	while (map[i + 1])
	{
		if ((ft_strlen(map[i])) != (ft_strlen(map[i + 1])))
			(write(2, "Error\n map not rectangular!\n", 29), exit(1));
		i++;
	}
}

void	ft_vrf(int c, int p, int e)
{
	if (c < 1)
		(write(2, "Error\n no collectibles found!\n", 31), exit(1));
	if (p != 1)
		(write(2, "Error\nnon or more then one player found!\n", 42), exit(1));
	if (e != 1)
		(write(2, "Error\nnon or more then one exit found!\n", 40), exit(1));
}

void	ft_count(char c, int i, int j, t_principal *count)
{
	if (c == 'C')
		count->c++;
	else if (c == 'P')
	{
		count->p++;
		count->pos.y = i;
		count->pos.x = j;
	}
	else if (c == 'E')
	{
		count->e++;
		count->pos.h = i;
		count->pos.g = j;
	}
	else if (c != '1' && c != '0')
		(write(2, "Error\ninvalid map!\n", 20), exit(1));
}

void	ft_check_and_count(char **map, t_principal *count)
{
	int	i;
	int	j;

	count->c = 0;
	count->p = 0;
	count->e = 0;
	i = 0;
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_count(map[i][j], i, j, count);
			j++;
		}
	}
	ft_vrf(count->c, count->p, count->e);
}

void	ft_check_newline(char *map_read)
{
	int	i;

	i = 0;
	if (!map_read[0])
		(write(2, "Error\nempty map\n", 17),
			exit(1));
	while (map_read[i])
	{
		if (map_read[0] == '\n')
		{
			(write(2, "Error\nnew line at the begining!\n", 33),
				exit(1));
		}
		if ((map_read[i] == '\n' && ((map_read[i + 1] == '\n')
					|| map_read[i + 1] == '\0')))
			(write(2, "Error\n new line inside the map or at the end!\n", 47),
				exit(1));
		i++;
	}
}
