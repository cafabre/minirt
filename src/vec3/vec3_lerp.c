/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_lerp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:45:55 by rshin             #+#    #+#             */
/*   Updated: 2025/10/02 15:46:22 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

// use case : linear interpolation for smooth blending (light, color, vecs...)

t_vec3	vec3_lerp(t_vec3 a, t_vec3 b, double factor)
{
	t_vec3	res;

	res.x = a.x + (b.x - a.x) * factor;
	res.y = a.y + (b.y - a.y) * factor;
	res.z = a.z + (b.z - a.z) * factor;
	return (res);
}
