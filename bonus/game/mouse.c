/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:00:40 by mruizzo           #+#    #+#             */
/*   Updated: 2023/02/09 12:12:17 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d_bonus.h"

static void	move_mouse(int x, int y, t_rules *rules)
{
	if (x < rules->mouse.x)
	{
		rules->player.dir = increment_angle(rules->player.dir, 40);
		rules->player.plane = increment_angle(rules->player.plane, 40);
	}
	else if (x > rules->mouse.x)
	{
		rules->player.dir = decrement_angle(rules->player.dir, 40);
		rules->player.plane = decrement_angle(rules->player.plane, 40);
	}
	rules->mouse.x = x;
	rules->mouse.y = y;
}

int	mouse(int x, int y, t_rules *rules)
{
	if (x < 0 || y < 0 || x > rules->mlx.win_width || y > rules->mlx.win_height)
		return (0);
	if (!rules->mouse.moved)
	{
		rules->mouse.moved = 1;
		rules->mouse.x = x;
		rules->mouse.y = y;
	}
	move_mouse(x, y, rules);
	rules->player.d_x = cos(rules->player.dir);
	if (rules->player.dir == (double)M_PI)
		rules->player.d_y = 0;
	else
		rules->player.d_y = -sin(rules->player.dir);
	rules->player.plane_x = -cos(rules->player.plane);
	rules->player.plane_y = sin(rules->player.plane);
	return (0);
}
