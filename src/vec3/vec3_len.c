/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:49:12 by rshin             #+#    #+#             */
/*   Updated: 2025/10/02 15:51:03 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

// use case : calculate length || magnitude of a single vector

double	vec3_len(t_vec3 vec)
{
	double	len;

	len = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	return (len);
}
