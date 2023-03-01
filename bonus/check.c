/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:37:28 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/02/15 15:14:06 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_B.h"

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

int	ft_check_line(char *map)
{
	int	j;

	j = 0;
	while (map[j])
	{
		if (map[j] != '1')
			return (1);
		else
			j++;
	}
	return (0);
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
