/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:06:41 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/10 18:13:10 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool  is_in_range(float f, float r_min, float r_max)
{
    if (f < r_min || r_max < f)
        return (false);
    return (true);
}

static t_vec4   *fill_vector(t_vec4 *vec, char **coords)
{
    float   x;
    float   y;
    float   z;
    int     i;
    
    i = 0;
    while (i <= 2)
    {
        if (!ft_isnumber(coords[i]))
            return (NULL);
    }
    x = ft_atof(coords[0]);
    y = ft_atof(coords[1]);
    z = ft_atof(coords[2]);
    *vec = vec4_vector(x, y, z);
    return (vec);
}

//fonction obselete - voir dispatcher + check_val / check_coords

//en entree : tab[1] pour L, sp, pl, cy + range min et max (optionnels)
// /!\ utiliser egalement pour les vecteurs et les couleurs
t_vec4 *parse_vectors(char **tab, float *r_min, float *r_max)
{
    t_vec4   *vec;
    char    **coords;

    //gerer les cas de "mauvaise ecriture"
    //(espaces, lettres, plusieurs virgules....)
    vec = malloc(sizeof(t_vec4));
    if (!vec)
        return (NULL);
    coords = ft_split(tab[1], ',');
    if (ft_tablen(coords) != 3)
        free_tab(coords); // a coder
        return (NULL);
    vec = fill_vector(vec, coords);
    if (!vec || (r_min && r_max && !in_range(*vec, r_min, r_max)))
        free_tab(coords);
        return (NULL);
    return (vec);
}
