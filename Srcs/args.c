/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:00:26 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/10 15:52:59 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void	ft_parsing(t_win *f, char **av)
{
	char	*type;

	type = ft_strlowcase(av[1]);
	if (ft_strcmp(type, "mandelbrot") == 0)
		f->type = 1;
	else if (ft_strcmp(type, "julia") == 0)
		f->type = 2;
	else if (ft_strcmp(type, "burningship") == 0)
		f->type = 3;
	else if (ft_strcmp(type, "tricorn") == 0)
		f->type = 4;
	else
		ft_error_message("Error : Invalid Argument.", 1, f);
	ft_init_fractol_limits(f);
}
