/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 19:50:07 by almoraru          #+#    #+#             */
/*   Updated: 2019/08/20 18:32:58 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_important_sphere(t_utils *u, t_objects *ob, int i)
{
	if (ft_strcmp(u->word, "r") == 0)
	{
		if (check_for_number(u->str))
			handle_float_number(u, &ob[i].r, u->str);
	}
	if (ft_strcmp(u->word, "c") == 0)
	{
		if (check_for_number(u->str))
			handle_4vec_number(u, &ob[i].c, u->str);
	}
	if (ft_strcmp(u->word, "color") == 0)
	{
		if (check_for_number(u->str))
			handle_4vec_number(u, &ob[i].color, u->str);
	}
}

void	parse_sphere(t_utils *u)
{
	t_objects	*ob;
	int		i;
	//TODO: put these string compares in a separate function
	//and add a counter to make sure only one is present
	ob = u->ob;
	i = u->index;
	ob[i].type = RT_OBJECT_TYPE_SPHERE;
	ob[i].number = i;
	while (*u->buf != '}')
	{
		ft_strnlinecpy(u->str, u->buf);
		ft_cpy_word(u->word, u->str);
		printf("what was here ? %s\n", u->word);
		check_important_sphere(u, ob, i);
		// The ones above are NECESARY, if none found = error
		check_optional_properties(u, &ob[i].att);
		while (ft_isalnum(*u->buf) || is_skippable_char(*u->buf))
			u->buf++;
		if (*u->buf == '\n')
			u->buf++;
	}
}
