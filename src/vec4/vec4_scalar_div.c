/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_scalar_div.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:46:55 by rshin             #+#    #+#             */
/*   Updated: 2025/12/11 10:16:34 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vec4.h"

// use case :  normalizing vectors (after computing len), scaling down vecs

t_vec4	vec4_scalar_div(t_vec4 vec, float scalar)
{
	t_vec4	res;

	if (scalar == 0)
		return (vec);
	res.x = vec.x / scalar;
	res.y = vec.y / scalar;
	res.z = vec.z / scalar;
	res.w = vec.w;
	return (res);
}
