/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:23:56 by anovelli          #+#    #+#             */
/*   Updated: 2023/02/09 14:38:12 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d_bonus.h"

static void	inpmap_init(t_rules *rules)
{
	rules->inpmap.north_wall = NULL;
	rules->inpmap.south_wall = NULL;
	rules->inpmap.east_wall = NULL;
	rules->inpmap.west_wall = NULL;
	rules->inpmap.ceiling = 0;
	rules->inpmap.floor = 0;
	rules->inpmap.line_offset = 0;
	rules->inpmap.block_width = 64;
	rules->inpmap.mini_block_width = rules->inpmap.block_width / 4;
	init_xpm_img(rules, &rules->inpmap.exit[0], "textures/exit-close.xpm");
	init_xpm_img(rules, &rules->inpmap.exit[1], "textures/exit_finale.xpm");
	init_xpm_img(rules, &rules->inpmap.exit[2], "textures/exit-only-mage.xpm");
	init_xpm_img(rules, &rules->inpmap.exit[3], "textures/exit-only-skull.xpm");
}

static void	init_keys(t_rules *rules)
{
	rules->keys.w_pressed = 0;
	rules->keys.a_pressed = 0;
	rules->keys.s_pressed = 0;
	rules->keys.d_pressed = 0;
	rules->keys.l_pressed = 0;
	rules->keys.r_pressed = 0;
	rules->keys.shift_pressed = 0;
}

void	init_rules(t_rules *rules)
{
	rules->mlx.win_width = 1024;
	rules->mlx.win_height = 720;
	init_mlx(&rules->mlx);
	rules->n_frames = 1;
	inpmap_init(rules);
	init_keys(rules);
	rules->inpmap.door_image[0] = init_door(0, rules);
	rules->inpmap.door_image[1] = init_door(1, rules);
	rules->flag_skull = 0;
	rules->flag_hat = 0;
	rules->win_flag = 0;
	rules->dist_array = malloc(sizeof(double) * (rules->mlx.win_width + 1));
	if (!rules->dist_array)
		ft_exit("Malloc error");
	rules->won = 0;
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx)
		exit(-1);
	mlx->mlx_win = mlx_new_window(mlx->mlx, mlx->win_width,
			mlx->win_height, "Cub3d");
}

void	init_img(t_rules *rules, t_image *img, int w, int h)
{
	img->img = mlx_new_image(rules->mlx.mlx, w, h);
	if (!img->img)
		ft_exit("Error initializing image 1");
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_length, &img->endian);
}
