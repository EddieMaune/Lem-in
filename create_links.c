/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 11:49:02 by emaune            #+#    #+#             */
/*   Updated: 2018/08/30 14:05:11 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static char			*get_room(char *link, char side, t_main *var)
{
	char			**rooms;
	char			*room;
	int				i;

	i = 0;
	rooms = ft_strsplit(link, '-');
	while (rooms[i])
		i++;
	if (i != 2)
	{
		ft_putendl("\x1b[31mError: Links invalid");
		free_data(var->data);
		free_rooms(var->rooms);
		exit(EXIT_FAILURE);
	}
	if (side == 'L')
		room = ft_strdup(rooms[0]);
	if (side == 'R')
		room = ft_strdup(rooms[1]);
	free_split(rooms);
	rooms = NULL;
	return (room);
}

static void			add_link(t_main *var)
{
	if (!var->links)
	{
		var->links = (t_link*)malloc(sizeof(t_link));
		var->links_tail = var->links;
		var->links->prev = NULL;
		var->links->next = NULL;
		var->links->from = get_room(var->data_tail->line, 'L', var);
		var->links->to = get_room(var->data_tail->line, 'R', var);
	}
	else
	{
		var->links_tail->next = (t_link*)malloc(sizeof(t_link));
		var->links_tail->next->prev = var->links_tail;
		var->links_tail = var->links_tail->next;
		var->links_tail->next = NULL;
		var->links_tail->from = get_room(var->data_tail->line, 'L', var);
		var->links_tail->to = get_room(var->data_tail->line, 'R', var);
	}
}

void				create_links(t_main *var)
{
	var->links = NULL;
	while (var->data_tail)
	{
		if (is_link(var->data_tail->line) && !is_comment(var->data_tail->line))
			add_link(var);
		var->data_tail = var->data_tail->next;
	}
	if (!var->links)
	{
		ft_putendl("\x1b[31mError: No links");
		free_data(var->data);
		free_rooms(var->rooms);
		exit(1);
	}
	var->links_tail = var->links;
}
