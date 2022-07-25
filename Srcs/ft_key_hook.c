/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:59:05 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/25 16:05:10 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

static void	ft_reset(t_win *f)
{
	ft_init_fractol_limits(f);
	f->color = 0xABCDEF;
	mlx_clear_window(f->mlx, f->win);
	ft_draw(f);
}

void	ft_move_arrow(t_win *f, double segment, int keycode)
{
	f->cent_r = f->max_r - f->min_r;
	f->cent_i = f->max_i - f->min_i;
	if (keycode == LEFT || keycode == Q)
	{
		f->min_r -= f->cent_r * segment;
		f->max_r -= f->cent_r * segment;
	}
	else if (keycode == RIGHT || keycode == D)
	{
		f->min_r += f->cent_r * segment;
		f->max_r += f->cent_r * segment;
	}
	else if (keycode == TOP || keycode == Z)
	{
		f->min_i -= f->cent_i * segment;
		f->max_i -= f->cent_i * segment;
	}
	else if (keycode == BOTTOM || keycode == S)
	{
		f->min_i += f->cent_i * segment;
		f->max_i += f->cent_i * segment;
	}
	ft_draw(f);
}

static void	ft_change_fractal(t_win *f, int keycode)
{
	if (keycode == 18 && f->type != MANDELBROT)
		f->type = MANDELBROT;
	else if (keycode == 19 && f->type != JULIA)
		f->type = JULIA;
	else if (keycode == 20 && f->type != BURNINGSHIP)
		f->type = BURNINGSHIP;
	ft_init_fractol_limits(f);
	ft_draw(f);
}

static void	ft_change_color(t_win *f, int keycode)
{
	if (keycode == 21)
	{
		f->color += 500;
		ft_set_colors(f, f->color);
	}
	else
	{
		f->color -= 500;
		ft_set_colors(f, f->color);
	}
	ft_draw(f);
}

int	key_hook(int key, t_win *f)
{
	if (key == 53)
		exit(1);
	else if (key == LEFT || key == RIGHT || key == Q || key == D)
		ft_move_arrow(f, 0.2, key);
	else if (key == BOTTOM || key == TOP || key == Z || key == S)
		ft_move_arrow(f, 0.2, key);
	else if (key == 24)
		ft_zoom(f, 0.5);
	else if (key == 27)
		ft_zoom(f, 2.0);
	else if (key == SPACE)
		ft_reset(f);
	else if (key == 21 || key == 23)
		ft_change_color(f, key);
	else if (key == 18 || key == 19 || key == 20)
		ft_change_fractal(f, key);
	return (0);
}
