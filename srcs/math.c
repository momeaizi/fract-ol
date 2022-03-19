/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:59:06 by momeaizi          #+#    #+#             */
/*   Updated: 2022/03/15 15:59:08 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	fpow(double nbr, int pow)
{
	int	i;

	i = 0;
	while (++i < pow)
		nbr *= nbr;
	return (nbr);
}

double	fabs(double nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}
