/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 00:28:21 by sqatim            #+#    #+#             */
/*   Updated: 2019/12/30 16:11:43 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			cnt_to_cvr(char *str)
{
	int i;

	i = 0;
	while (str[i] == '*' || ft_isdigit(str[i]) == 1 ||\
			str[i] == '-' || str[i] == '.')
		i++;
	return (i);
}

static void	ft_else(t_list *data)
{
	if (data->cvrs == 'u')
		data->u = va_arg(data->ap, unsigned int);
	else if (data->cvrs == 'x' || data->cvrs == 'X')
		data->x = va_arg(data->ap, unsigned int);
	else if (data->cvrs == 'p')
		data->ptr = va_arg(data->ap, unsigned long long);
	else
	{
		data->c = data->cvrs;
		data->cvrs = 'c';
	}
}

void		ft_check(t_list *data)
{
	if (data->cvrs == '%')
	{
		data->cvrs = 's';
		data->str = "%";
	}
	else if (data->cvrs == 'c')
		data->c = va_arg(data->ap, int);
	else if (data->cvrs == 's')
	{
		data->str = va_arg(data->ap, char *);
		if (data->str == NULL)
			data->str = "(null)";
	}
	else if (data->cvrs == 'd' || data->cvrs == 'i' || data->cvrs == '*')
		data->i = va_arg(data->ap, int);
	else
		ft_else(data);
}
