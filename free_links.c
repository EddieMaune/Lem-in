/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 14:10:57 by emaune            #+#    #+#             */
/*   Updated: 2018/08/30 14:04:56 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		free_links(t_link *links)
{
	while (links)
	{
		if (links->from)
			free(links->from);
		if (links->to)
			free(links->to);
		if (links->next)
		{
			links = links->next;
			free(links->prev);
		}
		else
			break ;
	}
	free(links);
}
