/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:32:52 by zminhas           #+#    #+#             */
/*   Updated: 2021/05/05 18:49:36 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_up(t_cub *var)
{
	float	dx;
	float	dy;

	dx = cos((M_PI / 180) * var->rot) * PLAYER_SPEED;
	dy = sin((M_PI / 180) * var->rot) * PLAYER_SPEED;
	if (!ft_iswall(var, var->p_x + dx, var->p_y - dy))
	{
		var->p_x += dx;
		var->p_y -= dy;
	}
}

void	move_down(t_cub *var)
{
	float	dx;
	float	dy;

	dx = cos((M_PI / 180) * var->rot) * PLAYER_SPEED;
	dy = sin((M_PI / 180) * var->rot) * PLAYER_SPEED;
	if (!ft_iswall(var, var->p_x - dx, var->p_y + dy))
	{
		var->p_x -= dx;
		var->p_y += dy;
	}
}

void	move_left(t_cub *var)
{
	float	dx;
	float	dy;

	dx = cos((M_PI / 180) * var->rot) * PLAYER_SPEED;
	dy = sin((M_PI / 180) * var->rot) * PLAYER_SPEED;
	if (!ft_iswall(var, var->p_x - dy, var->p_y - dx))
	{
		var->p_x -= dy;
		var->p_y -= dx;
	}
}

void	move_right(t_cub *var)
{
	float	dx;
	float	dy;

	dx = cos((M_PI / 180) * var->rot) * PLAYER_SPEED;
	dy = sin((M_PI / 180) * var->rot) * PLAYER_SPEED;
	if (!ft_iswall(var, var->p_x + dy, var->p_y + dx))
	{
		var->p_x += dy;
		var->p_y += dx;
	}
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
}
