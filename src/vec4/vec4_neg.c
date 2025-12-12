/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_neg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:27:19 by rshin             #+#    #+#             */
/*   Updated: 2025/12/11 10:11:51 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vec4.h"

// use case : reverse a direction (reflection / refraction)

t_vec4	vec4_neg(t_vec4 vec)
{
	t_vec4	res;

	res.x = -vec.x;
	res.y = -vec.y;
	res.z = -vec.z;
	res.w = vec.w;
	return (res);
}
