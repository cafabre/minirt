/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:45:02 by rshin             #+#    #+#             */
/*   Updated: 2026/01/13 15:58:21 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_obj	*create_sp(t_vec4 point, float d, t_vec4 color)
{
	t_obj	*sp;

	sp = ft_calloc(1, sizeof(t_obj));
	if (!sp)
		return (NULL);
	sp->type = SPHERE;
	sp->pos = point;
	sp->diam = d;
	sp->rad = sp->diam / 2;
	sp->col = color;
	sp->next = NULL;
	return (sp);
}

t_obj	*create_pl(t_vec4 point, t_vec4 vec, t_vec4 color)
{
	t_obj	*pl;

	pl = ft_calloc(1, sizeof(t_obj));
	if (!pl)
		return (NULL);
	pl->type = PLANE;
	pl->pos = point;
	pl->dir = vec4_norm(vec);
	pl->col = color;
	pl->next = NULL;
	return (pl);
}

t_obj	*create_cy(t_vec4 point, t_vec4 vec, t_dim dim, t_vec4 color)
{
	t_obj	*cy;

	cy = ft_calloc(1, sizeof(t_obj));
	if (!cy)
		return (NULL);
	cy->type = CYLINDER;
	cy->pos = point;
	cy->dir = vec4_norm(vec);
	cy->diam = dim.d;
	cy->rad = cy->diam / 2.0f;
	cy->height = dim.h;
	cy->col = color;
	cy->next = NULL;
	return (cy);
}
