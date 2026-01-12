/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:43:50 by cafabre           #+#    #+#             */
/*   Updated: 2026/01/12 15:36:50 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	dispatch_util(char **tab, t_scene *s,
	t_data *data, int nb_args, int type)
{
	if (ft_tablen(tab) == nb_args)
	{
		if (type == 1)
		{
			if (!dispatch_scene(tab, s, data))
				return (false);
		}
		else
		{
			if (!dispatch_obj(tab, s, data))
				return (false);
		}
	}
	else
	{
		data->error = ERR_INVALID_ARGS_LINE;
		return (false);
	}
	return (true);
}

bool	dispatch_ids(char **tab, t_scene *s, t_data *data)
{
	bool	valid_line;

	if (ft_strcmp(tab[0], "A") == 0)
		valid_line = dispatch_util(tab, s, data, 3, 1);
	else if (ft_strcmp(tab[0], "C") == 0 || ft_strcmp(tab[0], "L") == 0)
		valid_line = dispatch_util(tab, s, data, 4, 1);
	else if (ft_strcmp(tab[0], "sp") == 0 || ft_strcmp(tab[0], "pl") == 0)
		valid_line = dispatch_util(tab, s, data, 4, 2);
	else if (ft_strcmp(tab[0], "cy") == 0)
		valid_line = dispatch_util(tab, s, data, 6, 2);
	else
		return (ret_error(data, ERR_INVALID_ID));
	return (valid_line);
}
