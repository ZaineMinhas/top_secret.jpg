/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:14:59 by zminhas           #+#    #+#             */
/*   Updated: 2021/03/24 18:40:30 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(void)
{
	t_cub var;

	get_info(&var);
	ft_draw_pixel(var.img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(var.mlx_ptr, var.win_ptr, var.img->img, 0, 0);
	mlx_loop(var.mlx_ptr);
	return (0);
}

// w = 13, a = 0, s = 1, d = 2, up = 126, left = 123, right = 124, down = 125

// la commande : gcc -lmlx -framework OpenGL -framework AppKit cub3d.a && clear && ./a.out