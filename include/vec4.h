/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:36:46 by syukna            #+#    #+#             */
/*   Updated: 2026/01/12 16:00:34 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC4_H
# define VEC4_H

typedef union u_vector_4d
{
	struct
	{
		float	x;
		float	y;
		float	z;
		float	w;
	};
	struct
	{
		float	r;
		float	g;
		float	b;
		float	a;
	};
}	t_vec4;

typedef struct s_matrix_4x4
{
	t_vec4	m[4];
}	t_mat4;

t_vec4	vec4_point(float x, float y, float z);
t_vec4	vec4_vector(float x, float y, float z);
t_vec4	vec4_color(float x, float y, float z);

t_vec4	vec4_add(t_vec4 a, t_vec4 b);
t_vec4	vec4_sub(t_vec4 a, t_vec4 b);
t_vec4	vec4_mul(t_vec4 a, t_vec4 b);
t_vec4	vec4_cross_prod(t_vec4 a, t_vec4 b);
float	vec4_dot_prod(t_vec4 a, t_vec4 b);
t_vec4	vec4_scalar_mul(t_vec4 a, float scalar);
t_vec4	vec4_scalar_div(t_vec4 a, float scalar);
float	vec4_len(t_vec4 vec);
t_vec4	vec4_neg(t_vec4 a);
t_vec4	vec4_norm(t_vec4 vec);
t_vec4	vec4_mat4_prod(t_vec4 v, const t_mat4 *m);

#endif
