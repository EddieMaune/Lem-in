/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_links.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 13:59:33 by emaune            #+#    #+#             */
/*   Updated: 2018/08/30 13:59:03 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int			linked_room_exists(t_rooms *r, char *room)
{
	while (r)
	{
		if (ft_strequ(r->room_name, room))
			return (1);
		r = r->next;
	}
	return (0);
}

static int			links_have_dup(t_link *links)
{
	t_link			*temp;

	while (links)
	{
		temp = links->next;
		while (temp)
		{
			if (ft_strequ(links->from, temp->from)
					&& ft_strequ(links->to, temp->to))
				return (1);
			if (ft_strequ(links->from, temp->to)
					&& ft_strequ(links->to, temp->from))
				return (1);
			temp = temp->next;
		}
		links = links->next;
	}
	return (0);
}

void				error_check_links(t_main *var)
{
	if (links_have_dup(var->links_tail))
	{
		ft_putendl("\x1b[31mError: Duplicate link\x1b[0m");
		free_data(var->data);
		free_rooms(var->rooms);
		free_links(var->links);
		exit(EXIT_FAILURE);
	}
	while (var->links_tail)
	{
		if (!linked_room_exists(var->rooms, var->links_tail->from)
				|| !linked_room_exists(var->rooms, var->links_tail->to))
		{
			ft_putstr("\x1b[31mError: Linked room does not exist\n\x1b[0m");
			ft_putstr(var->links_tail->from);
			ft_putchar('-');
			ft_putstr(var->links_tail->to);
			free_data(var->data);
			free_rooms(var->rooms);
			free_links(var->links);
			exit(EXIT_FAILURE);
		}
		var->links_tail = var->links_tail->next;
	}
}
