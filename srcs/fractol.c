/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:12:11 by momeaizi          #+#    #+#             */
/*   Updated: 2022/03/06 12:19:10 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	fractal(t_mlx	*var)
{
	var->y = -1;
	while (++var->y < HEIGHT)
	{
		var->x = -1;
		while (++var->x < WIDTH)
		{
			if (var->mandel)
				mandelbrot(var);
			else if (var->jul)
				julia(var);
			else if (var->cel)
				celtic(var);
		}
	}
	mlx_put_image_to_window(var->mlx, var->mlx_win, var->img.img, 0, 0);
}

int	mouse_mv(int x, int y, t_mlx *var)
{
	if (var->fix_pos == -1 && var->jul)
	{
		var->c.re = (x * var->scale) + var->remin;
		var->c.im = (y * var->scale) - var->immax;
	}
	fractal(var);
	return (0);
}

int	mouse_hook(int key, int x, int y, t_mlx	*var)
{
	if (key == 1)
		var->fix_pos = 1;
	else if (key == 5)
	{
		var->scale *= 0.50;
		var->remin += (x * var->scale);
		var->immax -= (y * var->scale);
		var->max_it += 10;
	}
	else if (key == 4 && var->scale < 0.0066)
	{
		var->remin -= (x * var->scale);
		var->immax += (y * var->scale);
		var->scale /= 0.50;
		var->max_it -= 10;
	}
	else if (key == 2)
		var->cs++;
	fractal(var);
	return (0);
}

int	key_hook(int key, t_mlx	*var)
{
	if (key == 53)
		destroy(var);
	if (key == 69)
		var->max_it += 20;
	else if (key == 78 && var->max_it > 60)
		var->max_it -= 20;
	else if (key == 123)
		var->remin -= (var->scale * 10);
	else if (key == 124)
		var->remin += (var->scale * 10);
	else if (key == 125)
		var->immax -= (var->scale * 10);
	else if (key == 126)
		var->immax += (var->scale * 10);
	fractal(var);
	return (0);
}
