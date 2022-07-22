/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:44:03 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/22 18:14:17 by lolemmen         ###   ########.fr       */
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

enum e_utils {
	ESC = 53,
	LEFT = 123,
	RIGHT = 124,
	BOTTOM = 125,
	TOP = 126,
	Z = 13,
	S = 1,
	Q = 0,
	D = 2,
	SPACE = 49,
	NB1 = 18,
	NB2 = 19,
	NB3 = 20,
	NB4 = 21,
	NB5 = 23,
	MANDELBROT = 1,
	JULIA = 2,
	BURNINGSHIP = 3
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
	double	cent_r;
	double	cent_i;
	int		mouse_x;
	int		mouse_y;
	int		y;
	int		x;
	int		color;
	int		*colors;
	int		type;
}				t_win;

t_win	ft_init_fractal(void);
void	ft_burningship(t_win *f);
void	ft_clean_values(t_win *f);
void	ft_color(t_win *f, int n);
void	ft_set_colors(t_win *f, int color);
void	ft_display_controls(void);
void	ft_display_available(void);
void	ft_putendl(char *str);
void	ft_putchar(char c);
void	ft_draw(t_win *f);
void	ft_error_message(char *message, int close, t_win *f);
void	ft_init_win(t_win *f);
void	ft_init_img(t_win *f);
void	ft_init_fractol_limits(t_win *f);
void	ft_julia(t_win *f);
void	ft_move_arrow(t_win *f, double segment, int keycode);
void	ft_mandelbrot(t_win *f);
void	ft_zoom(t_win *f, double zoom);
void	ft_parse_fractale(t_win *f);
void	ft_parsing(t_win *f, char **av);
int		ft_clean_close(t_win *f);
int		key_hook(int keycode, t_win *f);
int		mouse_hook(int keycode, int x, int y, t_win *f);
int		ft_strcmp(char *str1, char *str2);
char	*ft_strlowcase(char *str);
double	ft_atof(char *str);

#endif
