/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:49:39 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/11 15:18:43 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//obselete : voir create.c

/*
void    fill_sphere_data(char **tab)
{
    t_obj   *sp;
    
    sp = ft_calloc(1, sizeof(t_obj));
    if (!sp)
        return ;
    sp->type = SPHERE;
    sp->pos = vec4_point(...);
    sp->diam = ft_atof(...);
    sp->col = parse_vector(...);
}

void    fill_plane_data(char **tab)
{
    t_obj   *pl;

    pl = malloc(sizeof(t_obj));
    if (!pl)
        return ;
    pl->type = PLANE;
    pl->pos = parse_vector(tab[1], NULL, NULL);
    pl->dir = parse_vector(tab[2], -1, 1);
    pl->col = parse_vector(tab[3], 0, 255);
}

void    fill_cylinder_data(char **tab)
{
    t_obj   *cy;
    cy = malloc(sizeof(t_obj));
    if (!cy)
        return ;
    if (!ft_isnumber(tab[3]) || !ft_isnumber(tab[4]))
        return ;
    cy->type = CYLINDER;
    cy->pos = parse_vector(tab[1], NULL, NULL);
    cy->dir = parse_vector(tab[2], -1, 1);
    cy->diam = ft_atof(tab[3]);
    cy->height = ft_atof(tab[4]);
    cy->col = parse_vector(tab[5], 0, 255);
}
    */
