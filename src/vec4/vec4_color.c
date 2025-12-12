/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:47:59 by rshin             #+#    #+#             */
/*   Updated: 2025/12/11 09:13:01 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vec4.h"

// use case : create a new color

t_vec4	vec4_color(float x, float y, float z)
{
	t_vec4	color;

	color.x = x;
	color.y = y;
	color.z = z;
	color.w = 1.0;
	color = vec4_scalar_div(color, 255);
	return (color);
}
