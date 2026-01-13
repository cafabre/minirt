/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_scalar_prod.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:45:49 by rshin             #+#    #+#             */
/*   Updated: 2026/01/13 15:16:20 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vec4.h"

/* use case : scaling vectors || directions,
convert normalized vecs to desired len */

t_vec4	vec4_scalar_prod(t_vec4 vec, float scalar)
{
	t_vec4	res;

	res.x = vec.x * scalar;
	res.y = vec.y * scalar;
	res.z = vec.z * scalar;
	res.w = vec.w;
	return (res);
}
