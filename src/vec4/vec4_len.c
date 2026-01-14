/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:49:12 by rshin             #+#    #+#             */
/*   Updated: 2025/10/14 20:10:22 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vec4.h"

// use case : calc vector magnitude

float	vec4_len(t_vec4 vec)
{
	float	len;

	len = sqrt(vec4_dot_prod(vec, vec));
	return (len);
}
