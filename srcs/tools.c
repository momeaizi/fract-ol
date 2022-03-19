/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 20:43:05 by momeaizi          #+#    #+#             */
/*   Updated: 2022/03/13 20:43:06 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = -1;
	while (s1[++i] || s2[i])
		if (s1[i] != s2[i])
			return (0);
	return (1);
}

int	get_color(int it, t_mlx *var)
{
	uint8_t	rgb[3];
	double	div;

	div = (double)it / (double)var->max_it;
	if (var->cs <= 3)
	{
		rgb[var->cs % 3] = 9 * (1 - div) * fpow(div, 3) * 255;
		rgb[(var->cs + 1) % 3] = 15 * fpow((1 - div), 2) * fpow(div, 2) * 255;
		rgb[(var->cs + 2) % 3] = 9 * fpow((1 - div), 3) * div * 255;
	}
	else
	{
		var->cs -= 3;
		get_color(it, var);
	}
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

int	destroy(t_mlx *var)
{
	mlx_destroy_image(var->mlx, var->img.img);
	mlx_destroy_window(var->mlx, var->mlx_win);
	exit(0);
	return (0);
}
