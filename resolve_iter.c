/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etexier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 09:58:51 by etexier           #+#    #+#             */
/*   Updated: 2020/01/06 09:58:57 by etexier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

static int		is_candidate_iter(t_grid *grid, int row, int col, t_tetrino *t)
{
	int count;

	count = 0;
	while (count < 4)
	{
		if (grid->table[row + t->crd4[count][0]][col + t->crd4[count][1]] != EMPTY)
			return (0);
		count++;
	}
	return (1);
}

static int		try_insert_tetrino(t_grid *grid, t_tetrino *t)
{
	int row;
	int col;
	int limrow;
	int limcol;

	row = t->coord[ROW];
	col = t->coord[COL];
	limrow = grid->csize - t->box[COL] + 1;
	limcol = grid->csize - t->box[ROW] + 1;
	while (row < limrow)
	{
		while (col < limcol)
		{
			if(is_candidate_iter(grid, row, col, t))
			{
				ins_tx_iter(grid, row, col, t);
				return (1);
			}
			col++;
		}
		col = 0;
		row++;
	}
	return (0);
}

static int		resolve_rec(t_grid *grid, t_tetrino *t)
{
	int		res;

	if (try_insert_tetrino(grid, t) == 0)
		return (0);
	if (t->next == NULL)
		return (1);
	t->next->coord[ROW] = 0;
	t->next->coord[COL] = 0;
	res = resolve_rec(grid, t->next);
	if (res == 0)
	{
		remove_tetrino_iter(grid, t);
		if (update_coord_iter(grid, t) == 0)
			return (0);
		return (resolve_rec(grid, t));
	}
	return (1);
}

static int		resize_iter(t_grid *grid)
{
	t_tetrino	*t;

	if (grid->csize + 1 < GRID_SIZE_MAX)
	{
		grid->csize++;
		grid->csize_moins_un = grid->csize - 1;
		grid->sq_size = grid->csize * grid->csize;
		ft_memset(&grid->table, EMPTY, GRID_SIZE_MAX * GRID_SIZE_MAX);
		t = grid->tetrino_input;
		while (t != NULL)
		{
			t->coord[ROW] = 0;
			t->coord[COL] = 0;
			t = t->next;
		}
		return (1);
	}
	return (0);
}

int				resolve_iter(t_grid *grid)
{
	t_tetrino	*t;

	ft_memset(&grid->table, EMPTY, GRID_SIZE_MAX * GRID_SIZE_MAX);
	t = grid->tetrino_input;
	while (resolve_rec(grid, t) == 0)
	{
		if (resize_iter(grid) == 0)
			return (0);
	}
	return (1);
}
