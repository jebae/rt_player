/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_func.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:06:55 by jebae             #+#    #+#             */
/*   Updated: 2019/08/19 16:11:09 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_FUNC_H
# define RT_FUNC_H

# include "gmath.h"
# include "rt_struct.h"
# include "rt_args.h"
# include "parse.h"

typedef enum				e_rgb_shades_idx
{
	AMBIENT,
	DIFFUSE,
	SPECULAR,
	REFLECT,
	REFRACT,
}							t_rgb_shades_idx;

/*
** ray
*/
t_ray_grid_properties		get_ray_grid_properties(
	t_camera *cam,
	float width,
	float height,
	float aov
);
void						set_ray(
	t_ray_grid_properties *props,
	t_ray *ray,
	int scalar_x,
	int scalar_y
);
t_vec4						hit_point(t_ray *ray, float t);

/*
** light
*/
size_t						new_distant_light(t_lights *light, char *lights_buf);

size_t						new_spherical_light(t_lights *light, char *lights_buf);

/*
** object
*/
size_t						get_object_stride(char *objects_buf);

char						*select_object(char *objects_buf, int index);

void						write_mem_buf(
	char *buf,
	char *content,
	size_t size,
	int type
);

size_t						new_sphere(t_objects *object, char *objects_buf);

size_t						new_cone(t_objects *object, char *objects_buf);

size_t						new_plane(t_objects *object, char *objects_buf);

size_t						new_cylinder(t_objects *object, char *objects_buf);

size_t						new_triangle(t_objects *object, char *objects_buf);

/*
** utils
*/
void						exit_with_memalloc_err(const char *msg);

void						clear_global_settings(t_global_settings *settings);

#endif