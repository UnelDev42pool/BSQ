/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edechena <edechena@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:10:59 by edechena          #+#    #+#             */
/*   Updated: 2023/07/25 11:26:28 by edechena         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	process_empty(t_data *d, unsigned short **matrix, int x, int y)
{
	short	tmp;

	if (x == 0 || y == 0)
		matrix[y][x] = 1;
	else
	{
		if (matrix[y - 1][x] > matrix[y][x - 1])
			tmp = matrix[y][x - 1];
		else
			tmp = matrix[y - 1][x];
		if (tmp > matrix[y - 1][x - 1])
			matrix[y][x] = matrix[y - 1][x - 1] + 1;
		else
			matrix[y][x] = tmp + 1;
		if (matrix[y][x] > matrix[d->bsq_y][d->bsq_x])
		{
			d->bsq_y = y;
			d->bsq_x = x;
		}
	}
}

bool	process_end_check(t_data *d, int *x, int *y, int i)
{
	if (d->map[i] == '\n')
	{
		if (*x != d->len_lines)
		{
			ft_putstr("map error\n");
			return (false);
		}
		*x = -1;
		*y = *y + 1;
	}
	else
	{
		ft_putstr("map error\n");
		return (false);
	}
	return (true);
}

bool	process(t_data *d, unsigned short **matrix)
{
	int	x;
	int	y;
	int	i;

	i = d->n;
	x = 0;
	y = 0;
	while (i < (d->len_lines + 1) * d->nbr_lines + d->n)
	{
		if (y >= d->nbr_lines)
		{
			ft_putstr("map error\n");
			return (false);
		}
		else if (d->map[i] == d->obstacle)
			matrix[y][x] = 0;
		else if (d->map[i] == d->empty)
			process_empty(d, matrix, x, y);
		else if (!process_end_check(d, &x, &y, i))
			return (false);
		i++;
		x++;
	}
	return (true);
}
