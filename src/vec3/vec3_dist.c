/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_dist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:48:30 by rshin             #+#    #+#             */
/*   Updated: 2025/10/02 15:48:24 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

// use case : get len of vecs, get distance

double	vec3_dist(t_vec3 a, t_vec3 b)
{
	t_vec3	diff;
	double	dist;

	diff = vec3_sub(a, b);
	dist = vec3_len(diff);
	return (dist);
}
