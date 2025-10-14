/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandykds <sandykds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:01:50 by syukna            #+#    #+#             */
/*   Updated: 2025/10/14 12:12:34 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_obj(t_obj *obj, t_obj **list)
{
	t_obj	*temp;
	if (*list)
	{
		temp = *list;
		while (temp->next)
			temp = temp->next;
		temp->next = obj;
	}
	else
		*list = obj;
}

int	add_objs(t_obj *obj, t_scene *scene)
{
	t_obj	*temp;

	if (scene->objs)
	{
		temp = scene->objs;
		while (temp->next_objs)
			temp = temp->next_objs;
		temp->next_objs = obj;
	}
	else
		scene->objs = obj;
	if (obj->type == PLANE)
		add_obj(obj, &scene->pl);
	else if (obj->type == SPHERE)
		add_obj(obj, &scene->sp);
	else if (obj->type == CYLINDER)
		add_obj(obj, &scene->cy);
	return (EXIT_SUCCESS);
}

int init_obj(char **args, t_scene *scene, t_objtype objt)
{
	t_obj	*obj;
	int		i;

	i = 1;
	obj = malloc(sizeof(t_obj));
	if (!obj)
		return (0);
	ft_memset(obj, '\0', sizeof(t_obj));
	obj->type = objt;
	obj->coor = init_vec4();
	obj->vector = init_vec4();
	if (!get_coor(args[i++], &obj->coor))
		return (free(obj),EXIT_FAILURE);
	if (obj->type != SPHERE && !get_norm(args[i++], &obj->vector))
		return (free(obj),EXIT_FAILURE);
	if (obj->type != PLANE)
		obj->diameter = atof(args[i++]);
	if (obj->type == CYLINDER)
		obj->height = atof(args[i++]);
	if (!get_color(args[i], obj))
		return (free(obj),EXIT_FAILURE);
	obj->next = NULL;
	add_objs(obj, scene);
	return (EXIT_SUCCESS);
}
