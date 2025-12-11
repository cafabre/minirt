/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:45:02 by rshin             #+#    #+#             */
/*   Updated: 2025/12/11 14:23:09 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_cam	*create_cam(void)
{
	t_cam	*c;

	c = ft_calloc(1, sizeof(t_cam));
	if (!c)
		return (NULL);
	c->pos = vec4_point(0, -20, 5);
	c->dir = vec4_vector(0, 1, 0);
	c->fov = 40;
	return (c);
}

static t_light	*create_light(char **tab)
{
	t_light	*l;

	l = ft_calloc(1, sizeof(t_light));
	if (!l)
		return (NULL);
	l->pos = vec4_point(tab[1][0], tab[1][1], tab[1][2]);
	l->lum = ft_atof(tab[2]);
	return (l);
}

static t_light	*create_amb(char **tab)
{
	t_light	*a;

	a = ft_calloc(1, sizeof(t_light));
	if (!a)
		return (NULL);
	a->col = vec4_color(tab[2][0], tab[2][1], tab[2][2]);
	a->lum = ft_atof(tab[1]);
	return (a);
}

static t_obj	*create_sp(void)
{
	t_obj	*sp;

	sp = ft_calloc(1, sizeof(t_obj));
	if (!sp)
		return (NULL);
	sp->type = SPHERE;
	sp->pos = vec4_point(0, 0, 5);
	sp->diam = 10;
	sp->rad = sp->diam / 2;
	sp->col = vec4_color(255, 0, 0);
	sp->next = NULL;
	return (sp);
}
/*
static t_obj	*create_pl(void)
{
	t_obj	*pl;

	pl = ft_calloc(1, sizeof(t_obj));
	if (!pl)
		return (NULL);
	pl->type = PLANE;
	pl->pos = vec4_point(0, 0, -50);
	pl->dir = vec4_point(0, 0, 1);
	pl->col = vec4_point(0, 255, 0);
	pl->next = NULL;
	return (pl);
}
*/
t_scene	*create_scene(void)
{
	t_scene	*s;

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
	s->objs = create_sp();
//	s->obj->next = create_pl();
	s->objs->next = NULL;
	return (s);
}
