/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:37:18 by cafabre           #+#    #+#             */
/*   Updated: 2026/01/12 15:42:31 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	is_in_range(float f, float r_min, float r_max, t_data *data)
{
	if (f < r_min || r_max < f)
	{
		data->detail = DETAIL_OUT_OF_RANGE;
		return (false);
	}
	return (true);
}

bool	check_val(char *s, float r_min, float r_max, t_data *data)
{
	float	f;

	if (!ft_isnumber(s))
	{
		data->detail = DETAIL_NOT_A_NUMBER;
		return (false);
	}
	f = ft_atof(s);
	if (!is_in_range(f, r_min, r_max, data))
		return (false);
	return (true);
}
