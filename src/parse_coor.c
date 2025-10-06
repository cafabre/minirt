/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_coor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:55:44 by syukna            #+#    #+#             */
/*   Updated: 2025/10/06 16:11:28 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_coor(char *str, t_coor *coor)
{
	char **args;
	if (!ft_accept_chars(str, "0123456789-.,"))
	{
		perror("The coordinates must not include other characters than numbers, '-', '.' or ','\n");
		return (EXIT_FAILURE);
	}
	args = ft_split(str, ',');
	if (!args || !args[0] || !args[1] || !args[2] || args[3])
	{
		perror("The coordinates have the wrong amount of arguments\n");
		ft_free_sptr(args);
		return (EXIT_FAILURE);
	}
	coor->x = atof(args[0]);
	coor->y = atof(args[1]);
	coor->z = atof(args[2]);
	ft_free_sptr(args);
	return (EXIT_SUCCESS);
}

//TODO create an ITOF function and replace current atof
//TODO check for overflow in floats
