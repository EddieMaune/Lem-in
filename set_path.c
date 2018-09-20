/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 14:06:14 by emaune            #+#    #+#             */
/*   Updated: 2018/08/28 12:33:45 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_path	*add_room(t_route *t, t_path *p, t_main *var)
{
	if (!p)
	{
		p = (t_path*)malloc(sizeof(t_path));
		p->room = t->room_ptr;
		p->next = NULL;
		p->prev = NULL;
		var->path = p;
	}
	else
	{
		p->next = (t_path*)malloc(sizeof(t_path));
		p->next->prev = p;
		p = p->next;
		p->room = t->room_ptr;
		p->next = NULL;
	}
	return (p);
}

void			set_path(t_route *route, t_main *var)
{
	t_route		*t;
	t_path		*p;
	int			flag;

	flag = 0;
	p = NULL;
	while (route)
	{
		if (route->room_ptr->is_end)
		{
			t = route;
			while (t)
			{
				p = add_room(t, p, var);
				t = t->parent;
			}
		}
		route = route->next;
	}
}

void			malloc_route_head(t_count_routes *cr, t_rooms *from)
{
	cr->route_tail = (t_route*)malloc(sizeof(t_route));
	cr->route_tail->room_ptr = from;
	cr->route = cr->route_tail;
	cr->route->parent = NULL;
	cr->route->prev = NULL;
	cr->route->next = NULL;
}
