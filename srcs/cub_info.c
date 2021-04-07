/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:38:07 by zminhas           #+#    #+#             */
/*   Updated: 2021/04/07 16:29:43 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_info(t_cub *var)
{
	var->img = malloc(sizeof(t_img));
	var->move = malloc(sizeof(t_move));
	var->tex = malloc(sizeof(t_tex));
	var->col = malloc(sizeof(t_col));
	var->map = malloc(sizeof(t_map));
	var->mlx_ptr = mlx_init();
	var->win_ptr = mlx_new_window(var->mlx_ptr, 1920, 1080, "la fenetre");
	var->img->img = mlx_new_image(var->mlx_ptr, 1920, 1080);
	var->img->addr = mlx_get_data_addr(var->img->img, &var->img->bits_per_pixel,
	&var->img->line_length, &var->img->endian);
}
