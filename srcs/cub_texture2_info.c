/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_texture2_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:21:13 by zminhas           #+#    #+#             */
/*   Updated: 2021/04/19 15:20:35 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_r(char *line, t_cub *var)
{
	char	**split;

	line += 1;
	if (*line != ' ')
		return (1);
	split = ft_split(line, ' ');
	if (!split)
		exit(1);
	var->col->r[0] = ft_atoi(split[0]);
	var->col->r[1] = ft_atoi(split[1]);
	if (!(var->col->r[0] || var->col->r[1]))
		return (1);
	return (0);
}

int	get_s(char *line, t_cub *var)
{
	if (line[1] != ' ')
		return (1);
	var->col->s = ft_strdup(line + 2);
	if (var->col->s)
		return (0);
	return (1);
}

int	get_f(char *line, t_cub *var)
{
	char	**split;

	line += 1;
	if (*line != ' ')
		return (1);
	split = ft_split(line, ',');
	if (!split)
		exit(1);
	var->col->f[0] = ft_atoi(split[0]);
	var->col->f[1] = ft_atoi(split[1]);
	var->col->f[2] = ft_atoi(split[2]);
	if (!(var->col->f[0] || var->col->f[1] || var->col->f[2]))
		return (1);
	return (0);
}

int	get_c(char *line, t_cub *var)
{
	char	**split;

	line += 1;
	if (*line != ' ')
		return (1);
	split = ft_split(line, ',');
	if (!split)
		exit(1);
	var->col->c[0] = ft_atoi(split[0]);
	var->col->c[1] = ft_atoi(split[1]);
	var->col->c[2] = ft_atoi(split[2]);
	if (!(var->col->c[0] || var->col->c[1] || var->col->c[2]))
		return (1);
	return (0);
}
