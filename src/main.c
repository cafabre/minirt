/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:48:54 by rshin             #+#    #+#             */
/*   Updated: 2025/10/21 17:36:57 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	check_fd(int argc, char **argv, t_env *env)
{
	int	len;

	if (argc != 2)
		return (false);
	len = ft_strlen(argv[1]);
	if (len < 3)
		return (false);
	if (ft_strncmp(argv[1] + len - 3, ".rt", 3))
		return (false);
	env->fd = open(argv[1], O_RDONLY);
	if (env->fd == -1)
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_env	env;

	ft_memset(&env, 0, sizeof(t_env));
	if (!check_fd(argc, argv, &env))
		return (EXIT_FAILURE);
	env.scene = create_scene();
	if (!env.scene)
	{
		free_env(&env);
		return (EXIT_FAILURE);
	}
	if (!render_scene(&env))
	{
		free_env(&env);
		return (EXIT_FAILURE);
	}
	hook_controls(&env);
	mlx_loop(env.mlx);
	return (EXIT_SUCCESS);
}
