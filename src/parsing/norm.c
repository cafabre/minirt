/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandykds <sandykds@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:42:28 by syukna            #+#    #+#             */
/*   Updated: 2025/10/14 12:12:03 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int get_norm(char *str, t_vec4 *vector)
{
	char **args;

	if (!ft_accept_chars(str, ",-01"))
	{
		perror("The normalized orientation vector must remain in the [-1,1] range, example = '0,1,1'.\n");
		return (0);
	}
	args = ft_split(str, ',');
	if (!args || !args[0] || !args[1] || !args[2] || args[3])
	{
		perror("The normalized orientation vector have the wrong amount of arguments\n");
		ft_free_sptr(args);
		return (0);
	}
	vector->x = atof(args[0]);
	vector->y = atof(args[1]);
	vector->z = atof(args[2]);
	ft_free_sptr(args);
	return (1);
}

// TODO if 0,0,0 invalid
