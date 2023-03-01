/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_B.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:46:54 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/02/15 16:07:21 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_B.h"

void	ft_dsgm(t_principal *m)
{
	m->mlx_ptr = mlx_init();
	m->mlx_window = mlx_new_window(m->mlx_ptr, m->len_line * 70, m->count_line
			* 70, "so_long");
	ft_stockwen(m);
	move_enm(m);
	mlx_hook(m->mlx_window, 2, 0, ft_key, m);
	mlx_hook(m->mlx_window, 17, 0, ft_exit, m);
	mlx_loop(m->mlx_ptr);
}

void	ft_open_fd(char *s, int *fd)
{
	*fd = open(s, O_RDWR);
	if (*fd == -1)
	{
		perror("ERROR");
		exit(1);
	}
	ft_check_inp(s);
}

int	main(int ac, char **av)
{
	int			fd;
	t_principal	*m;
	int			i;
	int			j;
	char		*map_read;

	if (ac != 2)
		(write(1, "EROOR!\npath", 12), exit(1));
	ft_open_fd(av[1], &fd);
	m = malloc(sizeof(t_principal));
	i = 0;
	j = 0;
	map_read = ft_read_fd(fd);
	ft_check_newline(map_read);
	m->count_line = ft_cnt(map_read, '\n');
	m->map = ft_split(map_read, '\n');
	ft_addenm(m);
	ft_check_and_count(m->map, m);
	m->flode = ft_split(map_read, '\n');
	m->flod = ft_split(map_read, '\n');
	m->len_line = ft_strlen(m->map[i]);
	ft_check(m);
	ft_dsgm(m);
}
