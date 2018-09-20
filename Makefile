# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emaune <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/16 11:12:24 by emaune            #+#    #+#              #
#    Updated: 2018/08/30 10:54:38 by emaune           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = main.c read_data.c malloc_data.c store_data.c\
	  \
	  error_check_data.c error_check_line.c is_room.c is_comment.c is_link.c\
	  error_check_multiple_start_end.c\
	  \
	  create_rooms.c error_check_rooms.c\
	  \
	 create_links.c error_check_links.c point_rooms_to_linked_rooms.c\
	 link_rooms.c\
	 \
	 get_start_end.c count_routes.c reset_visited_flag.c set_path.c\
	 march_ants.c is_parent.c\
	  free_data.c free_split.c free_rooms.c free_links.c free_route.c\
	  free_path.c 

CC = gcc

LINKER = -Llibft -lft

CFLAGS = -g -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@$(MAKE) -C libft
	@$(CC) $(LINKER) -g  $(SRC) -o $(NAME)

fclean:
	@rm -f $(NAME)

re: fclean
	@make
