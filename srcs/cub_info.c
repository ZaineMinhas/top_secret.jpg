/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:38:07 by zminhas           #+#    #+#             */
/*   Updated: 2021/03/24 18:42:26 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_info(t_cub *var)
{
	var->img = malloc(sizeof(t_img));
	var->mlx_ptr = mlx_init();
	var->win_ptr = mlx_new_window(var->mlx_ptr, 1920, 1080, "la fenetre");
	var->img->img = mlx_new_image(var->mlx_ptr, 1920, 1080);
	var->img->addr = mlx_get_data_addr(var->img->img, &var->img->bits_per_pixel,
	&var->img->line_length, &var->img->endian);
}
