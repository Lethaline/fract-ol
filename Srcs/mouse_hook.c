/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 12:01:14 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/09 15:42:40 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

static void	zoom(t_win *f, double zoom)
{
	double	center_r;
	double	center_i;

	center_r = f->min_r - f->max_r;
	center_i = f->max_i - f->min_i;
	f->max_r = f->max_r + (center_r - zoom * center_r) / 2;
	f->min_r = f->max_r + zoom * center_r;
	f->min_i = f->min_i + (center_i - zoom * center_i) / 2;
	f->max_i = f->min_i + zoom * center_i;
	ft_draw(f);
}

int	mouse_hook(int keycode, int x, int y, t_win *args)
{
	(void)args;
	if (keycode == 5)
	{
		zoom(args, 0.5);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			move_arrow(args, (double)x * -1 / WIDTH, 123);
		else if (x > 0)
			move_arrow(args, (double)x / WIDTH, 124);
		if (y < 0)
			move_arrow(args, (double)y * -1 / HEIGHT, 126);
		else if (y > 0)
			move_arrow(args, (double)y / HEIGHT, 125);
	}
	else if (keycode == 4)
		zoom(args, 2.0);
	printf("%d : %d - %d\n", keycode, x, y);
	return (0);
}
