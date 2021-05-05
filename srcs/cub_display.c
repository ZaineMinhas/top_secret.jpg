/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:39:50 by zminhas           #+#    #+#             */
/*   Updated: 2021/05/05 18:53:18 by zminhas          ###   ########.fr       */
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
	double	dx;
	double	dy;
	int		i;

	i = -1;
	dx = 0;
	dy = 0;
	while (++i < LINE_SIZE /*&& !ft_iswall(var, var->p_x * WALL_SIZE + dx, var->p_y * WALL_SIZE - dy)*/)
	{
		dx += cos(((double)var->rot + rot) * (M_PI / 180));
		dy += sin(((double)var->rot + rot) * (M_PI / 180));
		if ((var->p_x  * WALL_SIZE + dx < 1910 && var->p_x * WALL_SIZE + dx > 10)
			&& (var->p_y * WALL_SIZE - dy < 1070 && var->p_y * WALL_SIZE - dy > 10))
			ft_draw_pixel(var->img, dx + var->p_x * WALL_SIZE, var->p_y * WALL_SIZE - dy, color);
	}
}

void	ft_draw_player(t_cub *var, int color)
{
	double	i;
	double	j;

	i = -1;
	while (++i < PLAYER_SIZE)
	{
		j = -1;
		while (++j < PLAYER_SIZE)
		{
			ft_draw_pixel(var->img, var->p_x * WALL_SIZE + i - PLAYER_SIZE / 2,
				var->p_y * WALL_SIZE + j - PLAYER_SIZE / 2, color);
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

	if (!wall)
		return ;
	i = -0;
	while (++i < WALL_SIZE - 1)
	{
		j = +0;
		while (++j < WALL_SIZE - 1)
			ft_draw_pixel(var->img, x * WALL_SIZE + i, y * WALL_SIZE + j, 0xFF5722);
	}
	//mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img->img, 0, 0);
}

void	draw_map(t_cub *var)
{
	int	i;
	int	j;

	i = -1;
	while (++i < var->map_y)
	{
		j = -1;
		while (++j < var->map_line[i])
			draw_wall(var, var->int_map[i][j], j, i);
	}
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img->img, 0, 0);
}
