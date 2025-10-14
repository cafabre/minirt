/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:36:46 by syukna            #+#    #+#             */
/*   Updated: 2025/10/14 20:36:04 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC4_H
# define VEC4_H

# include <math.h>

typedef struct s_vector_4d
{
	float  x;
	float  y;
	float  z;
	float  w;
}   t_vec4;

typedef struct  s_matrix_4x4
{
	double  m[4][4];
}   t_mat4;

t_vec4	vec4_point(float x, float y, float z);
t_vec4	vec4_vector(float x, float y, float z);

t_vec4	vec4_add(t_vec4 a, t_vec4 b);
t_vec4	vec4_sub(t_vec4 a, t_vec4 b);
t_vec4	vec4_cross_prod(t_vec4 a, t_vec4 b);
float	vec4_dot_prod(t_vec4 a, t_vec4 b);
t_vec4	vec4_scalar_prod(t_vec4 a, float scalar);
t_vec4	vec4_scalar_div(t_vec4 a, float scalar);
float	vec4_len(t_vec4 vec);
float	vec4_dist(t_vec4 a, t_vec4 b);
t_vec4	vec4_neg(t_vec4 a);
t_vec4	vec4_norm(t_vec4 vec);
t_vec4	vec4_lerp(t_vec4 a, t_vec4 b, float factor);
t_vec4	vec4_mat4_prod(t_vec4 v, t_mat4 m);
t_mat4	mat4_prod(t_mat4 a, t_mat4 b);

#endif
