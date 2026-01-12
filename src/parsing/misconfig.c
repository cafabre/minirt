/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misconfig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafabre <cafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:18:04 by cafabre           #+#    #+#             */
/*   Updated: 2026/01/12 15:37:10 by cafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	display_err_detail(t_err_detail d)
{
	ft_printf(": ");
	if (d == DETAIL_OUT_OF_RANGE)
		ft_printf("at least one value is outside of the allowed range");
	else if (d == DETAIL_NOT_A_NUMBER)
		ft_printf("at least one value is not a number");
	else if (d == DETAIL_BAD_FORMAT)
		ft_printf("coordinates need to be three floats separated by two comas");
}

void	display_error_message(t_data *data)
{
	if (!data || data->error == ERR_NONE)
		return ;
	else
		ft_printf("Error: ");
	if (!display_input_error(data->error))
		return ;
	display_file_error(data->error);
	display_alloc_error(data->error);
	display_data_error(data->error);
	if (data->detail != DETAIL_NONE)
		display_err_detail(data->detail);
	ft_printf("\n");
}
