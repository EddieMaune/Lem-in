/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:22:39 by emaune            #+#    #+#             */
/*   Updated: 2018/08/28 12:27:09 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft/libft.h"

typedef struct		s_data
{
	char			*line;
	int				line_number;
	struct s_data	*next;
	struct s_data	*prev;
}					t_data;

typedef struct		s_vector
{
	int				x;
	int				y;
}					t_vector;

typedef struct		s_rooms
{
	char			*room_name;
	int				i;
	int				was_visited;
	int				is_start;
	int				is_end;
	int				total_links;
	int				total_ants;
	char			*ant_name;
	t_vector		v;
	struct s_rooms	**linked_rooms;
	struct s_rooms	*next;
	struct s_rooms	*prev;
}					t_rooms;

typedef struct		s_link
{
	char			*from;
	char			*to;
	struct s_link	*next;
	struct s_link	*prev;
}					t_link;

typedef struct		s_route
{
	char			*room;
	t_rooms			*room_ptr;
	struct s_route	*parent;
	struct s_route	*child;
	struct s_route	*next;
	struct s_route	*prev;
}					t_route;

typedef struct		s_path
{
	t_rooms			*room;
	int				was_visited;
	struct s_path	*next;
	struct s_path	*prev;
	struct s_path	*next_head;
}					t_path;

typedef struct		s_main
{
	int				total_ants;
	int				total_routes;
	char			*end_room;
	t_data			*data;
	t_data			*data_tail;
	t_rooms			*rooms;
	t_rooms			*rooms_tail;
	t_rooms			*start;
	t_rooms			*end;
	t_link			*links;
	t_link			*links_tail;
	t_link			*links_temp;
	t_route			*route;
	t_route			*route_tail;
	t_route			*route_temp;
	t_path			*path;
	t_path			*p;
}					t_main;

typedef struct		s_count_routes
{
	t_rooms			*start;
	t_rooms			*end;
	t_rooms			*from;
	t_rooms			*to;
	t_rooms			*prev;
	t_rooms			*s;
	int				*ans;
	t_route			*route_tail;
	t_route			*route;
}					t_count_routes;

/*
** Read and store data.
*/
void				read_data(t_main *var);
void				malloc_data(t_main *var);
void				store_data(t_main *var);
/*
** Error check data
*/
void				error_check_data(t_data *data);
void				error_check_line(t_data *data);
void				error_check_multiple_start_end(t_main *var);
int					is_room(char *line);
int					is_comment(char *line);
int					is_link(char *line);
/*
** Create Rooms
*/
void				create_rooms(t_main *var);
/*
** Error Check Rooms
*/
int					error_check_rooms(t_main *var);
/*
** Create Links
*/
void				create_links(t_main *var);
void				link_src_to_dest(t_main *var);
void				link_dest_to_src(t_main *var);
void				link_rooms(t_main *var);
/*
** Error Check Links
*/
void				error_check_links(t_main *var);
void				error_no_path(t_main *var);
/*
** Count Routes
*/
t_rooms				*get_start_room(t_rooms *room);
t_rooms				*get_end_room(t_rooms *room);
int					count_routes(t_rooms *room, t_main *var);
int					count_paths_to_end(t_rooms *from, t_count_routes *cr,
		t_main *var);
void				reset_visited_flag(t_rooms *rooms);
int					is_parent(t_route *r, t_rooms *to);
void				set_path(t_route *route, t_main *var);
void				malloc_route_head(t_count_routes *cr, t_rooms *from);
void				march_ants(t_main *var);
/*
** Free Memory
*/
void				free_data(t_data *data);
void				free_split(char **split);
void				free_rooms(t_rooms *rooms);
void				free_links(t_link *links);
void				free_route(t_route *route);
void				free_path(t_path *path);
#endif
