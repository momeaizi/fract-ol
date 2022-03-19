/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 20:42:51 by momeaizi          #+#    #+#             */
/*   Updated: 2022/03/13 20:42:53 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	julia(t_mlx	*var)
{
	t_complex	zn;
	int			it;
	float		real;

	zn.re = 0;
	zn.im = 0;
	it = -1;
	zn.re = (var->x * var->scale) + var->remin;
	zn.im = (var->y * var->scale) - var->immax;
	while (++it < var->max_it && (zn.re * zn.re) + (zn.im * zn.im) < 4)
	{
		real = zn.re;
		zn.re = fpow(zn.re, 2) - fpow(zn.im, 2) + var->c.re;
		zn.im = (2 * zn.im * real) + var->c.im;
	}
	pixel_put(&var->img, var->x, var->y, get_color(it, var));
}

void	mandelbrot(t_mlx	*var)
{
	t_complex	zn;
	int			it;
	double		real;

	it = -1;
	zn.re = 0;
	zn.im = 0;
	var->c.re = (var->x * var->scale) + var->remin;
	var->c.im = (var->y * var->scale) - var->immax;
	while (++it < var->max_it && (zn.re * zn.re) + (zn.im * zn.im) < 4)
	{
		real = zn.re;
		zn.re = fpow(zn.re, 2) - fpow(zn.im, 2) + var->c.re;
		zn.im = (2 * zn.im * real) + var->c.im;
	}
	pixel_put(&var->img, var->x, var->y, get_color(it, var));
}

void	celtic(t_mlx	*var)
{
	t_complex	zn;
	int			it;
	double		real;

	it = -1;
	zn.re = 0;
	zn.im = 0;
	var->c.re = (var->x * var->scale) + var->remin;
	var->c.im = (var->y * var->scale) - var->immax;
	while (++it < var->max_it && (zn.re * zn.re) + (zn.im * zn.im) < 4)
	{
		real = zn.re;
		zn.re = fabs(fpow(zn.re, 2) - fpow(zn.im, 2)) + var->c.re;
		zn.im = (2 * zn.im * real) + var->c.im;
	}
	pixel_put(&var->img, var->x, var->y, get_color(it, var));
}
