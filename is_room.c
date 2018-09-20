/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_room.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 14:00:00 by emaune            #+#    #+#             */
/*   Updated: 2018/08/26 11:33:31 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			is_room(char *line)
{
	char	**room;
	int		i;

	i = 0;
	room = ft_strsplit(line, ' ');
	while (room[i])
		i++;
	if (i != 3)
	{
		free_split(room);
		return (0);
	}
	if (room[0][0] != 'L' && room[0][0] != '#'
			&& ft_isnum(room[1])
			&& ft_isnum(room[2]))
	{
		free_split(room);
		return (1);
	}
	free_split(room);
	return (0);
}
