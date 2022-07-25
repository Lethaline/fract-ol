/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:52:37 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/25 16:02:17 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

int	main(int ac, char **av)
{
	t_win	f;

	if (ac < 2)
		ft_error_message("Usage : \"./fractol fractal_name\"", 1, &f);
	f = ft_init_fractal();
	ft_parsing(&f, av);
	ft_init_win(&f);
	ft_init_img(&f);
	ft_display_controls();
	mlx_hook(f.win, 17, 0, ft_clean_close, &f);
	mlx_key_hook(f.win, key_hook, &f);
	mlx_mouse_hook(f.win, mouse_hook, &f);
	ft_draw(&f);
	mlx_loop(f.mlx);
	free(&f);
}
