/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:00:26 by lolemmen          #+#    #+#             */
/*   Updated: 2022/06/27 14:35:17 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void	parsing(t_win *args, char *av)
{
	if (ft_strcmp(av, "mandelbrot") == 0)
		args->type = 1;
	else if (ft_strcmp(av, "julia") == 0)
		args->type = 2;
	else if (ft_strcmp(av, "burningship") == 0)
		args->type = 3;
	else if (ft_strcmp(av, "tricorn") == 0)
		args->type = 4;
	else
		exit(1);
}
