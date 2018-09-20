/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_rooms_to_linked_rooms.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 12:31:15 by emaune            #+#    #+#             */
/*   Updated: 2018/08/20 14:35:26 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		point_src_to_dest(t_main *var, t_rooms *room)
{
	if (var->rooms_tail->total_links)
	{
		while (room)
		{
			if (ft_strequ(room->room_name, var->links_tail->to))
			{
				var->rooms_tail->linked_rooms[var->rooms_tail->i] = room;
				var->rooms_tail->i++;
				break ;
			}
			room = room->next;
		}
	}
}

static void		point_dest_to_src(t_main *var, t_rooms *room)
{
	if (var->rooms_tail->total_links)
	{
		while (room)
		{
			if (ft_strequ(room->room_name, var->links_tail->from))
			{
				var->rooms_tail->linked_rooms[var->rooms_tail->i] = room;
				var->rooms_tail->i++;
				break ;
			}
			room = room->next;
		}
	}
}

void			link_src_to_dest(t_main *var)
{
	var->rooms_tail = var->rooms;
	while (var->rooms_tail)
	{
		if (ft_strequ(var->rooms_tail->room_name, var->links_tail->from))
			point_src_to_dest(var, var->rooms);
		var->rooms_tail = var->rooms_tail->next;
	}
}

void			link_dest_to_src(t_main *var)
{
	var->rooms_tail = var->rooms;
	while (var->rooms_tail)
	{
		if (ft_strequ(var->rooms_tail->room_name, var->links_tail->to))
			point_dest_to_src(var, var->rooms);
		var->rooms_tail = var->rooms_tail->next;
	}
}
