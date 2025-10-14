/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coor.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:55:44 by syukna            #+#    #+#             */
/*   Updated: 2025/10/14 19:53:20 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec4 init_vec4(void)
{
	t_vec4	vec;

	vec.x = 0;
	vec.y = 0;
	vec.z = 0;
	vec.w = 0;
	return (vec);
}

int	get_pos(char *str, t_vec4 *pos)
{
	char **args;
	if (!ft_accept_chars(str, "0123456789-.,"))
	{
		perror("The coordinates must not include other characters than numbers, '-', '.' or ','\n");
		return (0);
	}
	args = ft_split(str, ',');
	if (!args || !args[0] || !args[1] || !args[2] || args[3])
	{
		perror("The coordinates have the wrong amount of arguments\n");
		ft_free_sptr(args);
		return (0);
	}
	pos->x = atof(args[0]);
	pos->y = atof(args[1]);
	pos->z = atof(args[2]);
	pos->w = 1.0;
	ft_free_sptr(args);
	return (1);
}

//TODO create an ITOF function and replace current atof
//TODO check for overflow in floats
