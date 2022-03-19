/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:44:32 by momeaizi          #+#    #+#             */
/*   Updated: 2022/03/19 19:29:03 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

int	main(int ac, char **av)
{
	t_mlx	var;

	if (ac < 2)
		return (help(1));
	init(&var);
	arg_check(ac, av, &var);
	init_win(&var);
	fractal(&var);
	if (var.jul)
		mlx_hook(var.mlx_win, 06, 0L, mouse_mv, &var);
	mlx_hook(var.mlx_win, 04, 0L, mouse_hook, &var);
	mlx_hook(var.mlx_win, 02, 0L, key_hook, &var);
	mlx_hook(var.mlx_win, 17, 0L, destroy, &var);
	mlx_loop(var.mlx);
	return (0);
}

void	arg_check(int ac, char **av, t_mlx *var)
{
	if (ac == 2 && ft_strcmp("Mandelbrot", av[1]))
		var->mandel = 1;
	else if (ft_strcmp("Julia", av[1]))
	{
		if (ac == 3 && *av[2] >= '0' && *av[2] <= '5' && !av[2][1])
			var->fix_pos = *av[2] - '0';
		else if (ac >= 3)
			exit(help(0));
		init_c(var);
		var->jul = 1;
	}
	else if (ft_strcmp("Celtic", av[1]))
		var->cel = 1;
	else
	{
		exit(help(1));
	}
}

int	help(char c)
{
	if (c)
		write(1, "Unvalide fractal!\nChoose one of those\n\
Mandelbrot\nJulia [0-5]\nCeltic\n", 69);
	else
		write(1, "add a valid parameter [0-5] to fix Julia\n", 42);
	return (0);
}
