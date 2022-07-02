/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:12:03 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/02 11:02:13 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void	color(t_win *args, int n)
{
	int color;
	int	pixel;
	(void)n;

	color = 0xABCDEF;
	if (args->bpp != 32)
		color = mlx_get_color_value(args->mlx, color);
	pixel = (args->y * WIDTH * 4) + (args->x * 4);
	if (args->end == 1)
	{
		args->img_ptr[pixel] = (color >> 24);
		args->img_ptr[pixel + 1] = (color >> 16) & 0xFF;
		args->img_ptr[pixel + 2] = (color >> 8) & 0xFF;
		args->img_ptr[pixel + 3] = (color) & 0xFF;
	}
	else if (args->end == 0)
	{
		args->img_ptr[pixel] = (color) & 0xFF;
		args->img_ptr[pixel + 1] = (color >> 8) & 0xFF;
		args->img_ptr[pixel + 2] = (color >> 16) & 0xFF;
		args->img_ptr[pixel + 3] = (color >> 24);
	}
	mlx_put_image_to_window(args->mlx, args->win, args->img, 0, 0);
}
