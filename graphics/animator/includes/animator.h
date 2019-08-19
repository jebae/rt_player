/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:11:39 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 17:11:40 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATOR_H
# define ANIMATOR_H

# include "rt.h"

/*
** object
*/
void		object_translate(char *objects_buf, t_mat4 *mat);

void		object_rotate(char *objects_buf, t_vec4 *n, float theta);

void		sphere_translate(char *objects_buf, t_mat4 *mat);

void		cone_translate(char *objects_buf, t_mat4 *mat);

void		cone_rotate(char *objects_buf, t_vec4 *n, float theta);

void		cylinder_translate(char *objects_buf, t_mat4 *mat);

void		cylinder_rotate(char *objects_buf, t_vec4 *n, float theta);

void		plane_translate(char *objects_buf, t_mat4 *mat);

void		plane_rotate(char *objects_buf, t_vec4 *n, float theta);

void		triangle_translate(char *objects_buf, t_mat4 *mat);

void		triangle_rotate(char *objects_buf, t_vec4 *n, float theta);

void		camera_translate(t_camera *cam, t_mat4 *mat);

/*
** camera
*/
void		camera_translate(t_camera *cam, t_mat4 *mat);

void		rotate_camera_pan(t_camera *cam, float theta);

void		rotate_camera_tilt(t_camera *cam, float theta);

#endif
