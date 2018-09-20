/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_start_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:01:01 by emaune            #+#    #+#             */
/*   Updated: 2018/08/24 13:42:41 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_rooms			*get_start_room(t_rooms *room)
{
	while (room)
	{
		if (room->is_start)
			break ;
		room = room->next;
	}
	return (room);
}

t_rooms			*get_end_room(t_rooms *room)
{
	while (room)
	{
		if (room->is_end)
			break ;
		room = room->next;
	}
	return (room);
}
