/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:12:02 by almoraru          #+#    #+#             */
/*   Updated: 2019/09/05 22:10:39 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include "rt_struct.h"
# include "gmath.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define RT_OBJECT_TYPE_SPHERE		0
# define RT_OBJECT_TYPE_CONE		1
# define RT_OBJECT_TYPE_PLANE		2
# define RT_OBJECT_TYPE_TRIANGLE	3
# define RT_OBJECT_TYPE_CYLINDER	4
# define RT_LIGHT_TYPE_DISTANT		0
# define RT_LIGHT_TYPE_SPHERICAL	1
# define ERROR 42
# define GOOD 0
# define BUFF_SIZE 20480

typedef struct	s_cam
{
	t_vec4	pos;
	t_vec4	focus;
}				t_cam;

typedef struct	s_lights
{
	t_light_commons	att;
	t_vec4			d;
	t_vec4			origin;
	int				type;
	int				number;
}				t_lights;

typedef struct	s_objects
{
	t_object_commons	att;
	t_vec4				c;
	t_vec4				a;
	t_vec4				u;
	t_vec4				v;
	t_vec4				n;
	t_vec4				p;
	t_vec4				color;
	int					type;
	int					number;
	float				r;
	float				theta;
	float				h;
	float				cos_2_theta;
}				t_objects;

typedef struct	s_str
{
	char	*buf;
	char	*str;
	char	*word;
	char	*number;
	char	*sub_nb;
}				t_str;

typedef struct	s_num
{
	int		obj;
	int		cam;
	int		line;
	int		color;
	int		location;
	int		intensity;
	int		focus;
	int		specular_alpha;
	int		reflectivity;
	int		transparency;
	int		ior;
	int		r;
	int		c;
	int		h;
	int		v;
	int		n;
	int		p;
	int		theta;
	int		d;
	int		origin;
	int		bracket_o;
	int		bracket_c;
}				t_num;

typedef struct	s_index
{
	int		object;
	int		light;
}				t_index;

typedef struct	s_togs
{
	int		important;
	int		optional;
}				t_togs;

typedef struct	s_utils
{
	t_objects	ob[20];
	t_lights	light[5];
	t_cam		cam;
	t_str		s;
	t_num		nb;
	t_index		i;
	t_togs		t;
	int			scene;
}				t_utils;

/*
** PARSE FUNCTIONS
*/
int				check_objects(t_utils *u, char *str);
int				check_lights(t_utils *u, char *str);
void			check_line(t_utils *u, char *str);
void			parse(t_utils *u, char *av);
void			parse_through_file(t_utils *u, char *str);
void			parse_camera(t_utils *u, char *str);
void			parse_sphere(t_utils *u, char *str);
void			parse_cylinder(t_utils *u, char *str);
void			parse_plane(t_utils *u, char *str);
void			parse_cone(t_utils *u, char *str);
void			parse_distant_light(t_utils *u, char *str);
void			parse_spherical_light(t_utils *u, char *str);
void			check_optional_properties(t_utils *u
										, t_object_commons *att, char *str);
void			check_optional_light_properties(t_utils *u
										, t_light_commons *att, char *str);
void			check_for_duplicates(t_utils *u, char *str, int nb);
void			check_for_duplicates_optional(t_utils *u, char *str, int nb);
void			check_and_change_attribute(t_utils *u
										, t_object_commons *att);

/*
** INIT FUNCTIONS
*/
int				init_parse(t_utils *u);

/*
** BASIC CHECKS
*/
int				pre_check(char *buf);
int				check_basics(t_utils *u);
int				check_brackets(t_utils *u, int i);
int				check_dot_comma(char *buf, int i);

/*
** STRING FUNCTIONS
*/
int				ft_str_new_line_len(char *str);
char			*ft_cpy_word(char *dest, char *src);
char			*ft_getnumbers(char *number, char *str);
char			*ft_strnlinecpy(char *dest, char *src);
char			*ft_cpynb(char *dest, char *src);

/*
** NUMBER FUNCTIONS
*/
void			handle_4vec_number(t_utils *u, t_vec4 *vec, char *str);
void			handle_float_number(t_utils *u, char *str, float *f);
void			handle_theta_number(t_utils *u, char *str, float *f);
void			handle_int_number(t_utils *u, char *str, int *i);
void			check_color_number(t_utils *u, t_vec4 *vec, char *str);
void			check_ior_number(t_utils *u, char *str, float *f);
void			check_float_number(t_utils *u, char *str, float *f);
void			check_intensity_number(t_utils *u, t_vec4 *vec, char *str);

/*
** UTIL FUNCTIONS
*/
int				check_for_number(char *str);
int				check_sub(char *sub);
int				check_important(t_utils *u, char *str);
int				is_space_or_comma(char c);
int				ft_is_proper(char c);
int				is_skippable_char(char c);
void			increase_object_index(t_utils *u, char *str);
void			run_basic_checks(t_utils *u, char *str, int size);
void			check_number_of_all_cam(t_utils *u, char *str);
void			check_number_of_all_sphere(t_utils *u, char *str);
void			check_number_of_all_cylinder(t_utils *u, char *str);
void			check_number_of_all_plane(t_utils *u, char *str);
void			check_number_of_all_cone(t_utils *u, char *str);
void			check_number_of_directional_light(t_utils *u, char *str);
void			check_number_of_spherical_light(t_utils *u, char *str);
void			check_and_increase_object_index(t_utils *u, char *str);
void			check_and_increase_light_index(t_utils *u, char *str);
void			free_strings(t_utils *u, char *str);

/*
** ERROR FUNCTIONS
*/
void			ft_error(char *error);
void			ft_error_parse(t_utils *u, char *str, char *error);

#endif
