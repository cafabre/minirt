/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_dist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:48:30 by rshin             #+#    #+#             */
/*   Updated: 2025/10/02 14:48:42 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

// use case : get len of vecs, get distance

double	vec3_dist(t_vec3 vec)
{
	double	dist;

	dist = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	return (dist);
}
