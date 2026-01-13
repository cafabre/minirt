/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:48:54 by rshin             #+#    #+#             */
/*   Updated: 2026/01/13 14:08:40 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	check_fd(int argc, char **argv, t_env *env, t_data *data)
{
	int	len;

	if (argc != 2)
		return (ret_error(data, ERR_INVALID_ARGS_COUNT));
	len = ft_strlen(argv[1]);
	//test ne fonctionne pas si on appelle un fichier situe dans un sous dossier
	//ex : scences/0_bad/.rt -> len du nom > 4
	if (len < 4)
		return (ret_error(data, ERR_INVALID_FILE_NAME));
	if (ft_strncmp(argv[1] + len - 3, ".rt", 3))
		return (ret_error(data, ERR_INVALID_FILE_TYPE));
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

/*
RESTE A FAIRE
- refactor of functions over 25 lines -> ONGOING
    -> parse_ids DONE
    -> dispatch_ids DONE
    -> dispatch_scene TO DO
    -> check_coords DONE
    -> display_error_message DONE
    -> ft_atof DONE
    -> ft_isnumber DONE
- move libft_utils.c functions into the libft
- exec cylinder

ISSUES
- ambient lighting isnt right (ex : amb max + no light -> shadows shouldnt appear) -> exec
- colored light spot works with spheres, not planes -> exec
- add the code to make create_cy(...) work -> render of cylinders not tested yet -> exec
- pixelated results in some cases (recurring issue in minirt, solutions easily found on internet) -> exec
    --> see single_sp_room.rt

FIXED
- "invalid number of arguments on one line" when whitespaces at the end of the line -> parsing
    --> fix : ft_strtrim(line, " \t\n") before split
- "invalid number of arguments on one line" when wrong id at the beginning of the line -> parsing
    --> fix : changed the main dispatcher logic
- need to check that there is at least one C, one L and one A -> parsing
    --> fix : added a check in parse_ids at the end of the loop

IMPROVEMENTS
- ft_strcmp to get the id -> called twice (dispatch_id and dispatch_scene / dispatch_obj) -> parsing
    --> find a way to keep only one check

BONUS
- add color to light -> NOT FINISHED (errors to handle)
*/