/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:45:02 by rshin             #+#    #+#             */
/*   Updated: 2025/12/15 15:06:36 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cam	*create_cam(t_vec4 point, t_vec4 vec, float f)
{
	t_cam	*c;

	c = ft_calloc(1, sizeof(t_cam));
	if (!c)
		return (NULL);
	c->pos = point;
	c->dir = vec;
	c->fov = f;
	return (c);
}

t_light	*create_light(t_vec4 point, float light)
{
	t_light	*l;

	l = ft_calloc(1, sizeof(t_light));
	if (!l)
		return (NULL);
	l->pos = point;
	l->lum = light;
	return (l);
}

t_light	*create_amb(float light, t_vec4 rgb)
{
	t_light	*a;

	a = ft_calloc(1, sizeof(t_light));
	if (!a)
		return (NULL);
	a->col = rgb;
	a->lum = light;
	return (a);
}

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
	pl->dir = vec;
	pl->col = color;
	pl->next = NULL;
	return (pl);
}

//create_cy(...) -> to do

t_scene	*create_scene(void)
{
	t_scene	*s;

	s = ft_calloc(1, sizeof(t_scene));
	if (!s)
		return (NULL);
	if (!s->cam)
		return (NULL);
	if (!s->l)
		return (NULL);
	if (!s->amb)
		return (NULL);
	//revoir comment ajouter les objets crees a la struct scene
	return (s);
}
