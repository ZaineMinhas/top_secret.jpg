/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:06:20 by zminhas           #+#    #+#             */
/*   Updated: 2021/05/06 18:41:01 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_reset(t_move *move)
{
	move->w = 0;
	move->a = 0;
	move->s = 0;
	move->d = 0;
	move->left = 0;
	move->right = 0;
}

int		ft_iswall(t_cub *var, int x, int y)
{
	if (var->int_map[y][x])
		return (1);
	return (0);
}

int		intlen(int n)
{
	int	len;

	len = 0;
	while (n /= 10)
		len++;
	return (++len);
}

double	bet_0_1(double	nb)
{
	if (nb > 0)
	{
		while (nb > 1)
			nb--;
		return (nb);
	}
	return (nb);
}

double	player_wall_dist(t_cub *var)
{
	double	sideDist[2];

	sideDist[0]	= bet_0_1(var->p_x) / cos((double)var->rot);
	sideDist[1] = bet_0_1(var->p_y) / cos(90 - (double)var->rot);
	printf("|sideDist_x = %f sideDist_y = %f|\n", sideDist[0], sideDist[1]);
	return (0);
}

/*int	ft_strlen_remix(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			i += 4;
		else
			i++;
	}
	return (i);
}*/
