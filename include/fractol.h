/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:12:23 by momeaizi          #+#    #+#             */
/*   Updated: 2022/03/15 17:53:59 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>

//	Defining Mouse Button Codes

# define WIDTH 600.0
# define HEIGHT 600.0

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	double		x;
	double		y;
	t_complex	c;
	double		remin;
	double		immax;
	double		scale;
	int			max_it;
	int			cs;
	char		mandel;
	char		jul;
	char		cel;
	char		fix_pos;
}	t_mlx;
//					main
int		help(char c);
void	arg_check(int ac, char **av, t_mlx *var);
//					initialize
void	init(t_mlx	*var);
void	init_win(t_mlx	*var);
void	init_c(t_mlx *var);
//					fractol
void	fractal(t_mlx	*var);
int		mouse_hook(int key, int x, int y, t_mlx	*var);
int		key_hook(int key, t_mlx	*var);
int		mouse_mv(int x, int y, t_mlx *var);
//					sets
void	mandelbrot(t_mlx	*var);
void	julia(t_mlx	*var);
void	celtic(t_mlx	*var);
//					math
double	fpow(double nbr, int pow);
double	fabs(double nbr);
//					tools
int		get_color(int it, t_mlx *var);
void	pixel_put(t_data *data, int x, int y, int color);
int		ft_strcmp(const char *s1, const char *s2);
int		destroy(t_mlx *var);
#endif
