/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <rshin@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:36:32 by rshin             #+#    #+#             */
/*   Updated: 2025/10/15 16:37:03 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	close_win(void *param)
{
	t_env	*env;

	env = (t_env *)param;
	//  free_env(env);
	exit (EXIT_SUCCESS);
}

static int	key_controls(int keycode, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	camera_controls(&keycode, &env->scene->cam);
	if (keycode == ESC_KEY)
	{
		exit(0);
	}
	return (0);
}

void	hook_controls(t_env *env)
{
	mlx_key_hook(env->win, key_controls, (void *)env);
	mlx_hook(env->win, 17, 0, close_win, (void *)env);
}
