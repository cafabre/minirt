/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_neg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:27:19 by rshin             #+#    #+#             */
/*   Updated: 2025/10/02 15:50:38 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

// use case : reverse a direction (reflection / refraction)

t_vec3	vec3_neg(t_vec3 vec)
{
	t_vec3	res;

	res.x = -vec.x;
	res.y = -vec.y;
	res.z = -vec.z;
	return (res);
}
