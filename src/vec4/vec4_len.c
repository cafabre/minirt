/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:49:12 by rshin             #+#    #+#             */
/*   Updated: 2025/10/07 19:02:47 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec4.h"

// use case : calculate length || magnitude of a single vector

double	vec4_len(t_vec4 vec)
{
	double	len;

	len = sqrt(vec4_dot_prod(vec, vec));
	return (len);
}
