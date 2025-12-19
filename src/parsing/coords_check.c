/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 17:58:41 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/19 17:59:28 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static char	**split_coords(char *s, t_data *data)
{
	char	**coords;

	if (ft_strcnt(s, ',') != 2)
	{
		data->detail = DETAIL_BAD_FORMAT;
		return (NULL);
	}
	coords = ft_split(s, ',');
	if (!coords || ft_tablen(coords) != 3)
	{
		free_tab(coords);
		data->detail = DETAIL_BAD_FORMAT;
		return (NULL);
	}
	return (coords);
}

static bool	coords_are_num(char **coords, t_data *data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!ft_isnumber(coords[i]))
		{
			data->detail = DETAIL_NOT_A_NUMBER;
			return (false);
		}
		i++;
	}
	return (true);
}

char	**check_coords(char *s, t_data *data)
{
	char	**coords;

	coords = split_coords(s, data);
	if (!coords)
		return (NULL);
	if (!coords_are_num(coords, data))
	{
		free_tab(coords);
		return (NULL);
	}
	return (coords);
}

char **check_coords_range(char *s, float r_min, float r_max, t_data *data)
{
    int     i;
    char **coords;
    
    coords = check_coords(s, data);
    if (!coords)
        return (NULL);
    i = 0;
    while (i <= 2)
    {
        if (!check_val(coords[i], r_min, r_max, data))
        {
            free_tab(coords);
            return (NULL);
        }
        i++;
    }
    return (coords);
}
