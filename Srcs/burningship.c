/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:20:18 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/10 15:53:20 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void	burningship(t_win *f)
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
		tmp = fabs(2 * zr * zi) + f->ci;
		zr = (zr * zr) - (zi * zi) + f->cr;
		zi = tmp;
		n++;
	}
	color(f, n);
}
