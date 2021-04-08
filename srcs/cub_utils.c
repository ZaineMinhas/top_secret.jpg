/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:06:20 by zminhas           #+#    #+#             */
/*   Updated: 2021/04/08 14:27:22 by zminhas          ###   ########.fr       */
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

int	ft_strlen_remix(char *str)
{
	int i;

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
}