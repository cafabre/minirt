/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:44:16 by rshin             #+#    #+#             */
/*   Updated: 2025/12/11 10:18:15 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vec4.h"

// use case : move points (pos update)

t_vec4	vec4_add(t_vec4 a, t_vec4 b)
{
	t_vec4	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	res.w = a.w;
	return (res);
}
