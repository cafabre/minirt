/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:50:21 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/16 12:25:08 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool dispatch_amb(char **tab, t_scene *s, char ***coords_r)
{
    t_light *new_amb;
    
    *coords_r = check_coords_range(tab[2], 0, 255);
    if (!check_val(tab[1], 0.0f, 1.0f) || !*coords_r)
    {
        free_tab(*coords_r);
        //data->error = ERR_ invalid data for ambient light
        return (false);
    }
    //test si un amb existe deja -> fait dans dispatch_scene
    // (idem pour light et cam)
    new_amb = create_amb(ft_atof(tab[1]), parse_vector(*coords_r, 3));
    if (!new_amb)
    {
        //data->error = ERR_ calloc error : couldnt allocate ambient light
        return (false);
    }
    if (!)//add amb to scene
    {
        free(new_amb);
        //data->error = ERR_ couldnt add the ambient light to the scene
        return (false)
    }
    return (true);
}

static bool dispatch_light(char **tab, t_scene *s, char ***coords)
{
    t_light *new_l;
    
    *coords = check_coords(tab[1]);
    if (!*coords || !check_val(tab[2], 0.0f, 1.0f))
    {
        free_tab(*coords);
        //data->error = ERR_ invalid data for light spot
        return (false);
    }
    new_l = create_light(parse_vector(*coords, 1), ft_atof(tab[2]));
    if (!new_l)
    {
        //data->error = ERR_ calloc error : couldnt allocate light spot
        return (false);
    }
    if (!) //add light to scene
    {
        free(new_l);
        //data->error = ERR_ couldnt add the light spot to the scene
        return (false);
    }
    return (true);
}

static bool dispatch_cam(char **tab, t_scene *s, char ***coords, char ***coords_r)
{
    t_cam   *new_cam;
    
    *coords = check_coords(tab[1]);
    *coords_r = check_coords_range(tab[2], -1, 1);
    if (!*coords || !*coords_r || !check_val(tab[3], 0, 180))
    {
        free_tab(*coords);
        free_tab(*coords_r);
        //data->error = ERR_ invalid data for camera
        return (false);
    }
    new_cam = create_cam(parse_vector(*coords, 1), parse_vector(*coords_r, 2), ft_atof(tab[3]));
    if (!new_cam)
    {
        //data->error = ERR_ calloc error : couldnt allocate camera
        return (false);
    }
    if (!) //add cam to scene
    {
        free(new_cam);
        //data->error = ERR_ couldnt add the camera to the scene
        return (false);
    }
    return (true);
}

bool dispatch_scene(char **tab, t_scene *s, t_data *data)
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
        {
            //data->error = ERR_ there is already an existing ambient light
            return (false);
        }
        res = dispatch_amb(tab, s, &coords_r);
    }
    else if (ft_strcmp(tab[0], "L") == 0)
    {
        if (s->l)
        {
            //data->error = ERR_ there is already an existing light spot
            return (false);
        }
        res = dispatch_light(tab, s, &coords);
    }
    else if (ft_strcmp(tab[0], "C") == 0)
    {
        if (s->cam)
        {
            //data->error = ERR_ there is already an existing camera
            return (false);
        }
        res = dispatch_cam(tab, s, &coords, &coords_r);
    }
    else
    {
        //data->error = ERR_ not a valid id
        res = false;
    }
    free_tab(coords);
    free_tab(coords_r);
    return (res);
}
