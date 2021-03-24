/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntr_fct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 07:25:27 by sqatim            #+#    #+#             */
/*   Updated: 2019/12/31 00:13:10 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ntrrmpl_num(int cmp, t_list *data)
{
	if (ft_strchr("di*uxX", data->cvrs))
	{
		if (data->i < 0)
			ft_topos(data);
		if (data->p > data->len)
			ft_zero(data->p - data->len, data);
		ft_check_print(2, data);
		if ((-1 * data->w) > cmp)
			ft_space((-1 * data->w) - cmp, data);
	}
}

void	ft_ntrrmpl_crt(t_list *data)
{
	ft_print_cvr(data);
	if ((-1 * data->w) > data->len)
		ft_space((-1 * data->w) - data->len, data);
}

void	ft_ntrrmpl_str(t_list *data)
{
	if (data->p == 0 && *data->str == '%')
	{
		ft_check_print(2, data);
		if ((-1 * data->w) > data->len)
			ft_space((-1 * data->w) - data->len, data);
	}
	else
	{
		if (data->p > 0)
			ft_check_print(2, data);
		if ((-1 * data->w) > data->p && data->p < data->len)
			ft_space((-1 * data->w) - data->p, data);
		else if ((-1 * data->w) > data->len)
			ft_space((-1 * data->w) - data->len, data);
		if (data->p == 0)
			ft_space(data->w, data);
	}
}

void	ft_ntrrmpl_ptr(t_list *data)
{
	int len;

	len = data->len;
	if (data->p > 0)
		len -= 2;
	ft_putstr("0x", data);
	if (data->p > len)
		ft_zero(data->p - len, data);
	if (data->ptr > 0)
		ft_print_cvr(data);
	if ((-1 * data->w) > data->p && data->p >= len)
		ft_space((-1 * data->w) - (data->p + 2), data);
	else if ((-1 * data->w) > data->len && data->p < data->len)
		ft_space((-1 * data->w) - data->len, data);
}
