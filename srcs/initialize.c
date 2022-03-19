/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:34:44 by momeaizi          #+#    #+#             */
/*   Updated: 2022/03/14 12:34:45 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init(t_mlx	*var)
{
	var->mandel = 0;
	var->jul = 0;
	var->cel = 0;
	var->fix_pos = -1;
	var->cs = 0;
	var->max_it = 60;
	var->scale = 4.0 / WIDTH;
	var->remin = -2.0;
	var->immax = 2.0;
	var->c.re = 0;
	var->c.im = 0;
}

void	init_win(t_mlx *var)
{
	var->mlx = mlx_init();
	var->mlx_win = mlx_new_window(var->mlx, HEIGHT, WIDTH, "Mandelbrot set");
	var->img.img = mlx_new_image(var->mlx, HEIGHT, WIDTH);
	var->img.addr = mlx_get_data_addr(var->img.img, &var->img.bits_per_pixel, \
	&var->img.line_length, &var->img.endian);
}

void	init_c(t_mlx *var)
{
	if (var->fix_pos == -1)
		return ;
	if (var->fix_pos == 0)
		var->c = (t_complex){.re = -0.79, .im = 0.15};
	else if (var->fix_pos == 1)
		var->c = (t_complex){.re = -0.162, .im = 1.04};
	else if (var->fix_pos == 2)
		var->c = (t_complex){.re = 0.3, .im = 0.1};
	else if (var->fix_pos == 3)
		var->c = (t_complex){.re = -0.4, .im = 0.6};
	else if (var->fix_pos == 4)
		var->c = (t_complex){.re = -0.12, .im = -0.77};
	else if (var->fix_pos == 5)
		var->c = (t_complex){.re = 0.28, .im = 0.008};
}
