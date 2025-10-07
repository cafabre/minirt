/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_scalar_div.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:46:55 by rshin             #+#    #+#             */
/*   Updated: 2025/10/02 14:47:44 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

// use case :  normalizing vectors (after computing len), scaling down vecs

t_vec3	vec3_scalar_div(t_vec3 vec, double scalar)
{
	t_vec3	res;

	if (scalar == 0)
		return (vec);
	res.x = vec.x / scalar;
	res.y = vec.y / scalar;
	res.z = vec.z / scalar;
	return (res);
}
