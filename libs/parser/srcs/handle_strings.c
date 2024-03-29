/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_strings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 17:44:41 by almoraru          #+#    #+#             */
/*   Updated: 2019/09/09 17:00:32 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		ft_str_new_line_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		++i;
	return (i);
}

char	*ft_getnumbers(char *number, char *str)
{
	if (number != NULL)
		ft_bzero(number, ft_strlen(number));
	while (*str != '\0' && *str != '\n')
	{
		if (ft_is_proper(*str) || is_skippable_char(*str))
			str++;
		while (ft_isdigit(*str) || *str == ',' || *str == '.'
				|| *str == 'f' || *str == '-')
			*number++ = *str++;
	}
	*number = '\0';
	return (number);
}

char	*ft_cpy_word(char *dest, char *src)
{
	if (dest != NULL)
		ft_bzero(dest, ft_strlen(dest));
	while (*src != '\0' && ft_is_proper(*src))
		*dest++ = *src++;
	*dest = '\0';
	return (dest);
}

char	*ft_cpynb(char *dest, char *src)
{
	if (dest != NULL)
		ft_bzero(dest, ft_strlen(dest));
	while (ft_isalpha(*src))
		src++;
	while (*src != '\0' && *src != ',')
		*dest++ = *src++;
	*dest = '\0';
	return (dest);
}

char	*ft_strnlinecpy(char *dest, char *src)
{
	if (dest != NULL)
		ft_bzero(dest, ft_strlen(dest));
	while (*src != '\0' && *src != '\n'
			&& (ft_isalnum(*src) || ft_iswhitespace(*src)
				|| is_skippable_char(*src)))
	{
		while (ft_iswhitespace(*src))
			src++;
		*dest++ = *src++;
	}
	*dest = '\0';
	return (dest);
}
