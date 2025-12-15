/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_mul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <rshin@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:41:12 by rshin             #+#    #+#             */
/*   Updated: 2025/12/15 15:43:35 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vec4.h"

// use case : component wise multiplication (for colors)

t_vec4	vec4_mul(t_vec4 a, t_vec4 b)
{
	t_vec4	res;

	res.r = a.r * b.r;
	res.g = a.g * b.g;
	res.b = a.b * b.b;
	res.a = a.a * b.a;
	return (res);
}
