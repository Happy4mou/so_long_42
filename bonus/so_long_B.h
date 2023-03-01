/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_B.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:10:26 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/02/15 14:38:55 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_B_H
# define SO_LONG_B_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pos
{
	int		x;
	int		y;
	int		xe;
	int		ye;
	int		h;
	int		g;

}			t_pos;

typedef struct s_principal
{
	t_pos	pos;
	int		b;
	int		p;
	int		c;
	int		e;
	int		t;
	int		r;
	int		width;
	int		height;
	char	**flod;
	char	**flode;
	char	**floden;
	char	**map;
	int		count_enm;
	int		count_line;
	int		len_line;
	int		cm;
	int		mo;
	void	*mlx_ptr;
	void	*mlx_window;
	void	*xpm_img;
}			t_principal;

void		ft_stockwen(t_principal *m);
void		ft_check_path(char **map, int y, int x, t_principal *m);
void		ft_check_path1(t_principal *m);
void		ft_check_ce(t_principal *m);
void		ft_check_path_e(char **map, int y, int x, t_principal *m);
void		ft_check_len(char **map);
void		ft_check_and_count(char **map, t_principal *count);
void		ft_vrf(int c, int p, int e, int b);
void		ft_count(char c, int i, int j, t_principal *count);
void		ft_check_newline(char *map_read);
void		ft_check_wall(char **map);
void		ft_check_flline(char **map, int i);
void		ft_stockwen(t_principal *m);
void		ft_stockwen2(t_principal *m, int i, int j);
void		ft_put_img(t_principal *m, char *bath, int i, int j);
int			ft_key(int k, t_principal *m);
void		ft_move_up(t_principal *m, int d);
void		ft_move_up_helper(t_principal *m, int d);
void		ft_move_down(t_principal *m, int d);
void		ft_move_lf(t_principal *m);
void		ft_move_rt(t_principal *m);
void		ft_move_down_helper(t_principal *m, int d);
void		ft_move_rt_helper(t_principal *m);
void		ft_move_lf_helper(t_principal *m);
void		ft_check(t_principal *m);
int			ft_exit(void);
void		ft_count_move(t_principal *m);
void		ft_check_inp(char *s);
void		ft_dsgm(t_principal *m);
void		ft_anmy_1(t_principal *m);
void		ft_anmy1(t_principal *m);
void		ft_anmx1(t_principal *m);
void		ft_anmx_1(t_principal *m);
void		ft_enmexit(t_principal *m);
int			ft_moves(t_principal *m);
void		move_enm(t_principal *m);
void		ft_addenm(t_principal *m);
char		*ft_read_fd(int fd);
void		ft_check(t_principal *m);
int			ft_check_line(char *map);
void		ft_check_inp(char *s);

#endif