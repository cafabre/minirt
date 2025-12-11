/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:06:41 by cafabre           #+#    #+#             */
/*   Updated: 2025/12/11 15:17:57 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec4  parse_vector(char **coords)
{
    t_vec4 vec;
    double x;
    double y;
    double z;

    if (!coords || !coords[0] || !coords[1]
        || !coords[2])
        return (vec4_point(0.0f, 0.0f, 0.0f));
    x = ft_atof(coords[0]);
    y = ft_atof(coords[1]);
    z = ft_atof(coords[2]);
    vec = vec4_point((float)x, (float)y, (float)z);
    return (vec);
}
