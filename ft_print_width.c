/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 05:31:21 by sqatim            #+#    #+#             */
/*   Updated: 2019/12/29 21:35:16 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_nbr(int size, char *str, t_list *data)
{
	if (data->w > data->len)
	{
		if (*str == '0')
		{
			if (data->i < 0)
				ft_topos(data);
			ft_zero(size, data);
			data->j++;
		}
		else
		{
			ft_space(size, data);
		}
	}
	ft_check_print(1, data);
}

void	ft_width_al(char *str, int size, t_list *data)
{
	if (ft_strchr("cs", data->cvrs))
	{
		if (data->w > data->len)
		{
			if (*str == '0')
				ft_zero(size, data);
			else
				ft_space(size, data);
		}
	}
	ft_print_cvr(data);
}

void	ft_width_ptr(char *str, t_list *data)
{
	if (data->ptr == 0)
		data->len++;
	if (data->w > data->len)
	{
		if (*str == '0' && data->signe != -1)
		{
			ft_putstr("0x", data);
			ft_zero(data->w - data->len, data);
		}
		else
		{
			ft_space(data->w - data->len, data);
			ft_putstr("0x", data);
		}
	}
	else
		ft_putstr("0x", data);
	ft_print_cvr(data);
}

void	ft_print_width(int size, char *str, t_list *data)
{
	if (ft_strchr("di*uxX", data->cvrs))
		ft_width_nbr(size, str, data);
	else if (ft_strchr("cs", data->cvrs))
		ft_width_al(str, size, data);
	else if (ft_strchr("p", data->cvrs))
		ft_width_ptr(str, data);
}
