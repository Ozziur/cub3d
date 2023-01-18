/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:29:23 by anovelli          #+#    #+#             */
/*   Updated: 2023/01/18 19:34:17 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

static int	rules_status(t_rules *rules)
{
	if (!rules->inpmap.north_wall || !rules->inpmap.south_wall
		|| !rules->inpmap.east_wall || !rules->inpmap.west_wall
		|| !rules->inpmap.f_color || !rules->inpmap.c_color)
		return (0);
	return (1);
}

void	ft_parsing(char *input, t_rules *rules)
{
	int			fd;
	char		*buf;

	fd = open(input, 'r');
	if (fd < 0)
		exit(-1);//aggiungere stampa
	buf = get_next_line(fd);
	while (buf && !rule_status(rules))
	{
		// rules->line_offset++; chiedere delucidazioni a giorgio o davide
		//save_rule(buf);
		free(buf);
		buf = get_next_line(fd);
	}
	if (!rule_status(rules))
		exit(-1);//aggiungere stampa
	
	/*
	while (!is_map(tmp))
	{
		rules->line_offset++;
		insert_rule(tmp, rules);
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
	*/
}