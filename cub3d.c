/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:14:59 by zminhas           #+#    #+#             */
/*   Updated: 2021/04/18 17:02:51 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_cub var;

	if (argc != 2)
		exit(1);
	var.p_x = 1920 / 2;
	var.p_y = 1080 / 2;
	var.rot = 90;
	get_info(&var);
	cub_info(argv[1], &var);
	ft_draw_player(&var, 0xFF00FF);
	mlx_hook(var.win_ptr, 2, 1L<<0, ft_go, &var);
	mlx_hook(var.win_ptr, 17, 1L<<17, ft_close, &var);
	mlx_loop(var.mlx_ptr);
	return (0);
}

// w = 13, a = 0, s = 1, d = 2, up = 126, left = 123, right = 124, down = 125

// la commande : clear && make && make fclean && ./a.out fichier.cub

// l'autre commande : gcc -lmlx -framework OpenGL -framework AppKit cub3d.a && clear && ./a.out