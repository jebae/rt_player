/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 21:40:45 by almoraru          #+#    #+#             */
/*   Updated: 2019/08/31 15:07:40 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_color_plane(t_utils *u, t_objects *ob, char *str, int i)
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
	}
}

void	check_important_plane(t_utils *u, t_objects *ob, char *str, int i)
{
	t_num	*nb;
	t_str	*s;

	nb = &u->nb;
	s = &u->s;
	if (ft_strcmp(s->word, "n") == 0)
	{
		nb->n++;
		if (check_for_number(s->str))
			handle_4vec_number(u, &ob[i].n, s->str);
		check_for_duplicates(u, str, nb->n);
	}
	if (ft_strcmp(s->word, "p") == 0)
	{
		nb->p++;
		if (check_for_number(s->str))
			handle_4vec_number(u, &ob[i].p, s->str);
		check_for_duplicates(u, str, nb->p);
	}
	check_color_plane(u, ob, str, i);
}

void	parse_plane(t_utils *u, char *str)
{
	t_objects	*ob;
	t_str		*s;
	t_index		*index;
	int			i;

	ob = u->ob;
	s = &u->s;
	index = &u->i;
	i = index->object;
	ob[i].type = RT_OBJECT_TYPE_PLANE;
	ob[i].number = i;
	while (*s->buf != '\0' && *s->buf != '}')
	{
		ft_strnlinecpy(s->str, s->buf);
		ft_cpy_word(s->word, s->str);
		check_important_plane(u, ob, str, i);
		check_optional_properties(u, &ob[i].att, str);
		while (ft_isalnum(*s->buf) || is_skippable_char(*s->buf))
			s->buf++;
		if (*s->buf == '\n')
			s->buf++;
	}
	check_number_of_all_plane(u, str);
}
