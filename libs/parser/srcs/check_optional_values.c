/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_optional_values.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:43:27 by almoraru          #+#    #+#             */
/*   Updated: 2019/09/07 18:18:29 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_and_change_light(t_utils *u, t_light_commons *att)
{
	t_num	*nb;
	int		i;

	i = -1;
	nb = &u->nb;
	if (nb->intensity == 0)
	{
		ft_putendl("No light intensity found, going with default!");
		while (++i < 4)
			att->intensity.arr[i] = 1.0f;
	}
}

void	check_and_change_attribute(t_utils *u, t_object_commons *att)
{
	t_num	*nb;

	nb = &u->nb;
	if (nb->reflectivity == 0)
	{
		ft_putendl("No reflectivity found, going with default!");
		att->reflectivity = 0.2f;
	}
	if (nb->transparency == 0)
	{
		ft_putendl("No transparency found, going with default!");
		att->transparency = 0.2f;
	}
	if (nb->specular_alpha == 0)
	{
		ft_putendl("No specular alpha found, going with default!");
		att->specular_alpha = 50;
	}
	if (nb->ior == 0)
	{
		ft_putendl("No ior found, going with default!");
		att->ior = 1.5f;
	}
}
