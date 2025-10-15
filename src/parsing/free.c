/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandykds <sandykds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:32:15 by syukna            #+#    #+#             */
/*   Updated: 2025/10/14 12:11:42 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_objs(t_obj *lst)
{
	t_obj *tmp;

	while (lst)
	{
		tmp = lst->next_objs;
		free(lst);
		lst = tmp;
	}
}


void	free_all(t_scene *scene)
{
	if (scene->cam)
		free(scene->cam);
	if (scene->amb)
		free(scene->amb);
	if (scene->l)
		free(scene->l);
	if (scene->objs)
		free_objs(scene->objs);
	if (scene->cy)
		scene->cy = NULL;
	if (scene->pl)
		scene->pl = NULL;
    if (scene->sp)
		scene->sp = NULL;
}
