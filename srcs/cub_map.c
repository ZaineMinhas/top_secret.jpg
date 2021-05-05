/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:27:38 by zminhas           #+#    #+#             */
/*   Updated: 2021/05/05 18:24:39 by zminhas          ###   ########.fr       */
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

void	player_pos(t_cub *var, char c, int x, int y)
{
	if (var->player)
	{
		printf("trop de joueurs\n");
		exit(1);
	}
	var->player++;
	var->p_x = x + 0.5;
	var->p_y = y + 0.5;
	if (c == 'E')
		var->rot = 0;
	else if (c == 'N')
		var->rot = 90;
	else if (c == 'W')
		var->rot = 180;
	else if (c == 'S')
		var->rot = 270;
}

int		*int_line(t_cub *var, int j)
{
	char	*str;
	int		*map_line;
	int		i;

	i = ft_strlen(var->map->content) + 1;
	var->map_line[j] = i - 1;
	if (i > var->map_x)
		var->map_x = i;
	map_line = (int *)malloc(sizeof(int) * i);
	if (!map_line)
		exit(1);
	str = var->map->content;
	while (i--)
	{
		if (str[i] == '\t' || str[i] == ' ')
			map_line[i] = 0;
		else if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
		{
			map_line[i] = 0;
			player_pos(var, str[i], i, j);
		}
		else
			map_line[i] = (int)str[i] - '0';
	}
	return (map_line);
}

void	cub_map(t_cub *var)
{
	int	i;
	//int	j;

	i = -1;
	var->map_y = ft_lstsize(var->map);
	var->int_map = (int **)malloc(sizeof(int *) * var->map_y);
	var->map_line = (int *)malloc(sizeof(int) * var->map_y);
	if (!var->int_map || !var->map_line)
		exit(1);
	while (++i < var->map_y)
	{
		var->int_map[i] = int_line(var, i);
		var->map = var->map->next;
	}
	/*i = -1;
	while (++i < var->map_y)
	{
		j = -1;
		while (var->int_map[i][++j] != -48)
			printf("%d", var->int_map[i][j]);
		printf("|%d|\n", var->map_line[i]);
	}
	printf("w_map : %d\n", var->map_x);
	printf("h_map : %d\n", var->map_y);*/
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
	var->map = var->map->next;
	cub_map(var);
}
