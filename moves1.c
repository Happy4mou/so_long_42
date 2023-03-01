/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:33:20 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/03/01 15:21:41 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_lmlsplayer(t_principal *m, int d)
{
	if (d == 1)
		ft_put_img(m, "textures/playerlm.xpm", m->pos.y, m->pos.x);
	else if (d == 0)
		ft_put_img(m, "textures/playerls.xpm", m->pos.y, m->pos.x);
}

void	ft_move_up_helper(t_principal *m, int d)
{
	if (m->map[m->pos.y - 1][m->pos.x] == '0')
	{
		m->map[m->pos.y - 1][m->pos.x] = 'P';
		m->map[m->pos.y][m->pos.x] = '0';
		ft_put_img(m, "textures/back.xpm", m->pos.y, m->pos.x);
		m->pos.y--;
		ft_lmlsplayer(m, d);
	}
	else if (m->map[m->pos.y - 1][m->pos.x] == 'C')
	{
		ft_put_img(m, "textures/back.xpm", m->pos.y - 1, m->pos.x);
		m->map[m->pos.y - 1][m->pos.x] = 'P';
		m->map[m->pos.y][m->pos.x] = '0';
		ft_put_img(m, "textures/back.xpm", m->pos.y, m->pos.x);
		m->c--;
		m->pos.y--;
		ft_lmlsplayer(m, d);
	}
	else if (m->map[m->pos.y - 1][m->pos.x] == 'E' && m->c == 0)
		exit(0);
}

void	ft_move_up(t_principal *m, int d)
{
	if ((m->map[m->pos.y - 1][m->pos.x] == '1' || m->map[m->pos.y
			- 1][m->pos.x] == 'E') && m->c != 0)
		return ;
	ft_count_move(m);
	m->cm++;
	ft_move_up_helper(m, d);
	if (m->c == 0)
	{
		ft_put_img(m, "textures/back.xpm", m->pos.h, m->pos.g);
		ft_put_img(m, "textures/exiton.xpm", m->pos.h, m->pos.g);
	}
}

void	ft_move_down_helper(t_principal *m, int d)
{
	if (m->map[m->pos.y + 1][m->pos.x] == '0')
	{
		m->map[m->pos.y + 1][m->pos.x] = 'P';
		m->map[m->pos.y][m->pos.x] = '0';
		ft_put_img(m, "textures/back.xpm", m->pos.y, m->pos.x);
		m->pos.y++;
		ft_lmlsplayer(m, d);
	}
	else if (m->map[m->pos.y + 1][m->pos.x] == 'C')
	{
		ft_put_img(m, "textures/back.xpm", m->pos.y + 1, m->pos.x);
		m->map[m->pos.y + 1][m->pos.x] = 'P';
		m->map[m->pos.y][m->pos.x] = '0';
		ft_put_img(m, "textures/back.xpm", m->pos.y, m->pos.x);
		m->c--;
		m->pos.y++;
		ft_lmlsplayer(m, d);
	}
	else if (m->map[m->pos.y + 1][m->pos.x] == 'E' && m->c == 0)
		exit(0);
}

void	ft_move_down(t_principal *m, int d)
{
	if ((m->map[m->pos.y + 1][m->pos.x] == '1' || m->map[m->pos.y
			+ 1][m->pos.x] == 'E') && m->c != 0)
		return ;
	ft_count_move(m);
	m->cm++;
	ft_move_down_helper(m, d);
	if (m->c == 0)
	{
		ft_put_img(m, "textures/back.xpm", m->pos.h, m->pos.g);
		ft_put_img(m, "textures/exiton.xpm", m->pos.h, m->pos.g);
	}
}
