/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:27:48 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/12 15:13:03 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//fonctions obseletes -> voir create.c

/*
void    fill_light_data(char **tab, bool amb)
{
    t_light   *light;
    float       l;
    int         i;

    light = malloc(sizeof(t_light));
    if (!light)
        return ;
    i = 0;
    if (!amb)
    {
        i = 1;
        light->pos = parse_vector(tab);
    }
    if (!ft_isnumber(tab[1 + i]))
        return ;
    l = ft_atof(tab[1+i]);
    if (l < 0.0f || 1.0f < l)
        return ;
    light->lum = l;
    light->col = parse_vector(tab[2+i]);
}

void    fill_camera_data(char **tab)
{
    t_cam   *cam;
    int     fov;

    cam = malloc(sizeof(t_cam));
    if (!cam)
        return ;
    if (!ft_isnumber(tab[3]))
        return ;
    cam->pos = parse_vector(tab);
    cam->dir = parse_vector(tab);
    fov = ft_atof(tab[3]);
    if (fov < 0 || 180 < fov)
        return ;
}*/
