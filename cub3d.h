/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:53:01 by zminhas           #+#    #+#             */
/*   Updated: 2021/03/29 16:22:11 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"


typedef struct s_imglist
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}				t_img;

typedef struct s_texturelist
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}				t_tex;

typedef struct s_colorlist
{
	char	*s;
	int	*r;
	int	*f;
	int	*c;
}				t_col;

typedef struct s_movelist
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;

}				t_move;

typedef struct	s_cublist
{
	t_img	*img;
	t_move	*move;
	t_tex	*tex;
	t_col	*col;
	float	p_x;
	float	p_y;
	int		rot;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_cub;

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_ESC 53

/*
**	info fonctions
*/

void	get_info(t_cub *var);
int	get_no(char *line, t_cub *var);
int	get_so(char *line, t_cub *var);
int	get_we(char *line, t_cub *var);
int	get_ea(char *line, t_cub *var);
int	get_r(char *line, t_cub *var);
int	get_s(char *line, t_cub *var);
int	get_f(char *line, t_cub *var);
int	get_c(char *line, t_cub *var);

/*
**	display fonctions
*/

void	ft_draw_pixel(t_img *img, int x, int y, int color);
void	ft_draw_player(t_cub *var, int color);
void	draw_wall(int wall, int index, int floor, t_cub *var);

/*
**	key fonctions
*/

int	ft_go(int key, t_cub *var);
int	ft_close(t_cub *var);

/*
**	look fonctions
*/

void	look_left(t_cub *var);
void	look_right(t_cub *var);

/*
**	move fonctions
*/

void	move_check(t_cub *var);
void	move_up(t_cub *var);
void	move_down(t_cub *var);
void	move_left(t_cub *var);
void	move_right(t_cub *var);


/*
**	utils fonctions
*/

void	ft_reset(t_move *move);

#endif
