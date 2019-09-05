/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 19:50:07 by almoraru          #+#    #+#             */
/*   Updated: 2019/09/05 22:06:03 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_color_sphere(t_utils *u, t_objects *ob, char *str, int i)
{
	t_num	*nb;
	t_str	*s;

	nb = &u->nb;
	s = &u->s;
	if (ft_strcmp(s->word, "color") == 0)
	{
		nb->color++;
		if (check_for_number(s->str))
			handle_4vec_number(u, &ob[i].color, s->str);
		check_for_duplicates(u, str, nb->color);
		check_color_number(u, &ob[i].color, str);
	}
}

void	check_important_sphere(t_utils *u, t_objects *ob, char *str, int i)
{
	t_num	*nb;
	t_str	*s;

	nb = &u->nb;
	s = &u->s;
	if (ft_strcmp(s->word, "r") == 0)
	{
		nb->r++;
		if (check_for_number(s->str))
			handle_float_number(u, s->str, &ob[i].r);
		check_for_duplicates(u, str, nb->r);
		check_float_number(u, str, &ob[i].r);
	}
	if (ft_strcmp(s->word, "c") == 0)
	{
		nb->c++;
		if (check_for_number(s->str))
			handle_4vec_number(u, &ob[i].c, s->str);
		check_for_duplicates(u, str, nb->c);
	}
	check_color_sphere(u, ob, str, i);
}

void	parse_sphere(t_utils *u, char *str)
{
	t_objects	*ob;
	t_str		*s;
	t_index		*index;
	int			i;

	ob = u->ob;
	s = &u->s;
	index = &u->i;
	i = index->object;
	ob[i].type = RT_OBJECT_TYPE_SPHERE;
	ob[i].number = i;
	while (*s->buf != '\0' && *s->buf != '}')
	{
		ft_strnlinecpy(s->str, s->buf);
		ft_cpy_word(s->word, s->str);
		check_important_sphere(u, ob, str, i);
		check_optional_properties(u, &ob[i].att, str);
		while (ft_isalnum(*s->buf) || is_skippable_char(*s->buf))
			s->buf++;
		if (*s->buf == '\n')
			s->buf++;
	}
	check_and_change_attribute(u, &ob[i].att);
	check_number_of_all_sphere(u, str);
}
