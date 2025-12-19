/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:45:02 by rshin             #+#    #+#             */
/*   Updated: 2025/12/18 18:13:36 by cafabre          ###   ########.fr       */
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

t_light	*create_light(t_vec4 point, float light, t_vec4 rgb)
{
	t_light	*l;

	l = ft_calloc(1, sizeof(t_light));
	if (!l)
		return (NULL);
	l->pos = point;
	l->lum = light;
	l->col = rgb;
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

t_obj	*create_cy(t_vec4 point, t_vec4 vec, float d, float h, t_vec4 color)
{
	t_obj	*cy;

	cy = ft_calloc(1, sizeof(t_obj));
	if (!cy)
		return (NULL);
	cy->type = CYLINDER;
	cy->pos = point;
	cy->dir = vec4_norm(vec);
	cy->diam = d;
	cy->rad = cy->diam / 2.0f;
	cy->height = h;
	cy->col = color;
	cy->next = NULL;
	return (cy);
}

/*********** DEBUT fonctions de tests **********/
static t_obj	*create_pl2(void)
{
	t_obj	*pl;

	pl = ft_calloc(1, sizeof(t_obj));
	if (!pl)
		return (NULL);
	pl->type = PLANE;
	pl->pos = vec4_point(0, 0, 50);
	pl->dir = vec4_point(0, 0, -1);
	pl->col = vec4_color(128, 128, 0);
	pl->next = NULL;
	return (pl);
}

static t_obj	*create_pl3(void)
{
	t_obj	*pl;

	pl = ft_calloc(1, sizeof(t_obj));
	if (!pl)
		return (NULL);
	pl->type = PLANE;
	pl->pos = vec4_point(30, 0, 0);
	pl->dir = vec4_point(-1, 0, 0);
	pl->col = vec4_color(32, 64, 128);
	pl->next = NULL;
	return (pl);
}

static t_obj	*create_sp2(void)
{
	t_obj	*sp;

	sp = ft_calloc(1, sizeof(t_obj));
	if (!sp)
		return (NULL);
	sp->type = SPHERE;
	sp->pos = vec4_point(-10, 2, 20);
	sp->diam = 10;
	sp->rad = sp->diam / 2;
	sp->col = vec4_color(0, 0, 255);
	sp->next = NULL;
	return (sp);
}

static t_obj	*create_sp3(void)
{
	t_obj	*sp;

	sp = ft_calloc(1, sizeof(t_obj));
	if (!sp)
		return (NULL);
	sp->type = SPHERE;
	sp->pos = vec4_point(10, 5, -10);
	sp->diam = 10;
	sp->rad = sp->diam / 2;
	sp->col = vec4_color(128, 0, 128);
	sp->next = NULL;
	return (sp);
}
/*********** FIN fonctions de tests **********/

t_scene	*create_scene(void)
{
	t_scene	*s;

	(void)create_pl2;
	(void)create_pl3;
	(void)create_sp2;
	(void)create_sp3;

	s = ft_calloc(1, sizeof(t_scene));
	if (!s)
		return (NULL);
	return (s);
}
