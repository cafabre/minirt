/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_cross_prod.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:45:10 by rshin             #+#    #+#             */
/*   Updated: 2025/12/11 13:17:23 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vec4.h"

// use case : find surface normals for polygons, computes perpendicular vecs, calc tangent spaces

t_vec4	vec4_cross_prod(t_vec4 a, t_vec4 b)
{
	t_vec4	res;

	res.x = a.y * b.z - a.z * b.y;
	res.y = a.z * b.x - a.x * b.z;
	res.z = a.x * b.y - a.y * b.x;
	res.w = a.w;
	return (res);
}
