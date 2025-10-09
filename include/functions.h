/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syukna <syukna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:31:14 by syukna            #+#    #+#             */
/*   Updated: 2025/10/07 15:37:36 by syukna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

// PARSING
int		parse_scene(int fd, t_scene *scene);
int		get_coor(char *str, t_vec3 *coor);
int		get_color(char *str, t_color *color);
int		get_norm(char *str, t_vec3 *vector);
t_vec3	init_vec3(void);

// PARSING OBJECTS
int		init_ambient(char **args, t_scene *scene);
int		init_light(char **args, t_scene *scene);
int		init_sphere(char **args, t_scene *scene);
int		init_plane(char **args, t_scene *scene);
int		init_cyl(char **args, t_scene *scene);

// PARSING UTILS
int	ft_accept_chars(char *str, char *ref);

// PRINT ALL
void	print_scene(t_scene *scene);

// FREE ALL
void	free_all(t_scene *scene);
void	free_splitted(char **args);

#endif