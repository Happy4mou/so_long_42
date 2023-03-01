/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:30:18 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/02/15 15:10:45 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_B.h"

void	ft_anmy_1(t_principal *m)
{
	m->map[m->pos.ye - 1][m->pos.xe] = 'B';
	m->map[m->pos.ye][m->pos.xe] = '0';
	if (m->mo == 0)
	{
		ft_put_img(m, "textures/back.xpm", m->pos.ye, m->pos.xe);
		ft_put_img(m, "textures/enm.xpm", m->pos.ye - 1, m->pos.xe);
		m->mo = 1;
	}
	else if (m->mo == 1)
	{
		ft_put_img(m, "textures/back.xpm", m->pos.ye, m->pos.xe);
		ft_put_img(m, "textures/enmm.xpm", m->pos.ye - 1, m->pos.xe);
		m->mo = 0;
	}
	m->pos.ye--;
}

void	ft_anmy1(t_principal *m)
{
	m->map[m->pos.ye + 1][m->pos.xe] = 'B';
	m->map[m->pos.ye][m->pos.xe] = '0';
	if (m->mo == 0)
	{
		ft_put_img(m, "textures/back.xpm", m->pos.ye, m->pos.xe);
		ft_put_img(m, "textures/enm.xpm", m->pos.ye + 1, m->pos.xe);
		m->mo = 1;
	}
	else if (m->mo == 1)
	{
		ft_put_img(m, "textures/back.xpm", m->pos.ye, m->pos.xe);
		ft_put_img(m, "textures/enmm.xpm", m->pos.ye + 1, m->pos.xe);
		m->mo = 0;
	}
	m->pos.ye++;
}

void	ft_anmx1(t_principal *m)
{
	m->map[m->pos.ye][m->pos.xe + 1] = 'B';
	m->map[m->pos.ye][m->pos.xe] = '0';
	if (m->mo == 0)
	{
		ft_put_img(m, "textures/back.xpm", m->pos.ye, m->pos.xe);
		ft_put_img(m, "textures/enm.xpm", m->pos.ye, m->pos.xe + 1);
		m->mo = 1;
	}
	else if (m->mo == 1)
	{
		ft_put_img(m, "textures/back.xpm", m->pos.ye, m->pos.xe);
		ft_put_img(m, "textures/enmm.xpm", m->pos.ye, m->pos.xe + 1);
		m->mo = 0;
	}
	m->pos.xe++;
}

void	ft_anmx_1(t_principal *m)
{
	m->map[m->pos.ye][m->pos.xe - 1] = 'B';
	m->map[m->pos.ye][m->pos.xe] = '0';
	if (m->mo == 0)
	{
		ft_put_img(m, "textures/back.xpm", m->pos.ye, m->pos.xe);
		ft_put_img(m, "textures/enm.xpm", m->pos.ye, m->pos.xe - 1);
		m->mo = 1;
	}
	else if (m->mo == 1)
	{
		ft_put_img(m, "textures/back.xpm", m->pos.ye, m->pos.xe);
		ft_put_img(m, "textures/enmm.xpm", m->pos.ye, m->pos.xe - 1);
		m->mo = 0;
	}
	m->pos.xe--;
}
