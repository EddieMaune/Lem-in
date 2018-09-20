/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 13:21:44 by emaune            #+#    #+#             */
/*   Updated: 2018/08/16 13:28:11 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		free_data(t_data *data)
{
	t_data	*index;

	index = data;
	while (index->next)
	{
		ft_strdel(&index->line);
		index = index->next;
		free(index->prev);
		index->prev = NULL;
	}
	ft_strdel(&index->line);
	free(index);
	index = NULL;
}
