/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:22:50 by anovelli          #+#    #+#             */
/*   Updated: 2023/01/24 15:57:41 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

static void	move_up(t_rules *rules, float rcos, float rsin)
{
	//int	res1;
	//int	res2;

	//res1 = colliding(rules, ray_cos, 0, 1);
	//res2 = colliding(rules, 0, ray_sin, 1);
	rules->player.x += rules->player.d_x * rules->player.speed;
	rules->player.y += rules->player.d_y * rules->player.speed;
}

static void	move_down(t_rules *rules, float rcos, float rsin)
{
	//int	res1;
	//int	res2;

	//res1 = colliding(rules, ray_cos, 0, 1);
	//res2 = colliding(rules, 0, ray_sin, 1);
	rules->player.x -= rules->player.d_x * rules->player.speed;
	rules->player.y -= rules->player.d_y * rules->player.speed;
}

static void	move_left(t_rules *rules, float rcos, float rsin)
{
	//int	res1;
	//int	res2;

	//res1 = colliding(rules, ray_cos, 0, 1);
	//res2 = colliding(rules, 0, ray_sin, 1);
	rules->player.x += rules->player.d_x * rules->player.speed;
	rules->player.y -= rules->player.d_y * rules->player.speed;
}

static void	move_right(t_rules *rules, float rcos, float rsin)
{
	//int	res1;
	//int	res2;

	//res1 = colliding(rules, ray_cos, 0, 1);
	//res2 = colliding(rules, 0, ray_sin, 1);
	rules->player.x -= rules->player.d_x * rules->player.speed;
	rules->player.y += rules->player.d_y * rules->player.speed;
}


/*calcolati i valori del coseno e del seno dell'angolo di visuale del giocatore moltiplicati per la velocità del giocatore.*/
void	moves(t_rules *rules, char d)
{
	float	rcos;
	float	rsin;

	//rcos = rules->player.d_x * rules->player.speed;
	//rsin = rules->player.d_y * rules->player.speed;
	if (d == 'w')
		move_up(rules, rcos, rsin);
	else if (d == 'a')
		move_left(rules, rcos, rsin);
	else if (d == 's')
		move_down(rules, rcos, rsin);
	else if (d == 'd')
		move_right(rules, rcos, rsin);
}