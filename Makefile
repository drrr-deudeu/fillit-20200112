# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etexier <etexier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 11:32:12 by etexier           #+#    #+#              #
#    Updated: 2020/01/06 16:54:21 by etexier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -g -g3 -I./libft/includes -I.

LDFLAGS		= -lft -L./libft

AR			= ar rc

RM			= rm -f

OBJS		= *.o

NAME		= fillit

all:		${NAME}

fillit:		fillit.o get_next_line.o fillit_utils1.o fillit_utils2.o	fillit_utils3.o fillit_utils4.o tetrino_lst.o tetrino_bound.o tetrino_print.o tetrino_world.o resolve_iter.o resolve_iter2.o
			$(CC) $(CFLAGS) ${LDFLAGS} -o ${NAME} \
				fillit.o \
				get_next_line.o	\
				fillit_utils1.o	\
				fillit_utils2.o	\
				fillit_utils3.o	\
				fillit_utils4.o	\
				tetrino_lst.o	\
				tetrino_bound.o	\
				tetrino_print.o	\
				tetrino_world.o	\
				resolve_iter.o \
				resolve_iter2.o ${LDFLAGS} 


fillit.o:	fillit.c fillit.h get_next_line.h
			$(CC) $(CFLAGS) -c fillit.c -o fillit.o 	

get_next_line.o:	get_next_line.c get_next_line.h
			$(CC) $(CFLAGS) -c get_next_line.c -o get_next_line.o 	

fillit_utils1.o:	fillit_utils1.c fillit.h
			$(CC) $(CFLAGS) -c fillit_utils1.c -o fillit_utils1.o 	

fillit_utils2.o:	fillit.h fillit_utils2.c
			$(CC) $(CFLAGS) -c fillit_utils2.c -o fillit_utils2.o 	

fillit_utils3.o:	fillit.h fillit_utils3.c
			$(CC) $(CFLAGS) -c fillit_utils3.c -o fillit_utils3.o 	

fillit_utils4.o:	fillit.h fillit_utils4.c
			$(CC) $(CFLAGS) -c fillit_utils4.c -o fillit_utils4.o 	

tetrino_lst.o:	fillit.h tetrino_lst.c
			$(CC) $(CFLAGS) -c tetrino_lst.c -o tetrino_lst.o 	

tetrino_bound.o:	fillit.h tetrino_bound.c
			$(CC) $(CFLAGS) -c tetrino_bound.c -o tetrino_bound.o 	

tetrino_print.o:	fillit.h tetrino_print.c
			$(CC) $(CFLAGS) -c tetrino_print.c -o tetrino_print.o 	

tetrino_world.o:	fillit.h tetrino_world.c
			$(CC) $(CFLAGS) -c tetrino_world.c -o tetrino_world.o 	

gbox.o:	fillit.h gbox.c
			$(CC) $(CFLAGS) -c gbox.c -o gbox.o 	

clean:
			${RM} ${OBJS} 

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean re
