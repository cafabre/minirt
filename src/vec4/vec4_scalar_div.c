/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_scalar_div.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:46:55 by rshin             #+#    #+#             */
/*   Updated: 2025/10/08 11:44:26 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec4.h"

// use case :  normalizing vectors (after computing len), scaling down vecs

t_vec4	vec4_scalar_div(t_vec4 vec, double scalar)
{
	t_vec4	res;

	if (scalar == 0)
		return (vec);
	res.x = vec.x / scalar;
	res.y = vec.y / scalar;
	res.z = vec.z / scalar;
	return (res);
}
