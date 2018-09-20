/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 11:27:20 by emaune            #+#    #+#             */
/*   Updated: 2018/08/24 14:02:09 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			free_rooms(t_rooms *rooms)
{
	while (rooms)
	{
		free(rooms->room_name);
		if (rooms->linked_rooms)
			free(rooms->linked_rooms);
		if (rooms->next)
		{
			rooms = rooms->next;
			free(rooms->prev);
		}
		else
			break ;
	}
	free(rooms);
}
