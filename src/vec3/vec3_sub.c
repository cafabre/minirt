/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_subst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:46:40 by rshin             #+#    #+#             */
/*   Updated: 2025/10/02 15:02:32 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// use case : find direction from point b to point a

t_vec3	vec3_sub(t_vec3 a, t_vec3 b)
{
	t_vec3	res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);	
}
