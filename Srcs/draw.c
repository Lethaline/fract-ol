/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:04:14 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/10 15:59:44 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void	ft_draw(t_win *f)
{
	mlx_clear_window(f->mlx, f->win);
	f->y = 0;
	while (f->y < HEIGHT)
	{
		f->x = 0;
		while (f->x < WIDTH)
		{
			f->cr = f->min_r + f->x * (f->max_r - f->min_r) / WIDTH;
			f->ci = f->min_i + f->y * (f->max_i - f->min_i) / HEIGHT;
			ft_parse_fractale(f);
			f->x++;
		}
		f->y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
