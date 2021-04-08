/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:39:50 by zminhas           #+#    #+#             */
/*   Updated: 2021/04/08 14:46:35 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_draw_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void	ft_line(t_cub *var, float rot, int color)
{
	float dx;
	float dy;
	int i;

	i = -1;
	dx = 0;
	dy = 0;
	while (++i < LINE_SIZE/* && !ft_is_wall(var->p_x + dx, var->p_y - dy)*/)
	{
		dx += cos(((float)var->rot + rot) * (M_PI / 180));
		dy += sin(((float)var->rot + rot) * (M_PI / 180));
		if ((var->p_x + dx < 1910 && var->p_x + dx > 10) && (var->p_y - dy < 1070 && var->p_y - dy > 10))
			ft_draw_pixel(var->img, dx + var->p_x, var->p_y - dy, color);
	}
}

void	ft_draw_player(t_cub *var, int color)
{
	float	i;
	int	j;

	i = -1;
	while (++i < PLAYER_SIZE)
	{
		j = -1;
		while (++j < PLAYER_SIZE)
			ft_draw_pixel(var->img, var->p_x + i - PLAYER_SIZE / 2, var->p_y + j - PLAYER_SIZE / 2, color);
	}
	if (color)
		color = 0xFFFF66;
	i = -LINE_NUMBER;
	while (i <= LINE_NUMBER)
	{
		i += LINE_LINE;
		ft_line(var, i, color);
	}
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
