/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:51:15 by rshin             #+#    #+#             */
/*   Updated: 2025/10/02 15:03:02 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

typedef struct s_vector_3d
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

t_vec3	vec3_add(t_vec3 a, t_vec3 b);
t_vec3	vec3_sub(t_vec3 a, t_vec3 b);
t_vec3	vec3_prod(t_vec3 a, t_vec3 b);
t_vec3	vec3_scalar_prod(t_vec3 a, double scalar);
double	vec3_dot_prod(t_vec3 a, t_vec3 b);
t_vec3	vec3_scalar_div(t_vec3 a, double scalar);
t_vec3	vec3_norm(t_vec3 vec);
double	vec3_dist(t_vec3 vec);
