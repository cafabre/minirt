/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:23:45 by syukna            #+#    #+#             */
/*   Updated: 2025/10/01 17:17:40 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void replace_char(char **str, char old, char new)
{
	int i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == old)
			(*str)[i] = new;
		i++;
	}
}

int	ft_accept_char(char *ref, char letter)
{
	int i;

	i = 0;
	while (ref[i])
	{
		if (ref[i] == letter)
			return (1);
		i++;
	}
	return (0);
}

// If there are letters outside of the reference, the function returns 0. Otherwise, the function returns 1.
int	ft_accept_chars(char *str, char *ref)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_accept_char(ref, str[i]))
			return (0);
		i++;
	}
	return (1);
}
