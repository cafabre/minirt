/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:06:41 by cafabre           #+#    #+#             */
/*   Updated: 2026/01/12 15:50:15 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

t_vec4	parse_vector(char **coords, int type, t_data *data)
{
	t_vec4	vec;
	double	x;
	double	y;
	double	z;

	if (!coords || !coords[0] || !coords[1]
		|| !coords[2])
	{
		data->error = ERR_INVALID_VECTOR_COORDS;
		return (vec4_point(NAN, NAN, NAN));
	}
	x = ft_atof(coords[0]);
	y = ft_atof(coords[1]);
	z = ft_atof(coords[2]);
	if (type == 1)
		vec = vec4_point((float)x, (float)y, (float)z);
	else if (type == 2)
		vec = vec4_vector((float)x, (float)y, (float)z);
	else
		vec = vec4_color((float)x, (float)y, (float)z);
	return (vec);
}
