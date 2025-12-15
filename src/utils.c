/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:32:15 by syukna            #+#    #+#             */
/*   Updated: 2025/12/15 16:51:11 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_objs(t_obj *lst)
{
	t_obj *tmp;

	while (lst)
	{
		tmp = lst->next;
		ft_nullfree((void **)&lst);
		lst = tmp;
	}
}

void	free_scene(t_scene *scene)
{
	if (!scene) //added nullcheck
		return ; //added
	if (scene->cam)
		ft_nullfree((void **)&scene->cam);
	if (scene->amb)
		ft_nullfree((void **)&scene->amb);
	if (scene->l)
		ft_nullfree((void **)&scene->l);
	if (scene->objs)
		free_objs(scene->objs);
	if (scene->cy)
		scene->cy = NULL;
	if (scene->pl)
		scene->pl = NULL;
    if (scene->sp)
		scene->sp = NULL;
	ft_nullfree((void **)&scene); //added now mallocked scene free
}

void	free_env(t_env *env) //added 
{
	if (!env)
		return ;
	if (env->scene)
		free_scene(env->scene);
	if (env->img)
		mlx_destroy_image(env->mlx, env->img);
	if (env->win)
		mlx_destroy_window(env->mlx, env->win);
	if (env->mlx)
	{
		mlx_destroy_display(env->mlx);
		free(env->mlx);
	}
}
