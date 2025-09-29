/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:48:54 by rshin             #+#    #+#             */
/*   Updated: 2025/09/29 13:10:48 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	check_args(int argc, char **argv)
{
	int	len;

	if (argc != 2)
		return (false);
	len = ft_strlen(argv[2]);
	if (len < 3)
		return (false);
	if (ft_strncmp(argv[2] + len - 3, ".rt", 3) == 0)
		return (true);
	return (false);
}

int	main(int argc, char **argv)
{
	t_env	env;
	int		fd;

	if (!check_args(argc, argv))
		return (EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE);
	if (!init_env(&env))
	{
		close(fd);
		return (EXIT_FAILURE);
	}
	if (!parse_scene(&env, fd))
		return (EXIT_FAILURE);
	if (!render_scene(&env);
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
