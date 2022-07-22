/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:38:46 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/22 18:14:06 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

t_win	ft_init_fractal(void)
{
	t_win	f;

	f.mlx = NULL;
	f.win = NULL;
	f.min_r = 0;
	f.max_r = 0;
	f.min_i = 0;
	f.max_i = 0;
	f.cent_r = 0;
	f.cent_i = 0;
	f.const_r = 0.3;
	f.const_i = 0.5;
	f.color = 0xABCDEF;
	f.colors = (int *)malloc(sizeof(int) * MAX_ITERATIONS + 1);
	if (!f.colors)
		ft_error_message("Error : Malloc", 1, &f);
	ft_set_colors(&f, f.color);
	f.type = 0;
	return (f);
}

void	ft_init_win(t_win *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fract-ol by Lolemmen");
	if (!f->win || !f->mlx)
		ft_error_message("Error : mlx command", 1, f);
}

void	ft_init_img(t_win *f)
{
	int		endian;
	int		bits_by_pixel;
	int		size_line;
	char	*buffer;

	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	buffer = mlx_get_data_addr(f->img, &bits_by_pixel, &size_line, &endian);
	f->img_ptr = buffer;
	if (!f->img || !f->img_ptr)
		ft_error_message("Error : Img command", 1, f);
}

void	ft_init_fractol_limits(t_win *f)
{
	if (f->type == JULIA)
	{
		f->min_r = -2.0;
		f->max_r = 2.0;
		f->min_i = -2.0;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
	else
	{
		f->min_r = -2.0;
		f->max_r = 1.0;
		f->min_i = -1.5;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
}
