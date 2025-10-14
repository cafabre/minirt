/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_dist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:48:30 by rshin             #+#    #+#             */
/*   Updated: 2025/10/08 11:44:05 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec4.h"

// use case : get len of vecs, get distance

double	vec4_dist(t_vec4 a, t_vec4 b)
{
	t_vec4	diff;
	double	dist;

	diff = vec4_sub(a, b);
	dist = vec4_len(diff);
	return (dist);
}
