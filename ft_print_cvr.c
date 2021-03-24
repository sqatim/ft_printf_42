/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cvr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 17:57:45 by sqatim            #+#    #+#             */
/*   Updated: 2019/12/29 21:31:11 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_print(int res, t_list *data)
{
	if (res == 2 && (data->i == 0 && data->p == 0)\
		&& ft_strchr("di*", data->cvrs))
	{
		if (!(data->w == 0 && data->p == 0 && data->i == 0))
			ft_putchar(' ', data);
	}
	else if (res == 2 && (data->u == 0 && data->p == 0))
	{
		if (!(data->w == 0 && data->p == 0 && data->u == 0))
			ft_putchar(' ', data);
	}
	else if (res == 2 && (data->x == 0 && data->p == 0))
	{
		if (!(data->w == 0 && data->p == 0 && data->x == 0))
			ft_putchar(' ', data);
	}
	else if (data->cvrs == 's' && res == 2 && data->p < data->len)
		ft_ext_putstr(data);
	else
		ft_print_cvr(data);
}

void	ft_print_cvr(t_list *data)
{
	if (data->cvrs == 'c')
		ft_putchar(data->c, data);
	else if (data->cvrs == 's')
	{
		ft_putstr(data->str, data);
	}
	else if (data->cvrs == 'd' || data->cvrs == 'i' || data->cvrs == '*')
		ft_putnbr(data->i, data);
	else if (data->cvrs == 'u')
		ft_putunsigned(data->u, data);
	else if (data->cvrs == 'x' || data->cvrs == 'X')
	{
		if (data->cvrs == 'X')
			ft_printhexa(data->x, 1, data);
		else if (data->cvrs == 'x')
			ft_printhexa(data->x, 0, data);
	}
	else if (data->cvrs == 'p')
		ft_printadd(data->ptr, data);
}
