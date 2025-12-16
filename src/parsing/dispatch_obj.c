/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:52:06 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/16 16:09:54 by cafabre          ###   ########.fr       */
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

static bool dispatch_sp(char **tab, t_scene *s, t_coords *c_list, t_data *data)
{
    t_obj   *new_sp;
    
    c_list->coords = check_coords(tab[1], data);
    c_list->coords_r = check_coords_range(tab[3], 0, 255, data);
    if (!c_list->coords || !ft_isnumber(tab[2]) || ft_atof(tab[2]) < 0 || !c_list->coords_r)
    {
        free_tabs(c_list->coords, c_list->coords_r, c_list->coords_r2);
        data->error = ERR_INVALID_SPHERE_DATA;
        return (false);
    }
    new_sp = create_sp(parse_vector(c_list->coords, 1, data), ft_atof(tab[2]),
        parse_vector(c_list->coords_r, 3, data));
    if(!new_sp)
    {
        data->error = ERR_MALLOC_SPHERE;
        return (false);
    }
    if (!add_obj_to_scene(s, new_sp))
    {
        free(new_sp);
        data->error = ERR_ADD_SPHERE;
        return (false);
    }
    return (true);
}

static bool dispatch_pl(char **tab, t_scene *s, t_coords *c_list, t_data *data)
{
    t_obj   *new_pl;
    
    c_list->coords = check_coords(tab[1], data);
    c_list->coords_r = check_coords_range(tab[2], -1, 1, data);
    c_list->coords_r2 = check_coords_range(tab[3], 0, 255, data);
    if (!c_list->coords || !c_list->coords_r || !c_list->coords_r2)
    {
        free_tabs(c_list->coords, c_list->coords_r, c_list->coords_r2);
        data->error = ERR_INVALID_PLANE_DATA;
        return (false);
    }
    new_pl = create_pl(parse_vector(c_list->coords, 1, data),
        parse_vector(c_list->coords_r, 2, data), parse_vector(c_list->coords_r2, 3, data));
    if (!new_pl)
    {
        data->error = ERR_MALLOC_PLANE;
        return (false);
    }
    if (!add_obj_to_scene(s, new_pl))
    {
        free(new_pl);
        data->error = ERR_ADD_PLANE;
        return (false);
    }
    return (true);
}

static bool dispatch_cy(char **tab, t_scene *s, t_coords *c_list, t_data *data)
{
    t_obj   *new_cy;
    
    c_list->coords = check_coords(tab[1], data);
    c_list->coords_r = check_coords_range(tab[2], -1, 1, data);
    c_list->coords_r2 = check_coords_range(tab[5], 0, 255, data);
    if (!c_list->coords || !c_list->coords_r || !ft_isnumber(tab[3]) || ft_atof(tab[3]) < 0
        || !ft_isnumber(tab[4]) || ft_atof(tab[4]) < 0 || !c_list->coords_r2)
    {
        free_tabs(c_list->coords, c_list->coords_r, c_list->coords_r2);
        data->error = ERR_INVALID_CYLINDER_DATA;
        return (false);
    }
    //create_cy -> a coder
    new_cy = create_cy(parse_vector(c_list->coords, 1, data), parse_vector(c_list->coords_r, 2, data),
        ft_atof(tab[3]), ft_atof(tab[4]), parse_vector(c_list->coords_r2, 3, data));
    if (!new_cy)
    {
        data->error = ERR_MALLOC_CYLINDER;
        return (false);
    } 
    if (!add_obj_to_scene(s, new_cy))
    {
        free(new_cy);
        data->error = ERR_ADD_CYLINDER;
        return (false);
    }
    return (true);
}

bool dispatch_obj(char **tab, t_scene *s, t_data *data)
{
    t_coords    coords_list;
    bool    res;
    
    coords_list.coords = NULL;
    coords_list.coords_r = NULL;
    coords_list.coords_r2 = NULL;
    res = true;
    if (ft_strcmp(tab[0], "sp") == 0)
        res = dispatch_sp(tab, s, &coords_list, data);
    else if (ft_strcmp(tab[0], "pl") == 0)
        res = dispatch_pl(tab, s, &coords_list, data);
    else if (ft_strcmp(tab[0], "cy") == 0)
        res = dispatch_cy(tab, s, &coords_list, data);
    else
    {
        data->error = ERR_INVALID_OBJECT_ID;
        res = false;
    }
    free_tabs(coords_list.coords, coords_list.coords_r, coords_list.coords_r2);
    return (res);
}
