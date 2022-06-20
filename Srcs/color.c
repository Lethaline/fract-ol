/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:12:03 by lolemmen          #+#    #+#             */
/*   Updated: 2022/06/19 11:55:07 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void	color(t_win *args, int x, int y, int n)
{
	if (n >= 0 && n <= MAX_ITERATIONS / 2 - 1)
		mlx_pixel_put(args->mlx, args->win, x, y, 0xFFFFFF);
	else if ((n >= MAX_ITERATIONS / 2) && (n <= MAX_ITERATIONS - 1))
		mlx_pixel_put(args->mlx, args->win, x, y, 0x00FFFF);
	else
		mlx_pixel_put(args->mlx, args->win, x, y, 0x000000);
}
