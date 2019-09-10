/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:32:26 by jebae             #+#    #+#             */
/*   Updated: 2019/09/10 17:34:32 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_player.h"

static int		handle_two_bar(
	char *options,
	char *arg,
	int *parallel_mode_decided
)
{
	if (ft_strcmp(arg, "cpu") == 0)
	{
		if (*parallel_mode_decided)
			return (RTP_FAIL);
		*options &= ~RTP_OPTION_PARALLEL_GPU;
		*parallel_mode_decided = RTP_TRUE;
	}
	else if (ft_strcmp(arg, "gpu") == 0)
	{
		if (*parallel_mode_decided)
			return (RTP_FAIL);
		*options |= RTP_OPTION_PARALLEL_GPU;
		*parallel_mode_decided = RTP_TRUE;
	}
	else if (ft_strcmp(arg, "deep-trace") == 0)
		*options |= RTP_OPTION_DEEP_TRACE;
	else
		return (RTP_FAIL);
	return (RTP_SUCCESS);
}

static int		handle_one_bar(
	char *options,
	char *arg,
	int *parallel_mode_decided
)
{
	while (*arg != '\0')
	{
		if (*arg == 'c')
		{
			if (*parallel_mode_decided)
				return (RTP_FAIL);
			*options &= ~RTP_OPTION_PARALLEL_GPU;
			*parallel_mode_decided = RTP_TRUE;
		}
		else if (*arg == 'g')
		{
			if (*parallel_mode_decided)
				return (RTP_FAIL);
			*options |= RTP_OPTION_PARALLEL_GPU;
			*parallel_mode_decided = RTP_TRUE;
		}
		else if (*arg == 'd')
			*options |= RTP_OPTION_DEEP_TRACE;
		else
			return (RTP_FAIL);
		arg++;
	}
	return (RTP_SUCCESS);
}

int				handle_options(char *options, char **args, int num_args)
{
	int		i;
	int		res;
	int		parallel_mode_decided;

	parallel_mode_decided = RTP_FALSE;
	res = RTP_SUCCESS;
	i = 0;
	while (i < num_args)
	{
		if (args[i][0] == '-')
		{
			if (args[i][1] == '-')
				res = handle_two_bar(
					options, &(args[i][2]), &parallel_mode_decided);
			else
				res = handle_one_bar(
					options, &(args[i][1]), &parallel_mode_decided);
		}
		if (res == RTP_FAIL)
			return (RTP_FAIL);
		i++;
	}
	return (RTP_SUCCESS);
}

char			init_options(void)
{
	return (0);
}
