/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:36:43 by almoraru          #+#    #+#             */
/*   Updated: 2019/09/07 16:34:41 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_intensity_number(t_utils *u, t_vec4 *vec, char *str)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (vec->arr[i] < 0)
			ft_error_parse(u, str, "Value has to be positive!");
	}
}

void	check_color_number(t_utils *u, t_vec4 *vec, char *str)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (vec->arr[i] < 0 || vec->arr[i] > 1.0f)
			ft_error_parse(u, str, "Color has to be between 0.0 and 1.0");
	}
}

void	check_ior_number(t_utils *u, char *str, float *f)
{
	if (*f > 2.65f || *f < 1.0f)
		ft_error_parse(u, str, "Ior has to be between 1.0 and 2.65!");
}

void	check_float_number(t_utils *u, char *str, float *f)
{
	if (*f < 0.0f || *f > 1.0f)
		ft_error_parse(u, str, "Option has to be between 0.0 and 1.0!");
}

void	check_positive_float_number(t_utils *u, char *str, float *f)
{
	if (*f <= 0.0f)
		ft_error_parse(u, str, "Option has to be more than zero!");
}
