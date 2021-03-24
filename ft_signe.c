/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 01:06:56 by sqatim            #+#    #+#             */
/*   Updated: 2019/12/31 00:05:40 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_rempl_ntr(t_list *data)
{
	int cmp;

	cmp = comparaison(data);
	if (ft_strchr("di*uxX", data->cvrs))
		ft_ntrrmpl_num(cmp, data);
	else if (ft_strchr("s", data->cvrs))
		ft_ntrrmpl_str(data);
	else if (ft_strchr("c", data->cvrs))
		ft_ntrrmpl_crt(data);
	else if (ft_strchr("p", data->cvrs))
	{
		ft_ntrrmpl_ptr(data);
	}
}

void	ft_isnega(t_list *data)
{
	int wpos;

	wpos = -1 * data->w;
	if (data->ptr == 0)
		data->len++;
	if (data->cvrs == 'p')
		ft_putstr("0x", data);
	ft_print_cvr(data);
	if (wpos > data->len)
		ft_space(wpos - data->len, data);
}

void	ft_ispost(char *str, int nbr, t_list *data)
{
	int size;
	int cmp;

	size = data->w - data->len;
	cmp = comparaison(data);
	if (nbr == 1)
	{
		ft_print_width(size, str, data);
	}
	else if (nbr == 2)
	{
		if (ft_strchr("di*uxX", data->cvrs))
			ft_psrmpl_nbr(cmp, data);
		else if (ft_strchr("s", data->cvrs))
			ft_psrmpl_str(str, data);
		else if (ft_strchr("c", data->cvrs))
			ft_psrmpl_crt(str, data);
		else if (ft_strchr("p", data->cvrs))
			ft_psrmpl_ptr(data);
	}
}

void	ft_signe(int nb, char *str, t_list *data)
{
	int i;

	i = data->j;
	if (nb == 1)
	{
		if (data->w >= 0)
			ft_ispost(&str[data->j], nb, data);
		else
			ft_isnega(data);
	}
	else if (nb == 2)
	{
		if (data->w >= 0 && data->p >= 0)
		{
			ft_ispost(&str[data->j], nb, data);
		}
		else if ((data->w < 0 && data->p >= 0))
		{
			ft_rempl_ntr(data);
		}
	}
}
