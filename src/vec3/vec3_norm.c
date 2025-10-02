/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_norm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:47:59 by rshin             #+#    #+#             */
/*   Updated: 2025/10/02 16:06:50 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

// use case : converts any vec to a unit vector

t_vec3	vec3_norm(t_vec3 vec)
{
	t_vec3	res;
	double	len;

	len = vec3_len(vec);
	if (len == 0)
	{
		res.x = 0;
		res.y = 0;
		res.z = 0;
	}
	else
		res = vec3_scalar_div(vec, len);
	return (res);
}
