/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:04:29 by cafabre           #+#    #+#             */
/*   Updated: 2026/01/12 16:03:32 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_tabs(char **t1, char **t2, char **t3)
{
	free_tab (t1);
	free_tab (t2);
	free_tab (t3);
}

bool	ret_error(t_data *data, int err)
{
	data->error = err;
	return (false);
}

bool	detail_error(t_data *data, int det)
{
	data->detail = det;
	return (NULL);
}
