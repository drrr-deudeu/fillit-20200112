/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etexier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:24:46 by etexier           #+#    #+#             */
/*   Updated: 2019/12/07 13:27:20 by drouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

void		delete_list_tetrino(t_tetrino **lst)
{
	t_tetrino	*tmp;
	t_tetrino	*next;

	tmp = *lst;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*lst = NULL;
}

t_tetrino	*alloc_s_tetrino(t_ushort shape, int type)
{
	t_tetrino	*ptr;

	ptr = (t_tetrino *)malloc(sizeof(t_tetrino));
	if (ptr == NULL)
		return (NULL);
	ptr->shape = shape;
	ptr->base_shape = type;
	ptr->next = NULL;
	bound(shape, ptr->box, ptr->box + 1);
	do_span(ptr);
	init_crd4(ptr);
	init_coord(ptr);
	return (ptr);
}

t_tetrino	*make_s_tetrino(unsigned short int t)
{
	int index;
	int count;

	index = 0;
	count = 0;
	while (count < 16)
	{
		if (is_on(t, count) == 1)
		{
			if (index >= 4)
				return (0);
			index++;
		}
		count++;
	}
	if (index != 4)
		return (NULL);
	count = is_valid_shape(t);
	if (count == -1)
		return (NULL);
	return (alloc_s_tetrino(t, count));
}

t_ushort	get_single_row_val(char *a_row)
{
	int			count;
	short int	res;

	res = 0;
	count = 0;
	while (count < 4)
	{
		if (a_row[count] == SHAPE)
			res = (res << 1) + 1;
		else
			res = (res << 1);
		count++;
	}
	return (res);
}

t_ushort	add_tetrino_line(unsigned short val, char *a_row)
{
	return ((val << 4) + get_single_row_val(a_row));
}
