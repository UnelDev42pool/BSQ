/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edechena <edechena@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:11:37 by edechena          #+#    #+#             */
/*   Updated: 2023/07/24 10:11:38 by edechena         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bsq.h"

void	init_data(t_data *d)
{
	d->nbr_lines = 0;
	d->len_lines = 0;
	d->bsq_x = 0;
	d->bsq_y = 0;
	d->map = NULL;
}

unsigned short	**init_matrix(t_data *d)
{
	unsigned short	**matrix;
	int				i;

	matrix = malloc(sizeof(unsigned short *) * d->nbr_lines);
	if (!matrix)
	{
		ft_putstr("Error\n");
		return (NULL);
	}
	i = 0;
	while (i < d->nbr_lines)
	{
		matrix[i] = malloc(sizeof(unsigned short) * d->len_lines);
		if (!matrix[i])
			return (free_matrix_i(matrix, i));
		i++;
	}
	return (matrix);
}
