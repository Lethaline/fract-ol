/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:00:26 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/02 15:30:43 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void	ft_parsing(t_win *args, char **av)
{
	char *type;

	type = ft_strlowcase(av[1]);
	if (ft_strcmp(type, "mandelbrot") == 0)
		args->type = 1;
	else if (ft_strcmp(type, "julia") == 0)
		args->type = 2;
	else if (ft_strcmp(type, "burningship") == 0)
		args->type = 3;
	else if (ft_strcmp(type, "tricorn") == 0)
		args->type = 4;
	else
		ft_error_message("Error : Invalid Argument.", 1, args);
	ft_init_fractol_limits(args);
}
