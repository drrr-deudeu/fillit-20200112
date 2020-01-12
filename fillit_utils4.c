/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_utils4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etexier <etexier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 10:01:11 by etexier           #+#    #+#             */
/*   Updated: 2020/01/06 17:41:03 by etexier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "fillit.h"
#include "libft.h"

int				get_csize(const t_grid *grid)
{
	int			count;
	int			res;
	t_tetrino	*data;

	data = grid->tetrino_input;
	count = 0;
	while (data)
	{
		data = data->next;
		count++;
	}
	res = 1;
	while ((res * res) < (count * 4))
		res++;
	return (res);
}

t_grid			*init_grid(t_tetrino *lst)
{
	t_grid	*grid;

	grid = (t_grid *)malloc(sizeof(t_grid));
	if (grid == NULL)
		return (NULL);
	grid->tetrino_input = lst;
	grid->csize = get_csize(grid);
	grid->csize_moins_un = grid->csize - 1;
	grid->sq_size = grid->csize * grid->csize;
	return (grid);
}

int				display_result(t_grid *grid)
{
	int		row;
	int		col;

	row = 0;
	while (row < grid->csize)
	{
		col = 0;
		while (col < grid->csize)
		{
			ft_putchar(grid->table[row][col]);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
	ft_putchar('\n');
	return (1);
}

void	init_crd4(t_tetrino *t)
{
	int start;
	int count;
	int end;
	int point;

	count = 0;
	point = 0;
	while (count < 4 && t->spanx[count].start != -1)
	{
		start = t->spanx[count].start;
		end = start + t->spanx[count].span;
		while (start < end)
		{
			t->crd4[point][0] = count;
			t->crd4[point][1] = start;
			point++;
			start++;
		}
		count++;
	}
}

void	print_crd4(t_tetrino *l)
{
	int count;

	ft_putstr("crd4:\n");
	count = 0;
	while (count < 4)
	{
		ft_putnbr(count);
		ft_putstr(":");
		ft_putnbr(l->crd4[count][0]);
		ft_putstr(",");
		ft_putnbr(l->crd4[count][1]);
		ft_putchar('\n');
		count++;
	}
}

