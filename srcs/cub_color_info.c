/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_color_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:45:52 by zminhas           #+#    #+#             */
/*   Updated: 2021/03/29 16:58:01 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_r(char *line, t_cub *var)
{
	int	r_bis;
	int	j;
	int	i;

	i = 2;
	j = -1;
	if (line[1] != ' ')
		return (1);
	while (++j < 2)
	{
		var->col->r[j] = ft_atoi(line + i);
		r_bis = var->col->r[j];
		i++;
		while (r_bis % 10)
		{
			r_bis %= 10;
			i++;
		}
	}
	if (var->col->r[0] && var->col->r[1])
		return (0);
	return (1);
}

int	get_s(char *line, t_cub *var)
{
	if (line[1] != ' ')
		return (1);
	var->col->s = ft_strdup(line + 3);
	if (var->col->s)
		return (0);
	return (1);
}

int	get_f(char *line, t_cub *var)
{
	int	f_bis;
	int	j;
	int	i;

	i = 2;
	j = -1;
	if (line[1] != ' ')
		return (1);
	while (++j < 3)
	{
		var->col->f[j] = ft_atoi(line + i);
		f_bis = var->col->f[j];
		i++;
		while (f_bis % 10)
		{
			f_bis %= 10;
			i++;
		}
		if (line[i] == ',')
			i++;
	}
	if (var->col->r[0] && var->col->r[1] && var->col->r[2])
		return (0);
	return (1);
}

int	get_c(char *line, t_cub *var)
{
	int	r_bis;
	int	j;
	int	i;

	i = 2;
	j = -1;
	if (line[1] != ' ')
		return (1);
	while (++j < 2)
	{
		var->col->r[j] = ft_atoi(line + i);
		r_bis = var->col->r[j];
		i++;
		while (r_bis % 10)
		{
			r_bis %= 10;
			i++;
		}
		if (line[i] == ',')
			i++;
	}
	if (var->col->r[0] && var->col->r[1] && var->col->r[2])
		return (0);
	return (1);
}
