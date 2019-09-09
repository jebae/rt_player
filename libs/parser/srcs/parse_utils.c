/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 18:02:14 by almoraru          #+#    #+#             */
/*   Updated: 2019/09/09 17:35:28 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		check_sub(char *sub)
{
	while (*sub != '\0')
	{
		if (*sub == '.' || *sub == 'f')
			return (1);
		sub++;
	}
	return (0);
}

int		ft_is_proper(char c)
{
	if (ft_isalpha(c) || c == '_')
		return (1);
	return (0);
}

int		check_for_number(char *str)
{
	while (*str != '\0')
		if (ft_isdigit(*str++))
			return (1);
	return (0);
}

int		is_space_or_comma(char c)
{
	if (c == ' ' || c == ',')
		return (1);
	return (0);
}

int		is_skippable_char(char c)
{
	if (c == '\t' || (c >= ' ' && c < '0')
		|| (c > '9' && c <= '@') || (c > 'Z' && c < 'a')
		|| c == '{' || c == '|' || c == '~')
		return (1);
	return (0);
}
