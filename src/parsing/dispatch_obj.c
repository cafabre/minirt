/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:52:06 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/12 16:57:40 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool dispatch_sp(char **tab, t_scene *s, char **coords, char **coords_r)
{
    coords = check_coords(tab[1]);
    coords_r = check_coords_range(tab[3], 0, 255);
    if (!coords || !ft_isnumber(tab[2]) || ft_atof(tab[2]) < 0 || !coords_r)
    {
        free_tab(coords);
        free_tab(coords_r);
        return (false);
    }
    s->sp = create_sp(parse_vector(coords, 1), ft_atof(tab[2]), parse_vector(coords_r, 3));
    return (true);
}

static bool dispatch_pl(char **tab, t_scene *s, char **coords, char **coords_r, char **coords_r2)
{
    coords = check_coords(tab[1]);
    coords_r = check_coords_range(tab[2], -1, 1);
    coords_r2 = check_coords_range(tab[3], 0, 255);
    if (!coords || !coords_r || !coords_r2)
        return (false);
    s->pl = create_pl(parse_vector(coords, 1), parse_vector(coords_r, 2),
        parse_vector(coords_r2, 3));
    return (true);
}

static bool dispatch_cy(char **tab, t_scene *s, char **coords, char **coords_r, char **coords_r2)
{
    coords = check_coords(tab[1]);
    coords_r = check_coords_range(tab[2], -1, 1);
    coords_r2 = check_coords_range(tab[5], 0, 255);
    if (!coords || !coords_r || !ft_isnumber(tab[3]) || ft_atof(tab[3]) < 0
        || !ft_isnumber(tab[4]) || ft_atof(tab[4]) < 0 || !coords_r2)
        return (false);
    s->cy = create_cy(parse_vector(coords, 1), parse_vector(coords_r, 2), ft_atof(3),
                ft_atof(tab[4]), parse_vector(coords_r2, 3));
    return (true);
}

bool dispatch_obj(char **tab, t_scene *s)
{
    char    **coords;
    char    **coords_r;
    char    **coords_r2;
    
    if (ft_strcmp(tab[0], "sp") == 0)
    {
        if (!dispatch_sp(tab, s, coords, coords_r))
            return (false);
    }
    else if (ft_strcmp(tab[0], "pl") == 0)
    {
        if (!dispatch_pl(tab, s, coords, coords_r, coords_r2))
            return (false);
    }
    else if (ft_strcmp(tab[0], "cy") == 0)
    {
        if (!dispatch_cy(tab, s, coords, coords_r, coords_r2))
            return (false);
    }
    else
        return (false);
    return (true);
}
