/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 13:18:11 by emaune            #+#    #+#             */
/*   Updated: 2018/08/30 13:34:44 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		error_check_data(t_data *data)
{
	while (is_comment(data->line))
		data = data->next;
	if (!ft_isnum(data->line))
	{
		ft_putendl("\x1b[31mError: Number of ants unspecified\x1b[0m");
		free_data(data);
		exit(EXIT_FAILURE);
	}
	data = data->next;
	while (data)
	{
		error_check_line(data);
		data = data->next;
	}
}
