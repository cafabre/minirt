/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:48:54 by rshin             #+#    #+#             */
/*   Updated: 2025/12/16 23:25:49 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//modifiee pour repositionner le fd au debut du fichier apres le test
static bool	is_empty(int fd)
{
	int		fd_copy;
	char	*line;

	fd_copy = dup(fd);
	if (fd_copy == -1)
		return (false);

	line = ft_gnl(fd);

	dup2(fd_copy, fd);
	close(fd_copy);

	if (line == NULL)
		return (true);

	free(line);
	return (false);
}

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
	if (is_empty(env->fd))
	{
		data->error = ERR_EMPTY_FILE;
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
	if (!parsing(env.fd, env.scene, &data))
	{
		free_env(&env);
		display_error_message(&data);
		//ligne de test - a supprimer
		ft_printf("parsing failed\n");
		return (EXIT_FAILURE);
	}
	//ligne de test - a supprimer
	ft_printf("parsing finit\n");
	
	/*if (!render_scene(&env))
	{
		free_env(&env);
		return (EXIT_FAILURE);
	}
	hook_controls(&env);
	mlx_loop(env.mlx);*/
	return (EXIT_SUCCESS);
}
