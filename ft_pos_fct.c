/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_fct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 22:37:44 by sqatim            #+#    #+#             */
/*   Updated: 2019/12/30 23:23:04 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_topos(t_list *data)
{
	data->i *= -1;
	ft_putchar('-', data);
}

void	ft_psrmpl_str(char *str, t_list *data)
{
	if (data->p == 0 && data->cvrs == 's' && *data->str == '%')
		*str == '0' ? ft_zero(data->w - data->len, data) :\
		ft_space(data->w - data->len, data);
	else if (data->p == 0 && data->cvrs == 's' && *data->str != '%')
		*str == '0' ? ft_zero(data->w, data) : ft_space(data->w, data);
	else if (data->w > data->p)
	{
		{
			if (*str == '0')
				data->p < data->len ? ft_zero(data->w - data->p, data) :\
					ft_zero(data->w - data->len, data);
			else
				data->p < data->len ? ft_space(data->w - data->p, data) :\
					ft_space(data->w - data->len, data);
		}
	}
	else if (data->w <= data->p && data->cvrs == 's')
		(*str == '0' && data->signe != -1) ? ft_zero(data->w - data->len, data)\
		: ft_space(data->w - data->len, data);
	(data->cvrs == 's' && data->p < data->len) ?\
		ft_check_print(2, data) : ft_print_cvr(data);
}

void	ft_psrmpl_crt(char *str, t_list *data)
{
	if (data->p == 0 && data->cvrs == 'c')
		ft_space(data->w - data->len, data);
	else if (data->w > data->p)
	{
		{
			if (data->cvrs == 'c')
				ft_space(data->w - data->len, data);
		}
	}
	else if (data->w <= data->p && data->cvrs == 'c')
		(*str == '0' && data->signe != -1) ? ft_zero(data->w - data->len, data)\
		: ft_space(data->w - data->len, data);
}

void	ft_psrmpl_nbr(int cmp, t_list *data)
{
	if (data->w >= cmp)
	{
		ft_space(data->w - cmp, data);
		if (data->i < 0)
			ft_topos(data);
		if (data->p > data->len)
			ft_zero(data->p - data->len, data);
	}
	else if (data->w < cmp && data->p > data->len)
	{
		if (data->i < 0)
			ft_topos(data);
		ft_zero(data->p - data->len, data);
	}
	ft_check_print(2, data);
}

void	ft_psrmpl_ptr(t_list *data)
{
	if (data->p > 0 && data->p > data->len - 2)
		data->len -= 2;
	if (data->p > data->len)
	{
		if (data->w >= (data->p + 2))
			ft_space(data->w - (data->p + 2), data);
	}
	else
	{
		if (data->w >= data->len)
			ft_space(data->w - (data->len), data);
	}
	ft_putstr("0x", data);
	if (data->p > data->len)
		ft_zero(data->p - data->len, data);
	if (data->ptr > 0)
		ft_print_cvr(data);
}
