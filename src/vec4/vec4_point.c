/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:47:59 by rshin             #+#    #+#             */
/*   Updated: 2025/10/14 20:07:12 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vec4.h"

// use case : create a new point

t_vec4	vec4_point(float x, float y, float z)
{
	t_vec4	point;

    point.x = x;
    point.y = y;
    point.z = z;
    point.w = 1.0;
    return (point);
}
