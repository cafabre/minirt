/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_lerp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:45:55 by rshin             #+#    #+#             */
/*   Updated: 2025/10/08 11:44:15 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec4.h"

// use case : linear interpolation for smooth blending (light, color, vecs...)

t_vec4	vec4_lerp(t_vec4 a, t_vec4 b, double factor)
{
	t_vec4	res;

	res.x = a.x + (b.x - a.x) * factor;
	res.y = a.y + (b.y - a.y) * factor;
	res.z = a.z + (b.z - a.z) * factor;
	return (res);
}
