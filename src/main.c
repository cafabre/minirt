/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:48:54 by rshin             #+#    #+#             */
/*   Updated: 2026/01/14 13:54:27 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	check_fd(int argc, char **argv, t_env *env, t_data *data)
{
	int		len;
	char	*filename;

	if (argc != 2)
		return (ret_error(data, ERR_INVALID_ARGS_COUNT));
	filename = argv[1];
	len = ft_strlen(filename);
	if (len < 4)
		return (ret_error(data, ERR_INVALID_FILE_NAME));
	if (ft_strncmp(argv[1] + len - 3, ".rt", 3))
		return (ret_error(data, ERR_INVALID_FILE_TYPE));
	if (filename[len - 4] == '/')
		return (ret_error(data, ERR_INVALID_FILE_NAME));
	env->fd = open(argv[1], O_RDONLY);
	if (env->fd == -1)
		return (ret_error(data, ERR_OPEN));
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
	if (parsing(&env, &data) == EXIT_FAILURE)
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
