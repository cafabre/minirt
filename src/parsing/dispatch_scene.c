/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:50:21 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/15 13:51:38 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool dispatch_amb(char **tab, t_scene *s, char ***coords_r)
{
    *coords_r = check_coords_range(tab[2], 0, 255);
    if (!check_val(tab[1], 0.0f, 1.0f) || !*coords_r)
    {
        free_tab(*coords_r);
        return (false);
    }
    s->amb = create_amb(ft_atof(tab[1]), parse_vector(*coords_r, 3));
    return (true);
}

static bool dispatch_light(char **tab, t_scene *s, char ***coords)
{
    *coords = check_coords(tab[1]);
    if (!*coords || !check_val(tab[2], 0.0f, 1.0f))
    {
        free_tab(*coords);
        return (false);
    }
    s->l = create_light(parse_vector(*coords, 1), ft_atof(tab[2]));
    return (true);
}

static bool dispatch_cam(char **tab, t_scene *s, char ***coords, char ***coords_r)
{
    *coords = check_coords(tab[1]);
    *coords_r = check_coords_range(tab[2], -1, 1);
    if (!*coords || !*coords_r || !check_val(tab[3], 0, 180))
    {
        free_tab(*coords);
        free_tab(*coords_r);
        return (false);
    }
    s->cam = create_cam(parse_vector(*coords, 1), parse_vector(*coords_r, 2), ft_atof(tab[3]));
    return (true);
}

bool dispatch_scene(char **tab, t_scene *s)
{
    char    **coords_r;
    char    **coords;
    bool    res;
    
    coords = NULL;
    coords_r = NULL;
    res = true;
    if (ft_strcmp(tab[0], "A") == 0)
    {
        if (s->amb)
            return (false);
        res = dispatch_amb(tab, s, &coords_r);
    }
    else if (ft_strcmp(tab[0], "L") == 0)
    {
        if (s->l)
            return (false);
        res = dispatch_light(tab, s, &coords);
    }
    else if (ft_strcmp(tab[0], "C") == 0)
    {
        if (s->cam)
            return (false);
        res = dispatch_cam(tab, s, &coords, &coords_r);
    }
    else
        res = false;
    free_tab(coords);
    free_tab(coords_r);
    return (res);
}
