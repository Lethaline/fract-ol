/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:20:23 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/22 18:13:49 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void	ft_julia(t_win *f)
{
	int		n;
	double	tmp;
	double	zr;
	double	zi;

	n = 0;
	zr = f->cr;
	zi = f->ci;
	while (n < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + f->const_i;
		zr = (zr * zr) - (zi * zi) + f->const_r;
		zi = tmp;
		n++;
	}
	ft_color(f, n);
}
