/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_texture2_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:21:13 by zminhas           #+#    #+#             */
/*   Updated: 2021/04/15 16:43:11 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_r(char *line, t_cub *var)
{
	int i;

	*line += 1;
	if (*line != ' ')
		return (1);
	i = -1;
	while (++i < 2)
	{
		var->col->r[i] = ft_atoi(line);
		if (!var->col->r[i])
			return (1);
		*line += intlen(var->col->r[i]);
	}
	if (!var->col->r[i])
		return (1);
	return (0);
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
	int i;

	*line += 1;
	if (*line != ' ')
		return (1);
	i = -1;
	while (++i < 3)
	{
		var->col->f[i] = ft_atoi(line);
		if (!var->col->f[i])
			return (1);
		*line += intlen(var->col->f[i]) + 1;
	}
	if (!var->col->f[i])
		return (1);
	return (0);
}

int	get_c(char *line, t_cub *var)
{
	int i;

	*line += 1;
	if (*line != ' ')
		return (1);
	i = -1;
	while (++i < 3)
	{
		var->col->c[i] = ft_atoi(line);
		if (!var->col->c[i])
			return (1);
		*line += intlen(var->col->c[i]) + 1;
	}
	if (!var->col->c[i])
		return (1);
	return (0);
}
