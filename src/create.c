/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <rshin@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:45:02 by rshin             #+#    #+#             */
/*   Updated: 2025/12/17 14:28:43 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_cam	*create_cam(void)
{
	t_cam	*c;

	c = ft_calloc(1, sizeof(t_cam));
	if (!c)
		return (NULL);
	c->pos = vec4_point(0, 5, -50);
	c->dir = vec4_vector(0, 0, 1);
	c->fov = 40;
	return (c);
}

static t_light	*create_light(void)
{
	t_light	*l;

	l = ft_calloc(1, sizeof(t_light));
	if (!l)
		return (NULL);
	l->pos = vec4_point(-20, 20, -5);
	l->col = vec4_color(255, 255, 255);
	l->lum = 0.3f;
	return (l);
}

static t_light	*create_amb(void)
{
	t_light	*a;

	a = ft_calloc(1, sizeof(t_light));
	if (!a)
		return (NULL);
	a->col = vec4_color(0, 0, 255);
	a->lum = 1.0f;
	return (a);
}

static t_obj	*create_sp(void)
{
	t_obj	*sp;

	sp = ft_calloc(1, sizeof(t_obj));
	if (!sp)
		return (NULL);
	sp->type = SPHERE;
	sp->pos = vec4_point(0, 0, 0);
	sp->diam = 10;
	sp->rad = sp->diam / 2;
	sp->col = vec4_color(255, 0, 0);
	sp->next = NULL;
	return (sp);
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

static t_obj	*create_pl(void)
{
	t_obj	*pl;

	pl = ft_calloc(1, sizeof(t_obj));
	if (!pl)
		return (NULL);
	pl->type = PLANE;
	pl->pos = vec4_point(0, -5, 0);
	pl->dir = vec4_point(0, 1, 0);
	pl->col = vec4_color(0, 255, 0);
	pl->next = NULL;
	return (pl);
}

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

t_scene	*create_scene(void)
{
	t_scene	*s;
	t_obj	*curr;

	s = ft_calloc(1, sizeof(t_scene));
	if (!s)
		return (NULL);
	s->cam = create_cam();
	if (!s->cam)
		return (NULL);
	s->l = create_light();
	if (!s->l)
		return (NULL);
	s->amb = create_amb();
	if (!s->amb)
		return (NULL);
//	s->objs = create_sp();
//	s->objs->next = create_pl();
//	s->objs->next->next = NULL;
	s->objs = create_sp();
	curr = s->objs;
	curr->next = create_sp2();	
	curr = curr->next;	
	curr->next = create_sp3();
	curr = curr->next;	
	curr->next = create_pl();
	curr = curr->next;	
	curr->next = create_pl2();
	curr = curr->next;	
	curr->next = create_pl3();
	curr = curr->next;	
	return (s);
}
