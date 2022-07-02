/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:20:23 by lolemmen          #+#    #+#             */
/*   Updated: 2022/06/27 14:36:29 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void	julia(t_win *args)
{
	int		n;
	double	tmp;
	double	zr;
	double	zi;

	n = 0;
	zr = args->cr;
	zi = args->ci;
	while (n < 1000)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + args->const_i;
		zr = (zr * zr) - (zi * zi) + args->const_r;
		zi = tmp;
		n++;
	}
	color(args, n);
}

