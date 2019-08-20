/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 17:01:34 by almoraru          #+#    #+#             */
/*   Updated: 2019/08/19 13:14:00 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_important_cone(t_utils *u, t_objects *ob, int i)
{
	if (ft_strcmp(u->word, "color") == 0)
	{
		if (check_for_number(u->str))
			handle_4vec_number(u, &ob[i].color, u->str);
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
	if (ft_strcmp(u->word, "h") == 0)
	{
		if (check_for_number(u->str))
			handle_float_number(u, ob[i].h, u->str);
	}
	if (ft_strcmp(u->word, "theta") == 0)
	{
		if (check_for_number(u->str))
			handle_theta_number(u, ob[i].theta, u->str);
	}
}

void	parse_cone(t_utils *u)
{
	t_objects	*ob;
	int		i;
	//TODO: put these string compares in a separate function
	//and add a counter to make sure only one is present
	ob = u->ob;
	i = u->index;
	ob[i].type = RT_OBJECT_TYPE_CONE;
	ob[i].number = i;
	while (*u->buf != '}')
	{
		ft_strnlinecpy(u->str, u->buf);
		ft_cpy_word(u->word, u->str);
		printf("what was here ? %s\n", u->word);
		check_important_cone(u, ob, i);
		// The ones above are NECESARY, if none found = error
		check_optional_properties(u, &ob[i].att);
		while (ft_isalnum(*u->buf) || is_skippable_char(*u->buf))
			u->buf++;
		if (*u->buf == '\n')
			u->buf++;
	}
}
