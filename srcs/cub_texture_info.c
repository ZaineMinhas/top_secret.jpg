/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_texture_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:46:04 by zminhas           #+#    #+#             */
/*   Updated: 2021/03/29 16:49:14 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_no(char *line, t_cub *var)
{
	if (line[2] != ' ')
		return (1);
	var->tex->no = ft_strdup(line + 3);
	if (var->tex->no)
		return (0);
	return (1);
}

int	get_so(char *line, t_cub *var)
{
	if (line[2] != ' ')
		return (1);
	var->tex->so = ft_strdup(line + 3);
	if (var->tex->so)
		return (0);
	return (1);
}

int	get_we(char *line, t_cub *var)
{
	if (line[2] != ' ')
		return (1);
	var->tex->we = ft_strdup(line + 3);
	if (var->tex->we)
		return (0);
	return (1);
}

int	get_ea(char *line, t_cub *var)
{
	if (line[2] != ' ')
		return (1);
	var->tex->ea = ft_strdup(line + 3);
	if (var->tex->ea)
		return (0);
	return (1);
}
