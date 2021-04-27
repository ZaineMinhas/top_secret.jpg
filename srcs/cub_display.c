/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:39:50 by zminhas           #+#    #+#             */
/*   Updated: 2021/04/27 17:57:25 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_draw_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void	ft_line(t_cub *var, float rot, int color)
{
	float	dx;
	float	dy;
	int		i;

	i = -1;
	dx = 0;
	dy = 0;
	while (++i < LINE_SIZE && !ft_iswall(var, var->p_x + dx, var->p_y - dy))
	{
		dx += cos(((float)var->rot + rot) * (M_PI / 180));
		dy += sin(((float)var->rot + rot) * (M_PI / 180));
		if ((var->p_x + dx < 1910 && var->p_x + dx > 10)
			&& (var->p_y - dy < 1070 && var->p_y - dy > 10))
			ft_draw_pixel(var->img, dx + var->p_x, var->p_y - dy, color);
	}
}

void	ft_draw_player(t_cub *var, int color)
{
	float	i;
	int		j;

	i = -1;
	while (++i < PLAYER_SIZE)
	{
		j = -1;
		while (++j < PLAYER_SIZE)
		{
			ft_draw_pixel(var->img, var->p_x + i - PLAYER_SIZE / 2,
				var->p_y + j - PLAYER_SIZE / 2, color);
		}
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

void	draw_wall(t_cub *var, int wall, int x, int y)
{
	int	i;
	int	j;

	if (!wall || wall == -48)
		return ;
	i = -0;
	while (++i < WALL_SIZE - 1)
	{
		j = +0;
		while (++j < WALL_SIZE - 1)
			ft_draw_pixel(var->img, x * WALL_SIZE + i, y * WALL_SIZE + j, 0xFF5722);
	}
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img->img, 0, 0);
}

void	draw_map(t_cub *var)
{
	int	i;
	int	j;

	i = -1;
	while (++i < var->map_y)
	{
		j = -1;
		while (++j < var->map_x)
			draw_wall(var, var->int_map[i][j], j, i);
	}
}
