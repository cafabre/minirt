/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:27:48 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/04 17:27:19 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void    fill_light_data(char **tab, bool amb, int *error)
{
    t_light   *light;
    float       l;
    int         i;

    light = malloc(sizeof(t_light));
    if (!light)
    {
        *error = 1;
        return ;
    }
    i = 0;
    if (!amb)
    {
        i = 1;
        light->pos = parse_vectors(tab, NULL, NULL, error);
    }
    l = ft_atof(tab[1+i]);
    if (l < 0.0f || 1.0f < l)
        *error = 1;
    light->lum = l;
    light->col = parse_vectors(tab[2+i], 0, 255, error);
}

void    fill_camera_data(char **tab, int *error)
{
    t_cam   *cam;
    int     fov;

    cam = malloc(sizeof(t_cam));
    if (!cam)
    {
        *error = 1;
        return ;
    }
    cam->pos = parse_vectors(tab, NULL, NULL, error);
    cam->dir = parse_vectors(tab, -1, 1, error);
    fov = ft_atof(tab[3]);
    if (fov < 0 || 180 < fov)
        *error = 1;
}
