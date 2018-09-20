/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_rooms.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 11:23:43 by emaune            #+#    #+#             */
/*   Updated: 2018/08/28 12:51:56 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	check_for_same_coo(t_main *var)
{
	t_rooms	*a;
	t_rooms	*b;

	a = var->rooms;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (a->v.x == b->v.x && a->v.y == b->v.y)
			{
				ft_putendl("\x1b[31mError: Room has same coordinates\x1b[0m");
				free_data(var->data);
				free_rooms(var->rooms);
				exit(EXIT_FAILURE);
			}
			b = b->next;
		}
		a = a->next;
	}
}

static void	check_for_dup_room(t_main *var)
{
	t_rooms	*a;
	t_rooms	*b;

	a = var->rooms;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (ft_strequ(a->room_name, b->room_name))
			{
				ft_putendl("\x1b[31mError: Duplicate room.\x1b[0m");
				free_data(var->data);
				free_rooms(var->rooms);
				exit(EXIT_FAILURE);
			}
			b = b->next;
		}
		a = a->next;
	}
}

int			error_check_rooms(t_main *var)
{
	int		start;
	int		end;

	start = 0;
	end = 0;
	var->rooms_tail = var->rooms;
	check_for_dup_room(var);
	check_for_same_coo(var);
	while (var->rooms_tail)
	{
		if (var->rooms_tail->is_start)
			start = 1;
		if (var->rooms_tail->is_end)
			end = 1;
		var->rooms_tail = var->rooms_tail->next;
	}
	if (start && end)
		return (1);
	ft_putstr("\x1b[31mError: start/end room is missing\x1b[0m");
	free_data(var->data);
	free_rooms(var->rooms);
	exit(EXIT_FAILURE);
}
