/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:27:38 by zminhas           #+#    #+#             */
/*   Updated: 2021/03/29 16:00:20 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cub_info(char *argv, t_cub *var)
{
	char *line;
	int fd;

	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (line[0] == 'N' && line[1] == 'O')
			get_no(line, var);
		else if (line[0] == 'S' && line[1] == 'O')
			get_so(line, var);
		else if (line[0] == 'W' && line[1] == 'E')
			get_we(line, var);
		else if (line[0] == 'E' && line[1] == 'A')
			get_ea(line, var);
		else if (line[0] == 'R')
			get_r(line, var);
		else if (line[0] == 'S')
			get_s(line, var);
		else if (line[0] == 'F')
			get_f(line, var);
		else if (line[0] == 'C')
			get_c(line, var);
	}
}

