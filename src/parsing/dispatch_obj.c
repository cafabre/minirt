/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:52:06 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/15 16:52:30 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool add_obj_to_scene(t_scene *s, t_obj *o)
{
    t_obj   *tmp;

    o->next = NULL;
    if (!s->objs)
        s->objs = o;
    else
    {
        tmp = s->objs;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = o;
    }
    if (o->type == SPHERE)
        s->sp = o;
    else if (o->type == PLANE)
        s->pl = o;
    else
        s->cy = o;
    return (true);
}

static bool dispatch_sp(char **tab, t_scene *s, char ***coords, char ***coords_r)
{
    t_obj   *new_sp;
    
    *coords = check_coords(tab[1]);
    *coords_r = check_coords_range(tab[3], 0, 255);
    if (!*coords || !ft_isnumber(tab[2]) || ft_atof(tab[2]) < 0 || !*coords_r)
    {
        free_tab(*coords);
        free_tab(*coords_r);
        return (false);
    }
    new_sp = create_sp(parse_vector(*coords, 1), ft_atof(tab[2]), parse_vector(*coords_r, 3));
    if(!new_sp)
        return (false);
    if (!add_obj_to_scene(s, new_sp))
    {
        free(new_sp);
        return (false);
    }
    return (true);
}

static bool dispatch_pl(char **tab, t_scene *s, char ***coords, char ***coords_r, char ***coords_r2)
{
    t_obj   *new_pl;
    
    *coords = check_coords(tab[1]);
    *coords_r = check_coords_range(tab[2], -1, 1);
    *coords_r2 = check_coords_range(tab[3], 0, 255);
    if (!*coords || !*coords_r || !*coords_r2)
    {
        free_tabs(*coords, *coords_r, *coords_r2);
        return (false);
    }
    new_pl = create_pl(parse_vector(*coords, 1), parse_vector(*coords_r, 2),
        parse_vector(*coords_r2, 3));
    if (!new_pl)
        return (false);
    if (!add_obj_to_scene(s, new_pl))
    {
        free(new_pl);
        return (false);
    }
    return (true);
}

static bool dispatch_cy(char **tab, t_scene *s, char ***coords, char ***coords_r, char ***coords_r2)
{
    t_obj   *new_cy;
    
    *coords = check_coords(tab[1]);
    *coords_r = check_coords_range(tab[2], -1, 1);
    *coords_r2 = check_coords_range(tab[5], 0, 255);
    if (!*coords || !*coords_r || !ft_isnumber(tab[3]) || ft_atof(tab[3]) < 0
        || !ft_isnumber(tab[4]) || ft_atof(tab[4]) < 0 || !*coords_r2)
    {
        free_tabs(*coords, *coords_r, *coords_r2);
        return (false);
    }
    new_cy = create_cy(parse_vector(*coords, 1), parse_vector(*coords_r, 2), ft_atof(tab[3]),
                ft_atof(tab[4]), parse_vector(*coords_r2, 3));
    if (!new_cy)
        reutrn (false);
    if (!add_obj_to_scene(s, new_cy))
    {
        free(new_cy);
        return (false);
    }
    return (true);
}

bool dispatch_obj(char **tab, t_scene *s)
{
    char    **coords;
    char    **coords_r;
    char    **coords_r2;
    bool    res;
    
    coords = NULL;
    coords_r = NULL;
    coords_r2 = NULL;
    res = true;
    if (ft_strcmp(tab[0], "sp") == 0)
        res = dispatch_sp(tab, s, &coords, &coords_r);
    else if (ft_strcmp(tab[0], "pl") == 0)
        res = dispatch_pl(tab, s, &coords, &coords_r, &coords_r2);
    else if (ft_strcmp(tab[0], "cy") == 0)
        res = dispatch_cy(tab, s, &coords, &coords_r, &coords_r2);
    else
        res = false;
    free_tabs(coords, coords_r, coords_r2);
    return (res);
}
