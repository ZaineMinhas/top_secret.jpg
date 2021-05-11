/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:11:05 by zminhas           #+#    #+#             */
/*   Updated: 2021/05/11 17:09:56 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_close(t_cub *var)
{
	(void)var;
	exit(1);
	return (0);
}

int	ft_go(int key, t_cub *var)
{
	ft_reset(var->move);
	ft_draw_player(var, 0);
	if (key == KEY_ESC)
		exit(1);
	if (key == KEY_LEFT)
		var->move->left = 1;
	if (key == KEY_RIGHT)
		var->move->right = 1;
	if (key == KEY_W)
		var->move->w = 1;
	if (key == KEY_A)
		var->move->a = 1;
	if (key == KEY_S)
		var->move->s = 1;
	if (key == KEY_D)
		var->move->d = 1;
	if (var->move->left)
		look_left(var);
	if (var->move->right)
		look_right(var);
	move_check(var);
	draw_map(var);
	ft_draw_player(var, 0xFF00FF);
	//player_wall_dist(var);
	//printf("|x = %f y = %f|\n", between_zero_one(var->p_x), between_zero_one(var->p_y));
	return (0);
}
