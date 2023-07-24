/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edechena <edechena@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:11:21 by edechena          #+#    #+#             */
/*   Updated: 2023/07/24 10:11:22 by edechena         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bsq.h"

void	free_matrix(unsigned short **matrix, t_data *d)
{
	int	i;

	i = 0;
	while (i < d->nbr_lines)
		free(matrix[i++]);
	if (d->len_lines != 0)
		free(matrix);
}

unsigned short	**free_matrix_i(unsigned short **matrix, int i)
{
	while (i >= 0)
		free(matrix[i - 1]);
	free(matrix);
	return (NULL);
}
