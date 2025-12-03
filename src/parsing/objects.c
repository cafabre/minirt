/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:49:39 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/03 17:27:52 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing.h"

//en entree : tab[1] pour L, sp, pl, cy + range min et max (optionnels)
// /!\ utiliser egalement pour les vecteurs et les couleurs
static t_vec4 parse_vectors(char **tab, float *r_min, float *r_max, int *error)
{
    t_vec4   vec;
    char    **s;

    //gerer les cas de "mauvaise ecriture"
    //(espaces, lettres, plusieurs virgules....)
    memset(&vec, 0, sizeof(t_vec4));
    s = ft_split(tab[1], ',');
    *error = 0;
    if (ft_tablen(s) != 3)
    {
        *error = 1;
        return (vec);
    }
    vec.x = ft_atof(s[0]);
    vec.y = ft_atof(s[1]);
    vec.z = ft_atof(s[2]);
    if (r_min && r_max)
    {
        if (vec.x > *r_max || *r_min > vec.x || vec.y > *r_max ||
            *r_min > vec.y || vec.z > *r_max || *r_min > vec.z)
            *error = 1;
    }
    ft_free_tab(s); //a coder
    return (vec);
}

// /!\ trouver solution pour ne pas declarer min et max ET garder NULL
// solution -> va args !!!
void    fill_sphere_data(char **tab, int *error)
{
    t_obj   *sp;
    float   min;
    float   max;
    
    sp = malloc(sizeof(t_obj));
    if (!sp)
    {
        *error = 1;
        return ;
    }
    min = 0;
    max = 255;
    sp->type = SPHERE;
    sp->pos = parse_vectors(tab[1], NULL, NULL, error);
    sp->diam = ft_atof(tab[2]);
    sp->col = parse_vectors(tab[3], &min, &max, error);
}

void    fill_plane_data(char **tab, int *error)
{
    t_obj   *pl;
    float   min;
    float   max;

    pl = malloc(sizeof(t_obj));
    if (!pl)
    {
        *error = 1;
        return ;
    }
    pl->type = PLANE;
    pl->pos = parse_vectors(tab[1], NULL, NULL, error);
    min = -1;
    max = 1;
    pl->dir = parse_vectors(tab[2], &min, &max, error);
    min = 0;
    max = 255;
    pl->col = parse_vectors(tab[3], &min, &max, error);
}

void    fill_cylinder_data(char **tab, int *error)
{
    t_obj   *cy;
    float   min;
    float   max;

    cy = malloc(sizeof(t_obj));
    if (!cy)
    {
        *error = 1;
        return ;
    }
    cy->type = CYLINDER;
    cy->pos = parse_vectors(tab[1], NULL, NULL, error);
    min = -1;
    max = 1;
    cy->dir = parse_vectors(tab[2], &min, &max, error);
    cy->diam = ft_atof(tab[3]);
    cy->height = ft_atof(tab[4]);
    min = 0;
    max = 255;
    cy->col = parse_vectors(tab[5], &min, &max, error);
}
