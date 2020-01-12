/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_iter2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etexier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 09:59:07 by etexier           #+#    #+#             */
/*   Updated: 2020/01/06 09:59:19 by etexier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		update_coord_iter(t_grid *grid, t_tetrino *t)
{
	if ((t->coord[COL] = (t->coord[COL]+1) % grid->csize))
		return (1);
	t->coord[ROW] = (t->coord[ROW] + 1) % grid->csize;
	return (t->coord[ROW]);
}

int		ins_tx_iter(t_grid *grid, int row, int col, t_tetrino *t)
{
	int		count;

	count = 0;
	t->coord[COL] = col;
	t->coord[ROW] = row;
	while (count < 4)
	{
		grid->table[row + t->crd4[count][0]][col + t->crd4[count][1]] = t->marker;
		count++;
	}
	return (1);
}

int		remove_tetrino_iter(t_grid *grid, t_tetrino *t)
{
	int		count;
	int		col;
	int		row;

	count = 0;
	col = t->coord[COL];
	row = t->coord[ROW];
	while (count < 4)
	{
		grid->table[row + t->crd4[count][0]][col + t->crd4[count][1]] = EMPTY;
		count++;
	}
	return (1);
}
