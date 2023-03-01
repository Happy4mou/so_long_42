/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stockwen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:22:06 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/02/15 16:54:47 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_img(t_principal *m, char *bath, int i, int j)
{
	m->xpm_img = mlx_xpm_file_to_image(m->mlx_ptr, bath, &m->width, &m->height);
	if (m->xpm_img == NULL)
		exit(1);
	mlx_put_image_to_window(m->mlx_ptr, m->mlx_window,
		m->xpm_img, j * 70, i * 70);
}

void	ft_stockwen2(t_principal *m, int i, int j)
{
	if (m->map[i][j] == '1' && j == m->len_line - 1)
		ft_put_img(m, "textures/wall.xpm", i, j);
	if (m->map[i][j] == '1' && i != 0 && j != 0 && i != m->count_line - 1
		&& j != m->len_line - 1)
		ft_put_img(m, "textures/wall.xpm", i, j);
	if (m->map[i][j] == 'E')
	{
		ft_put_img(m, "textures/back.xpm", i, j);
		ft_put_img(m, "textures/exitoff.xpm", i, j);
	}
	if (m->map[i][j] == 'C')
	{
		ft_put_img(m, "textures/back.xpm", i, j);
		ft_put_img(m, "textures/C.xpm", i, j);
	}
	if (m->map[i][j] == 'P')
	{
		ft_put_img(m, "textures/back.xpm", i, j);
		ft_put_img(m, "textures/playerlm.xpm", i, j);
	}
}

void	ft_stockwen(t_principal *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx_clear_window(m->mlx_ptr, m->mlx_window);
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			if (m->map[i][j] == '0')
				ft_put_img(m, "textures/back.xpm", i, j);
			if (m->map[i][j] == '1' && i == 0)
				ft_put_img(m, "textures/wall.xpm", i, j);
			if (m->map[i][j] == '1' && j == 0)
				ft_put_img(m, "textures/wall.xpm", i, j);
			if (m->map[i][j] == '1' && i == m->count_line - 1)
				ft_put_img(m, "textures/wall.xpm", i, j);
			ft_stockwen2(m, i, j);
			j++;
		}
		i++;
	}
}

void	ft_check_inp(char *s)
{
	int	i;

	i = 0;
	i = ft_strlen(s) - 4;
	if (ft_strncmp(&s[i], ".ber") == 0)
		return ;
	else
		(write(1, "EROOR!\npath", 12), exit(1));
}
