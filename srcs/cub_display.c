/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:39:50 by zminhas           #+#    #+#             */
/*   Updated: 2021/03/29 15:20:41 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_draw_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void	ft_draw_player(t_cub *var, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 30)
	{
		j = -1;
		while (++j < 30)
			ft_draw_pixel(var->img, var->p_x + i - 15, var->p_y + j - 15, color);
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
		while (x++ < 50)
		{
			y = y_bis;
			while (y++ < 50)
				ft_draw_pixel(var->img, x + index * 50, y + floor * 50, 0xFF5722);
		}
	}
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img->img, 0, 0);
}
