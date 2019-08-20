/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 19:06:49 by almoraru          #+#    #+#             */
/*   Updated: 2019/08/19 16:16:44 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_important_distant_light(t_utils *u, t_lights *light, int i)
{
	if (ft_strcmp(u->word, "d") == 0)
	{
		if (check_for_number(u->str))
			handle_4vec_number(u, &light[i].d, u->str);
	}
}

void	parse_distant_light(t_utils *u)
{
	t_lights	*light;
	int		i;
	//TODO: put these string compares in a separate function
	//and add a counter to make sure only one is present
	light = u->light;
	i = u->light_index;
	light[i].type = RT_LIGHT_TYPE_DISTANT;
	light[i].number = i;
	while (*u->buf != '}')
	{
		ft_strnlinecpy(u->str, u->buf);
		ft_cpy_word(u->word, u->str);
		check_important_distant_light(u, light, i);
		// The ones above are NECESARY, if none found = error
		check_optional_light_properties(u, &light[i].att);
		while (ft_isalnum(*u->buf) || is_skippable_char(*u->buf))
			u->buf++;
		if (*u->buf == '\n')
			u->buf++;
	}
}

void	check_important_spherical_light(t_utils *u, t_lights *light, int i)
{
	if (ft_strcmp(u->word, "origin") == 0)
	{
		if (check_for_number(u->str))
			handle_4vec_number(u, &light[i].origin, u->str);
	}
}

void	parse_spherical_light(t_utils *u)
{
	t_lights	*light;
	int		i;
	//TODO: put these string compares in a separate function
	//and add a counter to make sure only one is present
	light = u->light;
	i = u->light_index;
	light[i].type = RT_LIGHT_TYPE_SPHERICAL;
	light[i].number = i;
	while (*u->buf != '}')
	{
		ft_strnlinecpy(u->str, u->buf);
		ft_cpy_word(u->word, u->str);
		check_important_spherical_light(u, light, i);
		// The ones above are NECESARY, if none found = error
		check_optional_light_properties(u, &light[i].att);
		while (ft_isalnum(*u->buf) || is_skippable_char(*u->buf))
			u->buf++;
		if (*u->buf == '\n')
			u->buf++;
	}
}
