/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:52:37 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/02 11:06:28 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

t_win	init_win(void)
{
	t_win	args;

	args.mlx = mlx_init();
	args.win = mlx_new_window(args.mlx, WIDTH, HEIGHT, "Fractol by Lolemmen");
	args.min_r = -2.0;
	args.max_r = 1.0;
	args.min_i = -1.5;
	args.max_i = args.min_i + (args.max_r - args.min_r) * HEIGHT / WIDTH;
	args.const_r = 0.3; // 0.183333, 0.096667, -0.766667, 0.3, -0.1011
	args.const_i = 0.5; // 0.596667, -0.613333, -0.090000, 0.5, 0.9563
	args.type = 0;
	args.img = mlx_new_image(args.mlx, WIDTH, HEIGHT);
	args.img_ptr = mlx_get_data_addr(args.img, &args.bpp, &args.sl, &args.end);
	return (args);
}

int	main(int argc, char **argv)
{
	t_win	args;

	if (argc < 2)
	{
		ft_putendl("Usage : ./fractol \"fractal_name : Mandelbrot, ...\"");
		exit(1);
	}
	args = init_win();
	display_values(&args);
	parsing(&args, ft_strlowcase(argv[1]));
	display_values(&args);
	mlx_key_hook(args.win, key_hook, &args);
	mlx_mouse_hook(args.win, mouse_hook, &args);
	ft_draw(&args);
	mlx_loop(args.mlx);
}
