/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_mat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:25:03 by jebae             #+#    #+#             */
/*   Updated: 2019/05/28 15:25:04 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gmath.h"

t_mat4		translate_mat(float x, float y, float z)
{
	t_mat4	m;

	m = identity_mat();
	m.arr[0][3] = x;
	m.arr[1][3] = y;
	m.arr[2][3] = z;
	return (m);
}