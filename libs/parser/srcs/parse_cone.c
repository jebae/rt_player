/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 17:01:34 by almoraru          #+#    #+#             */
/*   Updated: 2019/09/05 22:07:07 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_color_cone(t_utils *u, t_objects *ob, char *str, int i)
{
	t_str	*s;
	t_num	*nb;

	s = &u->s;
	nb = &u->nb;
	if (ft_strcmp(s->word, "color") == 0)
	{
		nb->color++;
		if (check_for_number(s->str))
			handle_4vec_number(u, &ob[i].color, s->str);
		check_for_duplicates(u, str, nb->color);
		check_color_number(u, &ob[i].color, str);
	}
}

void	check_important_cone2(t_utils *u, t_objects *ob, char *str, int i)
{
	t_str	*s;
	t_num	*nb;

	s = &u->s;
	nb = &u->nb;
	if (ft_strcmp(s->word, "h") == 0)
	{
		nb->h++;
		if (check_for_number(s->str))
			handle_float_number(u, s->str, &ob[i].h);
		check_for_duplicates(u, str, nb->h);
		check_float_number(u, str, &ob[i].h);
	}
	if (ft_strcmp(s->word, "theta") == 0)
	{
		nb->theta++;
		if (check_for_number(s->str))
			handle_theta_number(u, s->str, &ob[i].theta);
		check_for_duplicates(u, str, nb->theta);
		check_float_number(u, str, &ob[i].theta);
	}
}

void	check_important_cone(t_utils *u, t_objects *ob, char *str, int i)
{
	t_str	*s;
	t_num	*nb;

	s = &u->s;
	nb = &u->nb;
	if (ft_strcmp(s->word, "c") == 0)
	{
		nb->c++;
		if (check_for_number(s->str))
			handle_4vec_number(u, &ob[i].c, s->str);
		check_for_duplicates(u, str, nb->c);
	}
	if (ft_strcmp(s->word, "v") == 0)
	{
		nb->v++;
		if (check_for_number(s->str))
			handle_4vec_number(u, &ob[i].v, s->str);
		check_for_duplicates(u, str, nb->v);
	}
	check_color_cone(u, ob, str, i);
	check_important_cone2(u, ob, str, i);
}

void	parse_cone(t_utils *u, char *str)
{
	t_objects	*ob;
	t_str		*s;
	t_index		*index;
	int			i;

	ob = u->ob;
	s = &u->s;
	index = &u->i;
	i = index->object;
	ob[i].type = RT_OBJECT_TYPE_CONE;
	ob[i].number = i;
	while (*s->buf != '\0' && *s->buf != '}')
	{
		ft_strnlinecpy(s->str, s->buf);
		ft_cpy_word(s->word, s->str);
		check_important_cone(u, ob, str, i);
		check_optional_properties(u, &ob[i].att, str);
		while (ft_isalnum(*s->buf) || is_skippable_char(*s->buf))
			s->buf++;
		if (*s->buf == '\n')
			s->buf++;
	}
	check_and_change_attribute(u, &ob[i].att);
	check_number_of_all_cone(u, str);
}
