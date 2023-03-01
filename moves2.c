/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:45:51 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/03/01 15:24:26 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_rt_helper(t_principal *m)
{
	if (m->map[m->pos.y][m->pos.x + 1] == '0')
	{
		m->map[m->pos.y][m->pos.x + 1] = 'P';
		m->map[m->pos.y][m->pos.x] = '0';
		ft_put_img(m, "textures/back.xpm", m->pos.y, m->pos.x);
		mlx_destroy_image(m->mlx_ptr, m->xpm_img);
		m->pos.x++;
		ft_put_img(m, "textures/playerlm.xpm", m->pos.y, m->pos.x);
	}
	else if (m->map[m->pos.y][m->pos.x + 1] == 'C')
	{
		ft_put_img(m, "textures/back.xpm", m->pos.y, m->pos.x + 1);
		m->map[m->pos.y][m->pos.x + 1] = 'P';
		m->map[m->pos.y][m->pos.x] = '0';
		ft_put_img(m, "textures/back.xpm", m->pos.y, m->pos.x);
		mlx_destroy_image(m->mlx_ptr, m->xpm_img);
		m->c--;
		m->pos.x++;
		ft_put_img(m, "textures/playerlm.xpm", m->pos.y, m->pos.x);
	}
	else if (m->map[m->pos.y][m->pos.x + 1] == 'E' && m->c == 0)
		exit(0);
}

void	ft_move_rt(t_principal *m)
{
	if ((m->map[m->pos.y][m->pos.x + 1] == '1' || m->map[m->pos.y][m->pos.x
		+ 1] == 'E') && m->c != 0)
		return ;
	ft_count_move(m);
	m->cm++;
	ft_move_rt_helper(m);
	if (m->c == 0)
	{
		ft_put_img(m, "textures/back.xpm", m->pos.h, m->pos.g);
		ft_put_img(m, "textures/exiton.xpm", m->pos.h, m->pos.g);
	}
}

void	ft_move_lf_helper(t_principal *m)
{
	if (m->map[m->pos.y][m->pos.x - 1] == '0')
	{
		m->map[m->pos.y][m->pos.x - 1] = 'P';
		m->map[m->pos.y][m->pos.x] = '0';
		ft_put_img(m, "textures/back.xpm", m->pos.y, m->pos.x);
		m->pos.x--;
		ft_put_img(m, "textures/playerls.xpm", m->pos.y, m->pos.x);
	}
	else if (m->map[m->pos.y][m->pos.x - 1] == 'C')
	{
		ft_put_img(m, "textures/back.xpm", m->pos.y, m->pos.x - 1);
		m->map[m->pos.y][m->pos.x - 1] = 'P';
		m->map[m->pos.y][m->pos.x] = '0';
		ft_put_img(m, "textures/back.xpm", m->pos.y, m->pos.x);
		m->c--;
		m->pos.x--;
		ft_put_img(m, "textures/playerls.xpm", m->pos.y, m->pos.x);
	}
	else if (m->map[m->pos.y][m->pos.x - 1] == 'E' && m->c == 0)
		exit(0);
}

void	ft_move_lf(t_principal *m)
{
	if ((m->map[m->pos.y][m->pos.x - 1] == '1' || m->map[m->pos.y][m->pos.x
		- 1] == 'E') && m->c != 0)
		return ;
	ft_count_move(m);
	m->cm++;
	ft_move_lf_helper(m);
	if (m->c == 0)
	{
		ft_put_img(m, "textures/back.xpm", m->pos.h, m->pos.g);
		ft_put_img(m, "textures/exiton.xpm", m->pos.h, m->pos.g);
	}
}
