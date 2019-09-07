/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils_lights.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 15:14:02 by almoraru          #+#    #+#             */
/*   Updated: 2019/09/07 18:13:40 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_number_of_spherical_light(t_utils *u, char *str)
{
	t_num *nb;

	nb = &u->nb;
	if (nb->origin != 1)
		ft_error_parse(u, str, "Wrong spherical light parameters!");
	ft_bzero(nb, sizeof(nb) * 10);
}

void	check_number_of_distant_light(t_utils *u, char *str)
{
	t_num *nb;

	nb = &u->nb;
	if (nb->d != 1)
		ft_error_parse(u, str, "Wrong distant light parameters!");
	ft_bzero(nb, sizeof(nb) * 10);
}
