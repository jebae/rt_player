/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 18:00:10 by almoraru          #+#    #+#             */
/*   Updated: 2019/08/30 14:52:11 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		pre_check(char *buf)
{
	if (!(ft_isalpha(*buf)))
		return (ERROR);
	if (!(ft_strstr(buf, "scene")))
		return (ERROR);
	if (!(ft_strstr(buf, "camera")))
		return (ERROR);
	if (!(ft_strstr(buf, "location")))
		return (ERROR);
	if (!(ft_strstr(buf, "focus")))
		return (ERROR);
	return (GOOD);
}

int		check_brackets(t_utils *u, int i)
{
	t_str	*s;
	t_num	*nb;

	s = &u->s;
	nb = &u->nb;
	if (s->buf[i] == '{')
	{
		++nb->bracket_o;
		i++;
		if (s->buf[i] != '\n')
			return (-1);
	}
	if (s->buf[i] == '}')
	{
		++nb->bracket_c;
		i++;
		if (s->buf[i] != '\n')
			return (-1);
	}
	return (i);
}

int		check_basics(t_utils *u)
{
	t_str	*s;
	int		i;

	i = -1;
	s = &u->s;
	while (s->buf[++i] != '\0')
	{
		i = check_brackets(u, i);
		if (i == -1)
			return (ERROR);
		if (s->buf[i] == ';' && s->buf[i] != '\0')
			i = check_dot_comma(s->buf, i);
		if (i == -1)
			return (ERROR);
	}
	return (GOOD);
}

int		check_dot_comma(char *buf, int i)
{
	if (!(ft_isalnum(buf[i - 1])))
		return (-1);
	if (buf[i + 1] != '\n')
		return (-1);
	return (i);
}
