/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:36:45 by sqatim            #+#    #+#             */
/*   Updated: 2019/12/30 23:21:37 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ext_putstr(t_list *data)
{
	int i;

	i = 0;
	if (*data->str == '%')
		ft_putchar('%', data);
	else
	{
		while (i < data->p && data->str[i])
		{
			ft_putchar(data->str[i], data);
			i++;
		}
	}
}

void	ft_putnbr(int nbr, t_list *data)
{
	long long int	nb;
	int				sign;

	nb = nbr;
	sign = 1;
	if (nb < 0)
	{
		sign = -1;
		nb *= -1;
		ft_putchar('-', data);
	}
	if (nb < 10)
		ft_putchar(nb + '0', data);
	else
	{
		ft_putnbr(nb / 10, data);
		ft_putchar((nb %= 10) + '0', data);
	}
}

void	ft_putunsigned(unsigned int nbr, t_list *data)
{
	if (nbr < 10)
		ft_putchar(nbr + '0', data);
	else if (nbr > 9)
	{
		ft_putunsigned(nbr / 10, data);
		ft_putchar(nbr % 10 + '0', data);
	}
}

void	ft_printhexa(unsigned int nbr, int k, t_list *data)
{
	int i;

	i = 0;
	if (nbr <= 9)
		ft_putchar(nbr + '0', data);
	else
	{
		if ((nbr / 16) > 0)
			ft_printhexa(nbr / 16, k, data);
		if ((nbr % 16) < 10)
			ft_putunsigned(nbr % 16, data);
		else
		{
			i = nbr % 16;
			k = (k == 0) ? 97 : 65;
			i = k + i - 10;
			ft_putchar(i, data);
		}
	}
}

void	ft_printadd(unsigned long long nbr, t_list *data)
{
	int i;

	i = 0;
	if (nbr <= 9)
		ft_putchar(nbr + '0', data);
	else
	{
		if ((nbr / 16) > 0)
			ft_printadd(nbr / 16, data);
		if ((nbr % 16) < 10)
			ft_putnbr(nbr % 16, data);
		else
		{
			i = nbr % 16;
			i = 'a' + i - 10;
			ft_putchar(i, data);
		}
	}
}
