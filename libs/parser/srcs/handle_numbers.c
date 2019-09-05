/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 17:05:26 by almoraru          #+#    #+#             */
/*   Updated: 2019/09/05 22:12:39 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	handle_int_number(t_utils *u, char *str, int *i)
{
	t_str	*s;

	s = &u->s;
	ft_getnumbers(s->number, str);
	while (*s->number != '\0')
	{
		ft_cpynb(s->sub_nb, s->number);
		if (check_sub(s->sub_nb))
			ft_error_parse(u, str, "This number requires an int, not float!");
		*i = ft_atoi(s->sub_nb);
		while (*s->number != ',' && *s->number != '\0')
			s->number++;
		s->number++;
	}
}

void	handle_theta_number(t_utils *u, char *str, float *f)
{
	t_str	*s;

	s = &u->s;
	ft_getnumbers(s->number, str);
	while (*s->number != '\0')
	{
		ft_cpynb(s->sub_nb, s->number);
		if (check_sub(s->sub_nb))
			*f = M_PI / ft_atof(s->sub_nb);
		else
			*f = M_PI / ft_atoi(s->sub_nb);
		while (*s->number != ',' && *s->number != '\0')
			s->number++;
		s->number++;
	}
}

void	handle_float_number(t_utils *u, char *str, float *f)
{
	t_str	*s;

	s = &u->s;
	ft_getnumbers(s->number, str);
	while (*s->number != '\0')
	{
		ft_cpynb(s->sub_nb, s->number);
		if (check_sub(s->sub_nb))
			*f = ft_atof(s->sub_nb);
		else
			*f = ft_atoi(s->sub_nb);
		while (*s->number != ',' && *s->number != '\0')
			s->number++;
		s->number++;
	}
}

void	handle_4vec_number(t_utils *u, t_vec4 *vec, char *str)
{
	t_str	*s;
	int		i;

	i = 0;
	s = &u->s;
	ft_getnumbers(s->number, str);
	while (*s->number != '\0')
	{
		ft_cpynb(s->sub_nb, s->number);
		if (check_sub(s->sub_nb))
		{
			vec->arr[i] = ft_atof(s->sub_nb);
			i++;
		}
		else
		{
			vec->arr[i] = ft_atoi(s->sub_nb);
			i++;
		}
		while (*s->number != ',' && *s->number != '\0')
			s->number++;
		s->number++;
	}
}
