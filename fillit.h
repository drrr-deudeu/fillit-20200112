/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etexier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:55:46 by etexier           #+#    #+#             */
/*   Updated: 2019/12/07 13:25:41 by drouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define SHAPE '#'
# define EMPTY '.'
# define GRID_SIZE_MAX 11
# define SHAPES_MAX 19
# define ROW	0
# define COL	1

typedef unsigned short		t_ushort;
typedef	struct				s_span
{
	int						start;
	int						span;
}							t_span;

typedef	struct				s_tetrino
{
	t_ushort				shape;
	int						base_shape;
	int						box[2];
	t_span					spanx[4];
	int						coord[2];
	char					marker;
	int					crd4[4][2];
	struct s_tetrino		*next;
}							t_tetrino;

typedef struct				s_grid
{
	t_tetrino				*tetrino_input;
	int						sq_size;
	int						csize;
	int						csize_moins_un;
	int						marker;
	char					table[GRID_SIZE_MAX][GRID_SIZE_MAX];
}							t_grid;

# define TOO_MANY_EMPTY "File format error: too many empty lines\n"
# define BAD_TETRINO_DATA "Bad tetrino data. Check valid:\n"
# define USAGE "usage: ./fillit a_file\n"
# define CANNOT_RD_FILE "Cannot read file.\n"
# define FILE_NOT_FORMAT "Wrong Format\n"

int							resize_up(t_grid *grid);

int							is_candidate(t_grid *g, int x, int y, t_tetrino *t);
int							insert_tetrino(t_grid *g,
											int x, int y, t_tetrino *t);

void						delete_list_tetrino(t_tetrino **lst);
t_tetrino					*alloc_s_tetrino(t_ushort s, int type);
t_tetrino					*make_s_tetrino(unsigned short int t);
unsigned short int			get_single_row_val(char *a_row);
unsigned short int			add_tetrino_line(unsigned short val, char *a_row);

void						set_coord(t_tetrino *t, int row, int col);
void						init_coord(t_tetrino *t);
unsigned short int			move_to_top(unsigned short int tetrino);
unsigned short int			make_tetrino(char *a, char *b, char *c, char *d);

unsigned short int			shift_left(unsigned short int t);
t_tetrino					*build_all_default(void);
int							is_valid_shape(unsigned short int t);
int							is_on(unsigned short int tetrino, int index);

int							max_x(unsigned short int t);
int							min_y(unsigned short int t);
void						bound_x(unsigned short int i, int *x);
void						bound_y(unsigned short int t, int *y);
void						bound(unsigned short int i, int *x, int *y);

t_tetrino					*add_to_list(t_tetrino **first, t_tetrino *new);

void						print_line(unsigned char v);
void						print_tetrino(t_tetrino *l, int style);
void						print_box(t_tetrino *l, unsigned short int v);
void						print_span(t_tetrino *l);
void						print_list(t_tetrino *l, int style);

int							display_result(t_grid *grid);
int							get_csize(const t_grid *grid);
t_grid						*init_grid(t_tetrino *lst);

void						do_span(t_tetrino *t);
void						span_x(t_tetrino *t, int line, int *st, int *span);
int							get_xspan(unsigned char val, int pos);
void						span_y(t_tetrino *t, int col, int *st, int *span);
int							get_yspan(unsigned int u, int col, int *s, int pos);

int							resolve_backtrack(t_grid *grid);
int							clean_tetrino(t_grid *grid, t_tetrino *t);

int							resolve_iter(t_grid *grid);
int							ins_tx_iter(t_grid *g, int r, int c, t_tetrino *t);
int							update_coord_iter(t_grid *grid, t_tetrino *t);
int							remove_tetrino_iter(t_grid *grid, t_tetrino *t);
void						init_crd4(t_tetrino *t);
void						print_crd4(t_tetrino *t);

#endif
