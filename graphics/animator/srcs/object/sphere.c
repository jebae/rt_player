/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:11:22 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 17:11:23 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animator.h"

void		sphere_translate(char *objects_buf, t_mat4 *mat)
{
	t_sphere		*sphere;

	sphere = (t_sphere *)objects_buf;
	sphere->c = mat_mul_vec(mat, &(sphere->c));
}
