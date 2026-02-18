/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:23:45 by cafabre           #+#    #+#             */
/*   Updated: 2026/02/18 16:56:12 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	parse_lines_clean(char **tab, char *tmp)
{
	free_tab(tab);
	if (tmp)
		free(tmp);
	return (false);
}

static bool	parse_lines(int fd, t_scene *s, t_data *data, bool *empty_fd)
{
	char	*tmp;
	char	*line;
	char	**tab;

	*empty_fd = true;
	tmp = ft_get_next_line(fd);
	line = NULL;
	while (tmp)
	{
		*empty_fd = false;
		line = ft_strtrim(tmp, " \t\n");
		free(tmp);
		tab = ft_split_whitespaces(line);
		free (line);
		tmp = ft_get_next_line(fd);
		if (!tab || !tab[0] || ft_strcmp(tab[0], "\n") == 0)
		{
			free_tab(tab);
			continue ;
		}
		if (!dispatch_ids(tab, s, data))
			return (parse_lines_clean(tab, tmp));
		free_tab(tab);
	}
	return (true);
}

static bool	parse_scene(t_scene *s, t_data *data, bool *empty_fd)
{
	if (*empty_fd)
		return (ret_error(data, ERR_EMPTY_FILE));
	if (!s->cam || !s->amb || !s->l)
		return (ret_error(data, ERR_MISSING_ELEMENT));
	return (true);
}

int	parsing(t_env *env, t_data *data)
{
	bool	empty_fd;

	env->scene = ft_calloc(1, sizeof(t_scene));
	if (!env->scene)
		return (EXIT_FAILURE);
	if (!parse_lines(env->fd, env->scene, data, &empty_fd))
		return (EXIT_FAILURE);
	if (!parse_scene(env->scene, data, &empty_fd))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
