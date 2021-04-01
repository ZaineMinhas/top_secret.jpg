/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:39:50 by zminhas           #+#    #+#             */
/*   Updated: 2021/04/01 20:30:02 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_draw_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void	ft_line(t_cub *var, int rot, int color)
{
	float dx;
	float dy;
	int i;

	i = -1;
	dx = 0;
	dy = 0;
	while (++i < 250/* && !ft_is_wall(var->p_x + dx, var->p_y - dy)*/)
	{
		dx += cos(((float)var->rot + rot) * (M_PI / 180));
		dy += sin(((float)var->rot + rot) * (M_PI / 180));
		//mlx_pixel_put(var->mlx_ptr, var->win_ptr, dx + var->p_x, var->p_y - dy, color);
		ft_draw_pixel(var->img, dx + var->p_x, var->p_y - dy, color);
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img->img, 0, 0);
	}
}

void	ft_draw_player(t_cub *var, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < PLAYER_SIZE)
	{
		j = -1;
		while (++j < PLAYER_SIZE)
			ft_draw_pixel(var->img, var->p_x + i - 15, var->p_y + j - 15, color);
	}
	if (color)
		color = 0x00FF00;
	i = -LINE_NUMBER;
	while (i++ <= LINE_NUMBER)
		ft_line(var, i, color);
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img->img, 0, 0);
}

void	draw_wall(int wall, int index, int floor, t_cub *var)
{
	int	x;
	int	y;
	int y_bis;

	x = 0;
	y = 0;
	if (wall)
	{
		y_bis = y;
		while (x++ < WALL_SIZE)
		{
			y = y_bis;
			while (y++ < WALL_SIZE)
				ft_draw_pixel(var->img, x + index * 50, y + floor * 50, 0xFF5722);
		}
	}
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img->img, 0, 0);
}
