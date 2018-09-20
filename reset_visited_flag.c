/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_visited_flag.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 14:59:28 by emaune            #+#    #+#             */
/*   Updated: 2018/08/22 15:12:13 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			reset_visited_flag(t_rooms *rooms)
{
	while (rooms)
	{
		rooms->was_visited = 0;
		rooms = rooms->next;
	}
}
