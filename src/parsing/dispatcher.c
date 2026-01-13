/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:43:50 by cafabre           #+#    #+#             */
/*   Updated: 2026/01/13 13:10:26 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	dispatch_util(char **tab, t_scene *s,
	t_data *data, int *args)
{
	if (ft_tablen(tab) == args[0])
	{
		if (args[1] == 1)
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
		return (ret_error(data, ERR_INVALID_ARGS_LINE));
	return (true);
}

bool	dispatch_ids(char **tab, t_scene *s, t_data *data)
{
	bool	valid_line;

	if (ft_strcmp(tab[0], "A") == 0)
		valid_line = dispatch_util(tab, s, data, (int []){3, 1});
	else if (ft_strcmp(tab[0], "C") == 0 || ft_strcmp(tab[0], "L") == 0)
		valid_line = dispatch_util(tab, s, data, (int []){4, 1});
	else if (ft_strcmp(tab[0], "sp") == 0 || ft_strcmp(tab[0], "pl") == 0)
		valid_line = dispatch_util(tab, s, data, (int []){4, 2});
	else if (ft_strcmp(tab[0], "cy") == 0)
		valid_line = dispatch_util(tab, s, data, (int []){6, 2});
	else
		return (ret_error(data, ERR_INVALID_ID));
	return (valid_line);
}
