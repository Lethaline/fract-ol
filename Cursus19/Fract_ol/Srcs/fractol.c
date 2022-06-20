/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:52:37 by lolemmen          #+#    #+#             */
/*   Updated: 2022/06/20 16:11:39 by lolemmen         ###   ########.fr       */
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
	args.const_r = -1.5436; // 0.183333, 0.096667, -0.766667, 0.3
	args.const_i = 0; // 0.596667, -0.613333, -0.090000, 0.5
	return (args);
}

void	display_values(t_win *args)
{
	printf("min_r = %f\n", args->min_r);
	printf("max_r = %f\n", args->max_r);
	printf("min_i = %f\n", args->min_i);
	printf("max_i = %f\n", args->max_i);
}

int	main(int argc, char **argv)
{
	t_win	args;

	if (argc < 2)
		exit(1);
	(void)argv;
	args = init_win();
	mlx_key_hook(args.win, key_hook, &args);
	mlx_mouse_hook(args.win, mouse_hook, &args);
	display_values(&args);
	mandeldraw(&args);
	mlx_loop(args.mlx);
	system("leaks fractol");
}
