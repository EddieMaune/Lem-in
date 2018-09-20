/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:35:55 by emaune            #+#    #+#             */
/*   Updated: 2018/08/27 13:47:17 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			malloc_linked_rooms(t_rooms *rooms)
{
	while (rooms)
	{
		if (rooms->total_links)
			rooms->linked_rooms = (t_rooms**)malloc(sizeof(t_rooms*)
					* rooms->total_links + 1);
		rooms = rooms->next;
	}
}

static void			update_total_links(t_rooms *rooms, t_link *links)
{
	t_link			*head;

	head = links;
	while (rooms)
	{
		links = head;
		rooms->total_links = 0;
		while (links)
		{
			if (ft_strequ(links->from, rooms->room_name))
				rooms->total_links++;
			links = links->next;
		}
		links = head;
		while (links)
		{
			if (ft_strequ(links->to, rooms->room_name))
				rooms->total_links++;
			links = links->next;
		}
		rooms->i = 0;
		rooms->linked_rooms = NULL;
		rooms = rooms->next;
	}
}

void				link_rooms(t_main *var)
{
	int				count_links;
	t_rooms			*temp;

	update_total_links(var->rooms, var->links);
	malloc_linked_rooms(var->rooms);
	var->links_tail = var->links;
	while (var->links_tail)
	{
		link_src_to_dest(var);
		link_dest_to_src(var);
		temp = var->rooms;
		while (temp)
		{
			if (temp->linked_rooms)
				temp->linked_rooms[temp->total_links] = NULL;
			temp = temp->next;
		}
		var->links_tail = var->links_tail->next;
	}
}
