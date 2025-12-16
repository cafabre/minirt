/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:37:18 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/16 14:20:27 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <errno.h>

static bool  is_in_range(float f, float r_min, float r_max, t_data *data)
{
    if (f < r_min || r_max < f)
    {
        data->detail = DETAIL_OUT_OF_RANGE;
        return (false);
    }   
    return (true);
}

bool check_val(char *s, float r_min, float r_max, t_data *data)
{
    float   f;
    
    if (!ft_isnumber(s))
    {
        data->detail = DETAIL_NOT_A_NUMBER;
        return (false);
    }
    f = ft_atof(s);
    if (!is_in_range(f, r_min, r_max, data))
        return (false);
    return (true);
}

char **check_coords(char *s, t_data *data)
{
    char **coords;
    int  i;
    
    if (ft_strcnt(s, ',') != 2)
    {
        data->detail = DETAIL_BAD_FORMAT;
        return (NULL);
    }
    coords = ft_split(s, ',');
    if (ft_tablen(coords) != 3)
    {
        free_tab(coords);
        data->detail = DETAIL_BAD_FORMAT;
        return (NULL);
    }
    i = 0;
    while (i <= 2)
    {
        if (!ft_isnumber(coords[i]))
        {
            free_tab(coords);
            data->detail = DETAIL_NOT_A_NUMBER;
            return (NULL);
        }
        i++;
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
