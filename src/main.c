/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:48:54 by rshin             #+#    #+#             */
/*   Updated: 2025/12/15 14:29:24 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool    is_empty(int fd)
{
    if (ft_gnl(fd) == NULL)
        return (true);
	//repositionner le FD
    return (false);
}

//changer les valeurs de retours pour adapter les messages d erreur
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
	if (is_empty(env->fd)) //check fichier vide
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_env	env;

	ft_memset(&env, 0, sizeof(t_env));
	if (!check_fd(argc, argv, &env))
		return (EXIT_FAILURE);
	//a modifier : create scene deleted
	// -> scene created during parsing
	env.scene = create_scene();
	if (!env.scene)
	{
		free_env(&env);
		return (EXIT_FAILURE);
	}
	if (!parsing(env.fd, env.scene))
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
