/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1h.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:15:13 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/02/15 13:16:06 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(void)
{
	exit(0);
	return (0);
}

int	ft_key(int k, t_principal *m)
{
	static int	d;

	if (k == 53)
		exit(0);
	if (k == 2 || k == 124)
	{
		d = 1;
		ft_move_rt(m);
	}
	if (k == 0 || k == 123)
	{
		d = 0;
		ft_move_lf(m);
	}
	if (k == 1 || k == 125)
	{
		ft_move_down(m, d);
	}
	if (k == 13 || k == 126)
	{
		ft_move_up(m, d);
	}
	return (0);
}

void	ft_count_move(t_principal *m)
{
	ft_putnbr_fd(m->cm);
	write(1, "\n", 1);
}
