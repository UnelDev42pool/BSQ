/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edechena <edechena@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:11:14 by edechena          #+#    #+#             */
/*   Updated: 2023/07/24 10:11:15 by edechena         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	fill_bsq(t_data *d, unsigned short **matrix)
{
	int	x;
	int	y;
	int	top_x;
	int	top_y;

	top_x = d->bsq_x - matrix[d->bsq_y][d->bsq_x] + 1;
	top_y = d->bsq_y - matrix[d->bsq_y][d->bsq_x] + 1;
	y = 0;
	while (y <= d->nbr_lines)
	{
		x = 0;
		while (x <= d->len_lines)
		{
			if ((y >= top_y && y <= d->bsq_y) && (x >= top_x && x <= d->bsq_x))
				d->map[(y * (d->len_lines + 1)) + x + d->n] = d->filler;
			x++;
		}
		y++;
	}
}

void	display_bsq(t_data *d, unsigned short **matrix)
{
	fill_bsq(d, matrix);
	write(1, &d->map[d->n], d->nbr_lines * (d->len_lines + 1));
}
