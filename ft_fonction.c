/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 17:19:07 by sqatim            #+#    #+#             */
/*   Updated: 2019/12/29 21:38:54 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_list *data)
{
	data->count++;
	write(1, &c, 1);
}

void	ft_putstr(char *c, t_list *data)
{
	int i;

	i = 0;
	while (c[i])
	{
		ft_putchar(c[i], data);
		i++;
	}
}

int		comparaison(t_list *data)
{
	if (data->i < 0 && ft_strchr("id", data->cvrs))
		data->p++;
	if (data->p > data->len && data->len > 0)
		return (data->p);
	else if (data->p < data->len)
		return (data->len);
	else
		return (data->len);
}

void	ft_zero(int k, t_list *data)
{
	int i;

	i = 0;
	while (i < k)
	{
		ft_putchar('0', data);
		i++;
	}
}

void	ft_space(int k, t_list *data)
{
	int i;

	i = 0;
	while (i < k)
	{
		ft_putchar(' ', data);
		i++;
	}
}
