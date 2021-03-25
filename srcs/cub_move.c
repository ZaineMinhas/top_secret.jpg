/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:32:52 by zminhas           #+#    #+#             */
/*   Updated: 2021/03/25 17:43:48 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_up(t_cub *var)
{
	float dx;
	float dy;

	ft_draw_player(var, 0);
	dx = cos((M_PI / 180) * var->rot) * 10;
	dy = sin((M_PI / 180) * var->rot) * 10;
	var->p_x += dx;
	var->p_y -= dy;
	ft_draw_player(var, 0xFF00FF);
}

void	move_down(t_cub *var)
{
	float dx;
	float dy;

	ft_draw_player(var, 0);
	dx = cos((M_PI / 180) * var->rot) * 10;
	dy = sin((M_PI / 180) * var->rot) * 10;
	var->p_x -= dx;
	var->p_y += dy;
	ft_draw_player(var, 0xFF00FF);
}

void	move_left(t_cub *var)
{
	float dx;
	float dy;

	ft_draw_player(var, 0);
	dx = cos((M_PI / 180) * var->rot) * 10;
	dy = sin((M_PI / 180) * var->rot) * 10;
	var->p_x -= dy;
	var->p_y -= dx;
	ft_draw_player(var, 0xFF00FF);
}

void	move_right(t_cub *var)
{
	float dx;
	float dy;

	ft_draw_player(var, 0);
	dx = cos((M_PI / 180) * var->rot) * 10;
	dy = sin((M_PI / 180) * var->rot) * 10;
	var->p_x += dy;
	var->p_y += dx;
	ft_draw_player(var, 0xFF00FF);
}

void	move_check(t_cub *var)
{
	if (var->move->w)
		move_up(var);
	if (var->move->a)
		move_left(var);
	if (var->move->s)
		move_down(var);
	if (var->move->d)
		move_right(var);
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img->img, 0, 0);
}
