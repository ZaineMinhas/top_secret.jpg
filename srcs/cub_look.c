/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_look.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:18:23 by zminhas           #+#    #+#             */
/*   Updated: 2021/04/07 15:37:22 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	look_left(t_cub *var)
{
	ft_draw_player(var, 0);
	var->rot += 5;
	var->rot %= 360;
	ft_draw_player(var, 0x8E44AD);
}

void	look_right(t_cub *var)
{
	ft_draw_player(var, 0);
	var->rot -= 5;
	var->rot %= 360;
	ft_draw_player(var, 0x8E44AD);
}
