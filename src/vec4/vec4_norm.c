/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_norm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:47:59 by rshin             #+#    #+#             */
/*   Updated: 2025/10/14 20:11:25 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vec4.h"

// use case : converts any vec to a unit vector

t_vec4	vec4_norm(t_vec4 vec)
{
	t_vec4	res;
	float	len;

	len = vec4_len(vec);
	if (len == 0)
	{
		res.x = 0;
		res.y = 0;
		res.z = 0;
	}
	else
		res = vec4_scalar_div(vec, len);
	return (res);
}
