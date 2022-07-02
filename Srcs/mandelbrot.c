/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:20:21 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/02 10:43:48 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void	mandelbrot(t_win *args)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	n = 0;
	zr = 0;
	zi = 0;
	while (n < 80)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + args->ci;
		zr = (zr * zr) - (zi * zi) + args->cr;
		zi = tmp;
		n++;
	}
	color(args, n);
}
