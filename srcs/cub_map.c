/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:27:38 by zminhas           #+#    #+#             */
/*   Updated: 2021/04/09 15:21:05 by zminhas          ###   ########.fr       */
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

void	cub_map(t_cub *var)
{
	t_list	*addr;
	char	*str;
	int		**dest;
	int		i;
	int		j;

	i = 0;
	addr = var->map;
	dest = (int **)malloc(sizeof(int *) * ft_lstsize(var->map));
	while (addr)
	{
		j = -1;
		dest[i] = (int *)malloc(sizeof(int) * ft_strlen_remix(addr->content));
		str = addr->content;
		while (str[++j])
		{
			if (str[j] == '1')
				dest[i][j] = 1;
			else if (str[j] == '0')
				dest[i][j] = 0;
			else if (str[j] == ' ')
				dest[i][j] = 2;
			else if (str[j] == '\t')
				dest[i][j] = 2;
		}
		i++;
		addr = addr->next;
	}
}

void	cub_info(char *argv, t_cub *var)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (i < 8)
			get_data(line, var);
		else
			ft_lstadd_back(&var->map, ft_lstnew(line));
		i++;
	}
}
