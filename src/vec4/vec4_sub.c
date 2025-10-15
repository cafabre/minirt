/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:46:40 by rshin             #+#    #+#             */
/*   Updated: 2025/10/02 15:54:08 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec4.h"

// use case : find direction from point b to point a

t_vec4	vec4_sub(t_vec4 a, t_vec4 b)
{
	t_vec4	res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}
