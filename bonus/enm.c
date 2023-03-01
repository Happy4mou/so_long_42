/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:33:03 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/03/01 15:17:54 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_B.h"

void	ft_enmexit(t_principal *m)
{
	if (m->map[m->pos.ye - 1][m->pos.xe] == 'P' || m->map[m->pos.ye
		+ 1][m->pos.xe] == 'P' || m->map[m->pos.ye][m->pos.xe + 1] == 'P'
		|| m->map[m->pos.ye][m->pos.xe - 1] == 'P')
		exit(0);
}

int	ft_moves(t_principal *m)
{
	m->r = rand() % 4;
	if (m->t == 2000)
	{
		ft_enmexit(m);
		if (m->map[m->pos.ye - 1][m->pos.xe] == '0' && m->r == 2)
			ft_anmy_1(m);
		else if (m->map[m->pos.ye][m->pos.xe + 1] == '0' && m->r == 0)
			ft_anmx1(m);
		else if (m->map[m->pos.ye + 1][m->pos.xe] == '0' && m->r == 1)
			ft_anmy1(m);
		else if (m->map[m->pos.ye][m->pos.xe - 1] == '0' && m->r == 3)
			ft_anmx_1(m);
		m->t = 0;
	}
	m->t++;
	return (0);
}

void	move_enm(t_principal *m)
{
	mlx_loop_hook(m->mlx_ptr, ft_moves, m);
}

void	ft_addenm(t_principal *m)
{
	int	i;
	int	j;

	i = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			if ((m->map[i][j] == '0' && m->map[i][j + 1] == '0')
				|| (m->map[i][j] == '0' && m->map[i + 1][j] == '0'))
			{
				m->map[i][j] = 'B';
				return ;
			}
			j++;
		}
		i++;
	}
}
