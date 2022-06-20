/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:44:03 by lolemmen          #+#    #+#             */
/*   Updated: 2022/06/19 18:03:24 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

# define WIDTH 900
# define HEIGHT 900
# define MAX_ITERATIONS 80

typedef struct s_win {
	void	*mlx;
	void	*win;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	const_r;
	double	const_i;
	int		mouse_x;
	int		mouse_y;
}				t_win;

char	*ft_strlowcase(char *str);
int		key_hook(int keycode, t_win *args);
int		mouse_hook(int keycode, t_win *args);
void	color(t_win *args, int x, int y, int n);
void	move_arrow(t_win *args, int keycode);
void	burningdraw(t_win *args);
void	juliadraw(t_win *args);
void	mandeldraw(t_win *args);
void	tridraw(t_win *args);
void	testdraw(t_win *args);

#endif
