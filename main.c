/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:46:54 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/02/15 16:54:22 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_read_fd(int fd)
{
	char	*buf;
	char	*bufjoin;
	int		i;

	i = 1;
	bufjoin = ft_strdup("");
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			free(bufjoin);
			return (NULL);
		}
		buf[i] = '\0';
		bufjoin = ft_strjoin1(bufjoin, buf);
		if (!bufjoin)
			return (NULL);
	}
	free(buf);
	return (bufjoin);
}

void	ft_check(t_principal *m)
{
	ft_check_wall(m->map);
	ft_check_path1(m);
	ft_check_len(m->map);
}

void	ft_dsgm(t_principal *m)
{
	m->mlx_ptr = mlx_init();
	m->mlx_window = mlx_new_window(m->mlx_ptr, m->len_line * 70, m->count_line
			* 70, "so_long");
	ft_stockwen(m);
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
	ft_check_and_count(m->map, m);
	m->flode = ft_split(map_read, '\n');
	m->flod = ft_split(map_read, '\n');
	m->len_line = ft_strlen(m->map[i]);
	ft_check(m);
	ft_dsgm(m);
}
