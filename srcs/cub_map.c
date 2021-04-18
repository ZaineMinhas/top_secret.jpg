/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:27:38 by zminhas           #+#    #+#             */
/*   Updated: 2021/04/18 18:30:26 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_data(char *line, t_cub *var)
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

void	put_cub(int **map, int i, int o, char c)
{
	if (ft_isdigit(c))
		map[o][i] = (int)c - '0';
	else if (c == ' ' || c == '\t')
		map[o][i] = 0;
	else if (c == 'N')
		map[o][i] = 99;
}

void	cub_map(t_cub *var)
{
	char	*str;
	int		i;
	int		j;
	int		o;

	var->map_y = ft_lstsize(var->map);
	var->map_x = 0;
	var->int_map = (int **)malloc(sizeof(int *) * var->map_y);
	if (!var->int_map)
		exit(1);
	o = -1;
	while (var->map)
	{
		o++;
		i = -1;
		j = ft_strlen(var->map->content);
		if (j > var->map_x)
				var->map_x =j;
		var->int_map[o] = (int *)ft_calloc(sizeof(int), j);
		if (!var->int_map[i])
			exit(1);
		str = var->map->content;
		while (++i < j)
			put_cub(var->int_map, i, o, str[i]);
			//var->int_map[o][i] = (int)str[i] - '0';
		var->map = var->map->next;
	}
	i = -1;
	while (++i < var->map_x)
	{
		j = -1;
		while (++j < var->map_y)
			printf("%d", var->int_map[j][i]);
		printf("\n");
	}
}

void	cub_info(char *argv, t_cub *var)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (!fd)
		exit(1);
	while (get_next_line(fd, &line))
	{
		if (i < 8)
			get_data(line, var);
		else
		{
			if (ft_isdigit(line[0]) || line[0] == ' ' || line[0] == '\t')
				ft_lstadd_back(&var->map, ft_lstnew(line));
		}
		i++;
	}
	cub_map(var);
}
