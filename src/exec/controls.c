/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <rshin@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:36:32 by rshin             #+#    #+#             */
/*   Updated: 2025/10/17 12:58:26 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	close_win(void *param)
{
	t_env	*env;

	env = (t_env *)param;
	free_env(env);
	exit (EXIT_SUCCESS);
}

static int	key_controls(int keycode, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (keycode == ESC_KEY)
		close_win((void *)env);
	return (0);
}

void	hook_controls(t_env *env)
{
	mlx_key_hook(env->win, key_controls, (void *)env);
	mlx_hook(env->win, 17, 0, close_win, (void *)env);
}
