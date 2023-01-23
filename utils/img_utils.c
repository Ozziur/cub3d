/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:10:38 by mruizzo           #+#    #+#             */
/*   Updated: 2023/01/23 16:12:50 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	easy_pxl(t_image *image, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0)
		return ;
	dst = image->addr + (y * image->line_length + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
	return ;
}

unsigned int	get_color_arr(unsigned char arr[3])
{
	return (*(unsigned int *)(unsigned char [4]){arr[2], arr[1], arr[0], 0});
}