/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 18:41:27 by sqatim            #+#    #+#             */
/*   Updated: 2019/12/30 22:04:45 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count_alpha(t_list *data)
{
	if (data->cvrs == 'c')
	{
		return (1);
	}
	else
		return (ft_strlen(data->str));
}

int		ft_count_digit(t_list *data)
{
	if (data->cvrs == 'd' || data->cvrs == 'i' || data->cvrs == '*')
		return (count_int(data->i));
	else
		return (count_unsigned(data->u));
}

int		ft_count_alnum(t_list *data)
{
	if (data->cvrs == 'x' || data->cvrs == 'X')
		return (ft_count_hexa(data->x));
	else
		return (ft_count_add(data->ptr));
}

int		ft_cvrs_count(t_list *data)
{
	if (data->cvrs == '%' || data->cvrs == 'c' || data->cvrs == 's')
		return (ft_count_alpha(data));
	else if (data->cvrs == 'd' || data->cvrs == 'i' ||\
			data->cvrs == '*' || data->cvrs == 'u')
		return (ft_count_digit(data));
	else if (data->cvrs == 'x' || data->cvrs == 'X' || data->cvrs == 'p')
		return (ft_count_alnum(data));
	return (1);
}
