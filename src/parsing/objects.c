/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:49:39 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/04 16:15:39 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// /!\ trouver solution pour ne pas declarer min et max ET garder NULL
// solution -> va args !!!
void    fill_sphere_data(char **tab, int *error)
{
    t_obj   *sp;
    
    sp = malloc(sizeof(t_obj));
    if (!sp)
    {
        *error = 1;
        return ;
    }
    sp->type = SPHERE;
    sp->pos = parse_vectors(tab[1], NULL, NULL, error);
    sp->diam = ft_atof(tab[2]);
    sp->col = parse_vectors(tab[3], 0, 255, error);
}

void    fill_plane_data(char **tab, int *error)
{
    t_obj   *pl;

    pl = malloc(sizeof(t_obj));
    if (!pl)
    {
        *error = 1;
        return ;
    }
    pl->type = PLANE;
    pl->pos = parse_vectors(tab[1], NULL, NULL, error);
    pl->dir = parse_vectors(tab[2], -1, 1, error);
    pl->col = parse_vectors(tab[3], 0, 255, error);
}

void    fill_cylinder_data(char **tab, int *error)
{
    t_obj   *cy;
    cy = malloc(sizeof(t_obj));
    if (!cy)
    {
        *error = 1;
        return ;
    }
    cy->type = CYLINDER;
    cy->pos = parse_vectors(tab[1], NULL, NULL, error);
    cy->dir = parse_vectors(tab[2], -1, 1, error);
    cy->diam = ft_atof(tab[3]);
    cy->height = ft_atof(tab[4]);
    cy->col = parse_vectors(tab[5], 0, 255, error);
}
