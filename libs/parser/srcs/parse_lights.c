/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 19:06:49 by almoraru          #+#    #+#             */
/*   Updated: 2019/09/07 18:34:11 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_important_distant_light(t_utils *u, t_lights *light
									, char *str, int i)
{
	t_num	*nb;
	t_str	*s;

	nb = &u->nb;
	s = &u->s;
	if (ft_strcmp(s->word, "d") == 0)
	{
		nb->d++;
		if (check_for_number(s->str))
			handle_4vec_number(u, &light[i].d, s->str);
		check_for_duplicates(u, str, nb->d);
	}
}

void	parse_distant_light(t_utils *u, char *str)
{
	t_lights	*light;
	t_str		*s;
	t_index		*index;
	int			i;

	light = u->light;
	s = &u->s;
	index = &u->i;
	i = index->light;
	light[i].type = RT_LIGHT_TYPE_DISTANT;
	light[i].number = i;
	while (*s->buf != '\0' && *s->buf != '}')
	{
		ft_strnlinecpy(s->str, s->buf);
		ft_cpy_word(s->word, s->str);
		check_important_distant_light(u, light, str, i);
		check_optional_light_properties(u, &light[i].att, str);
		while (ft_isalnum(*s->buf) || is_skippable_char(*s->buf))
			s->buf++;
		if (*s->buf == '\n')
			s->buf++;
	}
	check_and_change_light(u, &light[i].att);
	check_number_of_distant_light(u, str);
}

void	check_important_spherical_light(t_utils *u, t_lights *light
									, char *str, int i)
{
	t_str	*s;
	t_num	*nb;

	s = &u->s;
	nb = &u->nb;
	if (ft_strcmp(s->word, "origin") == 0)
	{
		nb->origin++;
		if (check_for_number(s->str))
			handle_4vec_number(u, &light[i].origin, s->str);
		check_for_duplicates(u, str, nb->origin);
	}
}

void	parse_spherical_light(t_utils *u, char *str)
{
	t_lights	*light;
	t_str		*s;
	t_index		*index;
	int			i;

	light = u->light;
	s = &u->s;
	index = &u->i;
	i = index->light;
	light[i].type = RT_LIGHT_TYPE_SPHERICAL;
	light[i].number = i;
	while (*s->buf != '\0' && *s->buf != '}')
	{
		ft_strnlinecpy(s->str, s->buf);
		ft_cpy_word(s->word, s->str);
		check_important_spherical_light(u, light, str, i);
		check_optional_light_properties(u, &light[i].att, str);
		while (ft_isalnum(*s->buf) || is_skippable_char(*s->buf))
			s->buf++;
		if (*s->buf == '\n')
			s->buf++;
	}
	check_and_change_light(u, &light[i].att);
	check_number_of_spherical_light(u, str);
}
