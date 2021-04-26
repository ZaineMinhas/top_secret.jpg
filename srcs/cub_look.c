/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_look.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:18:23 by zminhas           #+#    #+#             */
/*   Updated: 2021/04/26 15:36:47 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	look_left(t_cub *var)
{
	ft_draw_player(var, 0);
	var->rot += ROT_SPEED;
	var->rot %= 360;
	ft_draw_player(var, 0x00FF66);
}

void	look_right(t_cub *var)
{
	ft_draw_player(var, 0);
	var->rot -= ROT_SPEED;
	var->rot %= 360;
	ft_draw_player(var, 0x00FF66);
}
