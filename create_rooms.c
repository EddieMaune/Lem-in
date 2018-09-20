/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 12:10:17 by emaune            #+#    #+#             */
/*   Updated: 2018/09/02 11:41:17 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			malloc_room(char **room, int is_start,
		int is_end, t_main *var)
{
	var->rooms = (t_rooms*)malloc(sizeof(t_rooms));
	var->rooms_tail = var->rooms;
	if (is_start)
	{
		var->rooms->total_ants = var->total_ants;
		var->rooms->is_start = 1;
	}
	if (is_end)
		var->rooms->is_end = 1;
	var->rooms->room_name = ft_strdup(room[0]);
	var->rooms->v.x = ft_atoi(room[1]);
	var->rooms->v.y = ft_atoi(room[2]);
	var->rooms->prev = NULL;
	var->rooms->next = NULL;
}

static void			add_room(char *line, int is_start, int is_end, t_main *var)
{
	char			**room;

	room = ft_strsplit(line, ' ');
	if (!var->rooms)
		malloc_room(room, is_start, is_end, var);
	else
	{
		var->rooms_tail->next = (t_rooms*)malloc(sizeof(t_rooms));
		var->rooms_tail->next->prev = var->rooms_tail;
		var->rooms_tail = var->rooms_tail->next;
		if (is_start)
		{
			var->rooms_tail->total_ants = var->total_ants;
			var->rooms_tail->is_start = 1;
		}
		if (is_end)
			var->rooms_tail->is_end = 1;
		var->rooms_tail->room_name = ft_strdup(room[0]);
		var->rooms_tail->v.x = ft_atoi(room[1]);
		var->rooms_tail->v.y = ft_atoi(room[2]);
		var->rooms_tail->next = NULL;
		var->rooms_tail->linked_rooms = NULL;
	}
	free_split(room);
}

static void			init_room(t_main *var)
{
	if (ft_strstr(var->data_tail->line, "##start"))
	{
		var->data_tail = var->data_tail->next;
		while (is_comment(var->data_tail->line))
			var->data_tail = var->data_tail->next;
		add_room(var->data_tail->line, 1, 0, var);
	}
	else if (ft_strstr(var->data_tail->line, "##end"))
	{
		var->data_tail = var->data_tail->next;
		while (is_comment(var->data_tail->line))
			var->data_tail = var->data_tail->next;
		add_room(var->data_tail->line, 0, 1, var);
	}
	else if (is_room(var->data_tail->line))
		add_room(var->data_tail->line, 0, 0, var);
}

void				create_rooms(t_main *var)
{
	while (var->data_tail)
	{
		init_room(var);
		var->data_tail = var->data_tail->next;
	}
	if (!var->rooms)
	{
		ft_putendl("\x1b[31mError: File descriptor has no rooms");
		free_data(var->data);
		exit(EXIT_FAILURE);
	}
	var->rooms_tail = var->rooms;
	var->data_tail = var->data;
}
