/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 21:13:45 by almoraru          #+#    #+#             */
/*   Updated: 2019/08/20 18:33:21 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_important_cylinder(t_utils *u, t_objects *ob, int i)
{
	if (ft_strcmp(u->word, "r") == 0)
	{
		if (check_for_number(u->str))
			handle_float_number(u, &ob[i].r, u->str);
	}
	if (ft_strcmp(u->word, "h") == 0)
	{
		if (check_for_number(u->str))
			handle_float_number(u, &ob[i].h, u->str);
	}
	if (ft_strcmp(u->word, "c") == 0)
	{
		if (check_for_number(u->str))
			handle_4vec_number(u, &ob[i].c, u->str);
	}
	if (ft_strcmp(u->word, "v") == 0)
	{
		if (check_for_number(u->str))
			handle_4vec_number(u, &ob[i].v, u->str);
	}
	if (ft_strcmp(u->word, "color") == 0)
	{
		if (check_for_number(u->str))
			handle_4vec_number(u, &ob[i].color, u->str);
	}
}

void	parse_cylinder(t_utils *u)
{
	t_objects	*ob;
	int		i;
	//TODO: put these string compares in a separate function
	//and add a counter to make sure only one is present
	ob = u->ob;
	i = u->index;
	ob[i].type = RT_OBJECT_TYPE_CYLINDER;
	ob[i].number = i;
	while (*u->buf != '\0' && *u->buf != '}')
	{
		ft_strnlinecpy(u->str, u->buf);
		ft_cpy_word(u->word, u->str);
		check_important_cylinder(u, ob, i);
		// The ones above are NECESARY, if none found = error
		check_optional_properties(u, &ob[i].att);
		while (ft_isalnum(*u->buf) || is_skippable_char(*u->buf))
			u->buf++;
		if (*u->buf == '\n')
			u->buf++;
	}
}
