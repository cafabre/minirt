/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_coor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:55:44 by syukna            #+#    #+#             */
/*   Updated: 2025/10/07 15:37:25 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3 init_vec3(void)
{
	t_vec3	vec;

	vec.x = 0;
	vec.y = 0;
	vec.z = 0;
	return (vec);
}

int	get_coor(char *str, t_vec3 *coor)
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
	coor->x = atof(args[0]);
	coor->y = atof(args[1]);
	coor->z = atof(args[2]);
	ft_free_sptr(args);
	return (1);
}

//TODO create an ITOF function and replace current atof
//TODO check for overflow in floats
