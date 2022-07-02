/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:44:03 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/02 10:43:41 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>

# ifndef WIDTH
#  define WIDTH 900
# endif
# ifndef HEIGHT
#  define HEIGHT 900
# endif
# ifndef MAX_ITERATIONS
#  define MAX_ITERATIONS 80
# endif

enum touche {
	ESC = 53,
	LEFT = 123,
	RIGHT = 124,
	BOTTOM = 125,
	TOP = 126,
	Z = 13,
	S = 1,
	Q = 0,
	D = 2,
	ENTER = 36,
	SPACE = 49,
	NB1 = 18,
	NB2 = 19,
	NB3 = 20,
	NB4 = 21,
	NB5 = 23
};

typedef struct s_win {
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_ptr;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	const_r;
	double	const_i;
	double	cr;
	double	ci;
	int		bpp;
	int		sl;
	int		end;
	int		mouse_x;
	int		mouse_y;
	int		y;
	int		x;
	int		color;
	int		type;
}				t_win;

char	*ft_strlowcase(char *str);
int		ft_strcmp(char *str1, char *str2);
int		key_hook(int keycode, t_win *args);
int		mouse_hook(int keycode, t_win *args);
void	color(t_win *args, int n);
void	move_arrow(t_win *args, int keycode);
void	burningship(t_win *args);
void	julia(t_win *args);
void	mandelbrot(t_win *args);
void	tricorn(t_win *args);
void	parsing(t_win *args, char *av);
void	ft_parse_fractale(t_win *args);
void	reset(t_win *args);
void	display_values(t_win *args);
void	ft_putendl(char *str);
void	ft_draw(t_win *args);
void	ft_put_text_on_screen(t_win *args);

#endif
