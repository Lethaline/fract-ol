/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:52:37 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/02 12:04:15 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

int	main(int argc, char **argv)
{
	t_win	args;

	if (argc < 2)
		ft_error_message("Usage : \"./fractol fractal_name\"", 1, &args);
	args = ft_init_fractal();
	ft_init_img(&args);
	ft_parsing(&args, argv);
	mlx_key_hook(args.win, key_hook, &args);
	mlx_mouse_hook(args.win, mouse_hook, &args);
	ft_draw(&args);
	mlx_loop(args.mlx);
}
