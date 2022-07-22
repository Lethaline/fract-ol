/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 22:31:16 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/21 22:58:16 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putendl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_display_available(void)
{
	ft_putendl("");
	ft_putendl("Arguments to define the fractal's type :");
	ft_putendl("1 - Mandelbrot");
	ft_putendl("2 - Julia");
	ft_putendl("3 - Burningship");
	ft_putendl("# ---------------- #");
	ft_putendl("For Julia's set, you can add some constant numbers.");
	ft_putendl("Like : ");
	ft_putendl("0.3, 0.5");
	ft_putendl("0.183333, 0.596667");
	ft_putendl("0.096667, -0.613333");
}

void	ft_display_controls(void)
{
	ft_putendl("Controls : ");
	ft_putendl("");
	ft_putendl("Use mouse to zoom @ mouse.");
	ft_putendl("Arrows will move the screen.");
	ft_putendl("Space will reset your screen.");
	ft_putendl("1, 2, 3 correspond to the type of fractal.");
	ft_putendl("4 and 5 will change the color.");
	ft_putendl("The cross or Esc will shut down the project.");
}
