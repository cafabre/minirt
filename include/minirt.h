/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:48:45 by rshin             #+#    #+#             */
/*   Updated: 2025/10/15 15:44:59 by rshin            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H

# define MINIRT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <math.h>

# include "structures.h"
# include "functions.h"
# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include "vec4.h"

# define WIN_W 1600
# define WIN_H 900
# define CX (WIN_W * 0.5f)
# define CY (WIN_H * 0.5f)
# define ESC_KEY 65307

#endif
