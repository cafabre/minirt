/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:37:18 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/15 14:13:27 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <errno.h>

static bool  is_in_range(float f, float r_min, float r_max)
{
    if (f < r_min || r_max < f)
        return (false);
    return (true);
}

bool check_val(char *s, float r_min, float r_max)
{
    float   f;
    
    if (!ft_isnumber(s))
        return (false);
    f = ft_atof(s);
    if (!is_in_range(f, r_min, r_max))
        return (false);
    return (true);
}

char **check_coords(char *s)
{
    char **coords;
    int  i;
    
    if (ft_strcnt(s, ',') != 2)
        return (NULL);
    coords = ft_split(s, ',');
    if (ft_tablen(coords) != 3)
    {
        free_tab(coords);
        return (NULL);
    }
    i = 0;
    while (i <= 2)
    {
        if (!ft_isnumber(coords[i]))
        {
            free_tab(coords);
            return (NULL);
        }
        i++;
    }
    return (coords);
}

char **check_coords_range(char *s, float r_min, float r_max)
{
    int     i;
    char **coords;
    
    coords = check_coords(s);
    if (!coords)
        return (NULL);
    i = 0;
    while (i <= 2)
    {
        if (!check_val(coords[i], r_min, r_max))
        {
            free_tab(coords);
            return (NULL);
        }
        i++;
    }
    return (coords);
}
