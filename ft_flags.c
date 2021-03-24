/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 04:26:51 by sqatim            #+#    #+#             */
/*   Updated: 2019/12/29 21:36:48 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_just_cvrs(t_list *data)
{
	ft_check(data);
	if (data->cvrs == 'p')
	{
		ft_putstr("0x", data);
	}
	ft_print_cvr(data);
	data->len = ft_cvrs_count(data);
}

void	ft_just_width(int res, char *str, t_list *data)
{
	ft_check(data);
	data->len = ft_cvrs_count(data);
	ft_signe(res, str, data);
	data->j += cnt_to_cvr(&str[data->j]);
}

void	ft_precision(int res, char *str, t_list *data)
{
	ft_check(data);
	data->len = ft_cvrs_count(data);
	ft_signe(res, str, data);
	data->j += cnt_to_cvr(&str[data->j]);
}

void	ft_flags(char *str, t_list *data)
{
	int res;
	int i;

	i = data->j;
	while (str[i] == '*' || ft_isdigit(str[i]) == 1 ||\
			str[i] == '-' || str[i] == '.')
		i++;
	data->cvrs = str[i];
	if (!(ft_strchr(".*-0123456789", str[data->j])))
		ft_just_cvrs(data);
	else
	{
		res = ft_determination(str, data);
		if (res == 1)
			ft_just_width(res, str, data);
		else if (res == 2)
		{
			ft_precision(res, str, data);
		}
	}
}
