/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 05:13:41 by sqatim            #+#    #+#             */
/*   Updated: 2019/12/31 00:14:03 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_list data;

	data.j = 0;
	data.count = 0;
	va_start(data.ap, format);
	while (format[data.j])
	{
		if (format[data.j] != '%')
		{
			ft_putchar(format[data.j], &data);
		}
		else if (format[data.j] == '%')
		{
			data.j++;
			ft_flags((char *)format, &data);
		}
		data.j++;
	}
	va_end(data.ap);
	return (data.count);
}
