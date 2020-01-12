/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrino_world.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etexier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 13:03:38 by etexier           #+#    #+#             */
/*   Updated: 2019/12/02 13:58:29 by etexier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int				get_xspan(unsigned char val, int pos)
{
	if (pos == 3)
		return (1);
	if (pos == 2)
	{
		if (val == 3)
			return (2);
		return (1);
	}
	if (pos == 1)
	{
		if ((val & 0x1) == 1)
			return (3);
		if ((val & 0x2) == 2)
			return (2);
		return (1);
	}
	if ((val & 0x1) == 1)
		return (4);
	if ((val & 0x2) == 2)
		return (3);
	if ((val & 0x4) == 4)
		return (2);
	return (1);
}

void			span_x(t_tetrino *t, int line, int *start, int *span)
{
	int				shift[4];
	unsigned char	val;

	shift[0] = 12;
	shift[1] = 8;
	shift[2] = 4;
	shift[3] = 0;
	val = (unsigned char)((t->shape >> shift[line]) & 0xF);
	*start = -1;
	*span = 0;
	if (val > 7)
		*start = 0;
	else if (val > 3)
		*start = 1;
	else if (val > 1)
		*start = 2;
	else if (val == 1)
		*start = 3;
	if (*start != -1)
		*span = get_xspan(val, *start);
}

void			do_span(t_tetrino *t)
{
	int start;
	int span;
	int line;

	line = 0;
	while (line < 4)
	{
		span_x(t, line, &start, &span);
		t->spanx[line].start = start;
		t->spanx[line].span = span;
		line++;
	}
	return ;
}
