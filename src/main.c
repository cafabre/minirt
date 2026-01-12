/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:48:54 by rshin             #+#    #+#             */
/*   Updated: 2026/01/12 15:12:24 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	check_fd(int argc, char **argv, t_env *env, t_data *data)
{
	int	len;

	if (argc != 2)
	{
		data->error = ERR_INVALID_ARGS_COUNT;
		return (false);
	}
	len = ft_strlen(argv[1]);
	if (len < 3)
	{
		data->error = ERR_INVALID_FILE_NAME;
		return (false);
	}
	if (ft_strncmp(argv[1] + len - 3, ".rt", 3))
	{
		data->error = ERR_INVALID_FILE_TYPE;
		return (false);
	}
	env->fd = open(argv[1], O_RDONLY);
	if (env->fd == -1)
	{
		data->error = ERR_OPEN;
		return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_env	env;
	t_data	data;

	data.error = ERR_NONE;
	data.detail = DETAIL_NONE;
	ft_memset(&env, 0, sizeof(t_env));
	if (!check_fd(argc, argv, &env, &data))
	{
		display_error_message(&data);
		return (EXIT_FAILURE);
	}
	env.scene = create_scene();
	if (!env.scene)
	{
		free_env(&env);
		return (EXIT_FAILURE);
	}
	if (parsing(env.fd, env.scene, &data) == EXIT_FAILURE)
	{
		free_env(&env);
		display_error_message(&data);
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
