/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_calculs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:14:31 by zminhas           #+#    #+#             */
/*   Updated: 2021/05/11 16:34:24 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	line(t_cub *var, double j, int color)
{
	double	dx;
	double	dy;
	double	distx;
	double	disty;
	double	nextx;
	double	nexty;
	double	dist_to_wall;
	int		i;
	int		stepx;
	int		stepy;
	int		side;
	int		mapx;
	int		mapy;
	int		hit;

	i = -1;
	hit = 0;
	dx = cos(((M_PI / 180)) * (double)(var->rot + j));
	dy = sin(((M_PI / 180)) * (double)(var->rot + j));
	mapx = (int)var->p_x;
	mapy = (int)var->p_y;
	if ((int)dy == 0)
		distx = 0;
	else
	{
		if ((int)dx == 0)
			distx = 1;
		else
			distx = fabs(1 / dx);
	}
	if ((int)dx == 0)
		disty = 0;
	else
	{
		if ((int)dy == 0)
			disty = 1;
		else
			disty = fabs(1 / dy);
	}
	printf("dx = %f, dy = %f\n", dx, dy);
	printf("distx = %f, disty = %f\n", distx, disty);
	if (dx < 0)
	{
		stepx = -1;
		nextx = (var->p_x - mapx) * distx;
	}
	else
	{
		stepx = 1;
		nextx = (mapx + 1.0 - var->p_x) * distx;
	}
	if (dy < 0)
	{
		stepy = -1;
		nexty = (var->p_y - mapy) * disty;
	}
	else
	{
		stepy = 1;
		nexty = (mapy + 1.0 - var->p_y) * disty;
	}
	while (hit == 0)
	{
		if (nexty < nextx)
		{
			nextx += dx;
			mapx += stepx;
			side = 1;
		}
		else
		{
			nexty += dy;
			mapy += stepy;
			side = 0;
		}
		if (var->int_map[mapy][mapx] > 0)
			hit = 1;
	}
	if (side == 0)
		dist_to_wall = fabs((var->p_x - mapx + (1 - stepx) / 2) / dx);
	else
		dist_to_wall = fabs((var->p_y - mapy + (1 - stepy) / 2) / dy);
	printf("dist_to_wall = %f\n", dist_to_wall);
	while (++i < dist_to_wall * WALL_SIZE)
		ft_draw_pixel(var->img, WALL_SIZE * var->p_x + i * dx, WALL_SIZE * var->p_y - i * dy, color);
}
