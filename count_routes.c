/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_routes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 10:44:51 by emaune            #+#    #+#             */
/*   Updated: 2018/08/28 14:57:11 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void				get_path(t_count_routes *cr, t_rooms *from, t_route *r)
{
	cr->route_tail->next = (t_route*)malloc(sizeof(t_route));
	cr->route_tail->next->prev = cr->route_tail;
	cr->route_tail = cr->route_tail->next;
	cr->route_tail->room_ptr = cr->to;
	cr->route_tail->parent = r;
	cr->route_tail->next = NULL;
	cr->prev = from;
}

static void				traverse_graph(t_rooms *from, t_count_routes *cr,
		int i, t_main *var)
{
	t_route				*temp;
	t_route				*t;

	i = 0;
	temp = cr->route_tail;
	while (i < from->total_links)
	{
		cr->to = from->linked_rooms[i];
		if (cr->to == cr->prev)
			cr->to = from->linked_rooms[++i];
		if (cr->to)
		{
			if (!cr->route)
			{
				malloc_route_head(cr, from);
				temp = cr->route_tail;
			}
			t = cr->route_tail;
			get_path(cr, from, temp);
			if (!cr->to->was_visited || cr->to == cr->end)
				count_paths_to_end(cr->to, cr, var);
		}
		i++;
	}
}

int						count_paths_to_end(t_rooms *from, t_count_routes *cr,
		t_main *var)
{
	int					routes;
	int					i;
	t_route				*temp;

	i = 0;
	routes = 0;
	from->was_visited = 1;
	if (from == cr->end)
	{
		*cr->ans += 1;
		return (routes);
	}
	if (from->total_links)
		traverse_graph(from, cr, i, var);
	return (routes);
}

static void				search_routes(t_rooms *rooms, t_main *var,
		t_count_routes *cr)
{
	count_paths_to_end(cr->from, cr, var);
	if (!*cr->ans)
	{
		ft_putendl("\x1b[31mError: There are no routes to end\x1b[0m");
		free_data(var->data);
		free_rooms(var->rooms);
		free_links(var->links);
		if (cr->route)
			free_route(cr->route);
		free(cr->ans);
		exit(EXIT_FAILURE);
	}
	var->route = cr->route;
	var->total_routes = *cr->ans;
	free(cr->ans);
}

int						count_routes(t_rooms *rooms, t_main *var)
{
	t_count_routes		cr;

	cr.start = get_start_room(rooms);
	cr.end = get_end_room(rooms);
	cr.from = cr.start;
	cr.s = cr.start;
	cr.prev = NULL;
	cr.route_tail = NULL;
	cr.ans = (int*)malloc(sizeof(int));
	*cr.ans = 0;
	search_routes(rooms, var, &cr);
	return (var->total_routes);
}
