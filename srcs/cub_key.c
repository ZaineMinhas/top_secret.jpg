/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:11:05 by zminhas           #+#    #+#             */
/*   Updated: 2021/03/25 17:24:01 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_go(int key, t_cub *var)
{
	ft_reset(var->move);
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
	return (0);
}
