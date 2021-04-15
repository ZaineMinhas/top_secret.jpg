/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:27:38 by zminhas           #+#    #+#             */
/*   Updated: 2021/04/15 17:32:36 by zminhas          ###   ########.fr       */
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

void	put_cub(char str, int ***dest,int i,int j)
{
	if (str == '1')
		*dest[i][j] = 1;
	else if (str == '0')
		*dest[i][j] = 0;
	else if (str == ' ')
		*dest[i][j] = 2;
	else if (str == '\t')
		*dest[i][j] = 2;
}

void	cub_map(t_cub *var)
{
	t_list	*addr;
	char	*str;
	int		i;
	int		j;

	i = 0;
	addr = var->map;
	var->int_map = (int **)malloc(sizeof(int *) * ft_lstsize(var->map));
	if (!var->int_map)
		exit(1);
	while (addr)
	{
		printf("nik\n");
		j = -1;
		var->int_map[i] = (int *)malloc(sizeof(int) * ft_strlen(addr->content));
		if (!var->int_map[i])
			exit(1);
		str = addr->content;
		while (str[++j])
			put_cub(str[j], &var->int_map, i, j);
		i++;
		addr = addr->next;
	}
	i = -1;
	while (var->int_map[++i])
	{
		j = -1;
		while (var->int_map[i][++j] != '\n')
			printf("%d", var->int_map[i][j]);
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
			ft_lstadd_back(&var->map, ft_lstnew(line));
		i++;
	}
	cub_map(var);
}
