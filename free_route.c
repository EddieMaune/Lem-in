/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_route.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 14:28:40 by emaune            #+#    #+#             */
/*   Updated: 2018/08/28 13:40:42 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			free_route(t_route *route)
{
	while (route->next)
	{
		route = route->next;
		free(route->prev);
	}
	ft_strdel(&route->room);
	free(route);
}
